/*
* This source file is part of an OSTIS project. For the latest info, see http://ostis.net
* Distributed under the MIT License
* (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
*/

#include "SubdividingSearchAgent.hpp"

#include <sc_agent.generated.hpp>

using namespace std;
using namespace utils;

namespace exampleModule
{

sc_result SubdividingSearchAgent::Run(ScAddr const & listenAddr)
//SC_AGENT_IMPLEMENTATION(SubdividingSearchAgent)
{
  if (!listenAddr.IsValid())
    return SC_RESULT_ERROR;

  ScAddr a = ms_context->CreateNode(ScType::NodeConstTuple);
  ms_context -> HelperSetSystemIdtf("SUCCESS", a);



//  ScAddr systemIdtf = ms_context->HelperFindBySystemIdtf("nrel_system_identifier");
//  cout << listenAddr.IsValid();
//
//
//  ScAddr a = ms_context->CreateNode(ScType::Node);
//  ScAddr b = ms_context->CreateNode(ScType::Node);
//  ScAddr link = ms_context->CreateLink();
//  sc_char * idtf = "a";
//  ScStreamPtr stream;
//  stream.reset(new ScStream(idtf, sizeof(*idtf), SC_STREAM_FLAG_READ | SC_STREAM_FLAG_SEEK));
//  ms_context->SetLinkContent(link, stream);
//  ms_context->HelperSetSystemIdtf("a", a);
//  ScAddr arc = ms_context->CreateEdge(ScType::EdgeDCommonConst, b, link);
//  ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, systemIdtf, arc);

//  ScTemplate templ;
//  //templ.
//  templ.TripleWithRelation(
//        ScType::Unknown,
//        ScType::EdgeDCommonVar,
//        ScType::Link,
//        ScType::EdgeAccessVarPosPerm,
//        systemIdtf);
//
//  ScTemplateSearchResult res;
//  if (ms_context->HelperSearchTemplate(templ, res) == true) {
//    for (int i = 0; i < res.Size()-1; i++)
//    {
//      std::string str1 = ms_context->HelperGetSystemIdtf(res[i][0]);
//      for (int j = i+1; j < res.Size(); j++)
//      {
//        std::string str2 = ms_context->HelperGetSystemIdtf(res[j][0]);
//        if (str1 == str2)
//        {
//          //do elimination here
//          std::cout << str1;
//        }
//      }
//    }
//  }


  return SC_RESULT_OK;
}

}
