/*
* This source file is part of an OSTIS project. For the latest info, see http://ostis.net
* Distributed under the MIT License
* (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
*/

#include <thread>

#include "catch2/catch.hpp"
#include "sc-memory/sc_event.hpp"
#include "sc-memory/sc_timer.hpp"
#include "sc-memory/sc_stream.hpp"
#include "sc-test-framework/sc_test_unit.hpp"
#include "sc-memory/utils/sc_progress.hpp"

extern "C"
{
#include <glib.h>
}

namespace
{
const double kTestTimeout = 5.0;

template<typename EventClassT, typename PrepareF, typename EmitF>
void testEventsFuncT(ScMemoryContext & ctx, ScAddr const & addr, PrepareF prepare, EmitF emit)
{
  prepare();

  volatile bool isDone = false;
  auto const callback = [&isDone](ScAddr const & listenAddr,
                                  ScAddr const & edgeAddr,
                                  ScAddr const & otherAddr)
  {
    isDone = true;
    return true;
  };

  EventClassT evt(ctx, addr, callback);
  ScTimer timer(kTestTimeout);

  emit();

  while (!isDone && !timer.IsTimeOut())
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

  REQUIRE(isDone);
}
}

TEST_CASE("Events common", "[test event]")
{
  test::ScTestUnit::InitMemory("sc-dumper.ini", "");
  ScMemoryContext * ctx = new ScMemoryContext(sc_access_lvl_make_min, "events_common");

  SECTION("ScEventAddInputEdge")
  {
    SUBTEST_START("ScEventAddInputEdge")
    {
      try
      {
        ScAddr addr;
        auto const CreateNode = [&ctx, &addr]()
        {
          addr = ctx->CreateNode(ScType::Unknown);
          REQUIRE(addr.IsValid());
        };

        auto const emitEvent = [&ctx, &addr]()
        {
          ScAddr const addr2 = ctx->CreateNode(ScType::Unknown);
          REQUIRE(addr2.IsValid());

          ScAddr const edge = ctx->CreateEdge(ScType::EdgeAccess, addr2, addr);
          REQUIRE(edge.IsValid());
        };

        testEventsFuncT<ScEventAddInputEdge>(*ctx, addr, CreateNode, emitEvent);
      } catch (...)
      {
        SC_LOG_ERROR("Test \"ScEventAddInputEdge\" failed")
      }
    }
    SUBTEST_END()
  }

  SECTION("ScEventAddOutputEdge")
  {
    SUBTEST_START("ScEventAddOutputEdge")
    {
      try
      {
        ScAddr addr;
        auto const CreateNode = [&ctx, &addr]()
        {
          addr = ctx->CreateNode(ScType::Unknown);
          REQUIRE(addr.IsValid());
        };

        auto const emitEvent = [&ctx, &addr]()
        {
          ScAddr const addr2 = ctx->CreateNode(ScType::Unknown);
          REQUIRE(addr2.IsValid());

          ScAddr const edge = ctx->CreateEdge(ScType::EdgeAccess, addr, addr2);
          REQUIRE(edge.IsValid());
        };

        testEventsFuncT<ScEventAddOutputEdge>(*ctx, addr, CreateNode, emitEvent);
      }
      catch (...)
      {
        SC_LOG_ERROR("Test \"ScEventAddOutputEdge\" failed")
      }
    }
    SUBTEST_END();
  }

  SECTION("ScEventRemoveInputEdge")
  {
    SUBTEST_START("ScEventRemoveInputEdge")
    {
      try
      {
        ScAddr const addr = ctx->CreateNode(ScType::Unknown);
        REQUIRE(addr.IsValid());

        ScAddr const addr2 = ctx->CreateNode(ScType::Unknown);
        REQUIRE(addr2.IsValid());

        ScAddr const edge = ctx->CreateEdge(ScType::EdgeAccess, addr, addr2);
        REQUIRE(edge.IsValid());

        auto const prepare = []()
        {};
        auto const emitEvent = [&ctx, &edge]()
        {
          REQUIRE(ctx->EraseElement(edge));
        };

        testEventsFuncT<ScEventRemoveInputEdge>(*ctx, addr2, prepare, emitEvent);
      } catch (...)
      {
        SC_LOG_ERROR("Test \"ScEventRemoveInputEdge\" failed")
      }
    }
    SUBTEST_END()
  }

  SECTION("ScEventRemoveOutputEdge")
  {
    SUBTEST_START("ScEventRemoveOutputEdge")
    {
      try
      {
        ScAddr const addr = ctx->CreateNode(ScType::Unknown);
        REQUIRE(addr.IsValid());

        ScAddr const addr2 = ctx->CreateNode(ScType::Unknown);
        REQUIRE(addr2.IsValid());

        ScAddr const edge = ctx->CreateEdge(ScType::EdgeAccess, addr, addr2);
        REQUIRE(edge.IsValid());

        auto const prepare = []()
        {};
        auto const emitEvent = [&ctx, &edge]()
        {
          REQUIRE(ctx->EraseElement(edge));
        };

        testEventsFuncT<ScEventRemoveOutputEdge>(*ctx, addr, prepare, emitEvent);
      } catch (...)
      {
        SC_LOG_ERROR("Test \"ScEventRemoveOutputEdge\" failed")
      }
    }
    SUBTEST_END()
  }

  SECTION("ScEventContentChanged")
  {
    SUBTEST_START(ScEventContentChanged)
    {
      try
      {
        ScAddr const addr = ctx->CreateLink();
        REQUIRE(addr.IsValid());

        auto const prepare = []()
        {};
        auto const emitEvent = [&ctx, &addr]()
        {
          std::string const value("test");
          ScStreamPtr stream = ScStreamMakeRead(value);
          REQUIRE(ctx->SetLinkContent(addr, stream));
        };
        testEventsFuncT<ScEventContentChanged>(*ctx, addr, prepare, emitEvent);
      } catch (...)
      {
        SC_LOG_ERROR("Test \"ScEventContentChanged\" failed")
      }
    }
    SUBTEST_END()
  }

  SECTION("ScEventEraseElement")
  {
    SUBTEST_START("ScEventEraseElement")
    {
      try
      {
        ScAddr const addr = ctx->CreateNode(ScType::Unknown);
        REQUIRE(addr.IsValid());

        auto const prepare = []()
        {};
        auto const emitEvent = [&ctx, &addr]()
        {
          REQUIRE(ctx->EraseElement(addr));
        };

        testEventsFuncT<ScEventEraseElement>(*ctx, addr, prepare, emitEvent);
      } catch (...)
      {
        SC_LOG_ERROR("Test \"ScEventEraseElement\" failed")
      }
    }
    SUBTEST_END()
  }

  SECTION("events destroy order")
  {
    SUBTEST_START("events destroy order")
    {
      ScEventAddOutputEdge * evt;
      try
      {
        ScAddr const node = ctx->CreateNode(ScType::Unknown);
        REQUIRE(node.IsValid());

        evt = new ScEventAddOutputEdge(
              *ctx, node,
              [](ScAddr const &, ScAddr const &, ScAddr const &)
              {
                return true;
              });
      } catch (...)
      {
        SC_LOG_ERROR("Test \"events destroy order\" failed")
      }
      if (evt != nullptr)
        delete evt;
    }
    SUBTEST_END()
  }

  SECTION("events lock")
  {
    SUBTEST_START("events lock")
    {
      ScEventAddOutputEdge * evt;
      try
      {
        ScAddr const node = ctx->CreateNode(ScType::NodeConst);
        ScAddr const node2 = ctx->CreateNode(ScType::NodeConst);

        evt = new ScEventAddOutputEdge(
              *ctx, node,
              [](ScAddr const & addr, ScAddr const & edgeAddr, ScAddr const & otherAddr)
              {
                bool result = false;
                ScMemoryContext localCtx(sc_access_lvl_make_min);
                ScIterator3Ptr it = localCtx.Iterator3(addr, ScType::EdgeAccessConstPosPerm,
                                                       ScType::Unknown);
                while (it->Next())
                {
                  result = true;
                }

                return true;
              });

        for (size_t i = 0; i < 10000; i++)
        {
          ctx->CreateEdge(ScType::EdgeAccessConstPosPerm, node, node2);
        }
        if (evt != nullptr)
          delete evt;
      } catch (...)
      {
        SC_LOG_ERROR("Test \"events lock\" failed")
      }
    }
    SUBTEST_END()
  }

  ctx->Destroy();
  test::ScTestUnit::ShutdownMemory(false);
}

TEST_CASE("pend_events", "[test event]")
{
  test::ScTestUnit::InitMemory("sc-dumper.ini", "");
  ScMemoryContext ctx(sc_access_lvl_make_min, "pend_events");

  /* Main idea of test: create two sets with N elements, and add edges to relations.
   * Everytime, when event emits, we should check, that whole construction exist
   */

  volatile int32_t eventsCount = 0;
  volatile int32_t passedCount = 0;

  ScAddr const set1 = ctx.CreateNode(ScType::NodeConstClass);
  ScAddr const rel = ctx.CreateNode(ScType::NodeConstNoRole);

  static const size_t el_num = 1 << 10;
  std::vector<ScAddr> elements(el_num);

  ScTemplate templ;

  ScEventAddOutputEdge * evt = new ScEventAddOutputEdge
        (ctx, set1,
         [&passedCount, &eventsCount, &set1, &elements, &rel](ScAddr const &, ScAddr const &,
                                                              ScAddr const &)
         {
           std::shared_ptr<ScTemplate> checkTempl(new ScTemplate());
           size_t step = 100;
           size_t testNum = el_num / step - 1;
           for (size_t i = 0; i < testNum; ++i)
           {
             checkTempl->TripleWithRelation(
                   set1,
                   ScType::EdgeDCommonVar,
                   elements[i * step] >> "_el",
                   ScType::EdgeAccessVarPosPerm,
                   rel);
           }

           ScMemoryContext localCtx(sc_access_lvl_make_min);

           ScTemplateSearchResult res;
           REQUIRE(localCtx.HelperSearchTemplate(*checkTempl, res));

           if (res.Size() == 1)
             g_atomic_int_add(&passedCount, 1);

           g_atomic_int_add(&eventsCount, 1);

           localCtx.Destroy();
           res.Clear();

           return true;
         });

  try
  {
    for (size_t i = 0; i < el_num; ++i)
    {
      ScAddr const a = ctx.CreateNode(ScType::NodeConst);
      REQUIRE(a.IsValid());
      elements[i] = a;
    }

    // create template for pending events check
    for (auto const & a : elements)
    {
      templ.TripleWithRelation(
            set1,
            ScType::EdgeDCommonVar,
            a >> "_el",
            ScType::EdgeAccessVarPosPerm,
            rel);
    }

    ScTemplateGenResult genResult;
    REQUIRE(ctx.HelperGenTemplate(templ, genResult));

    // wait all events
    while (g_atomic_int_get(&eventsCount) < el_num)
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    REQUIRE(passedCount == el_num);
  } catch (...)
  {
    SC_LOG_ERROR("Test \"pend_events\" failed");
  }

  delete evt;
  ctx.Destroy();
  test::ScTestUnit::ShutdownMemory(false);
}
