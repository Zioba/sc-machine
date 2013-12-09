/** \file
 *  This C header file was generated by $ANTLR version !Unknown version!
 *
 *     -  From the grammar source file : grammar/scs.g
 *     -                            On : 2013-12-09 21:27:08
 *     -                 for the lexer : scsLexerLexer *
 * Editing it, at least manually, is not wise. 
 *
 * C language generator and runtime by Jim Idle, jimi|hereisanat|idle|dotgoeshere|ws.
 *
 *
 * The lexer scsLexer has the callable functions (rules) shown below,
 * which will invoke the code for the associated rule in the source grammar
 * assuming that the input stream is pointing to a token/text stream that could begin
 * this rule.
 * 
 * For instance if you call the first (topmost) rule in a parser grammar, you will
 * get the results of a full parse, but calling a rule half way through the grammar will
 * allow you to pass part of a full token stream to the parser, such as for syntax checking
 * in editors and so on.
 *
 * The parser entry points are called indirectly (by function pointer to function) via
 * a parser context typedef pscsLexer, which is returned from a call to scsLexerNew().
 *
 * As this is a generated lexer, it is unlikely you will call it 'manually'. However
 * the methods are provided anyway.
 * * The methods in pscsLexer are  as follows:
 *
 *  -  void      pscsLexer->SEP_SENTENCE(pscsLexer)
 *  -  void      pscsLexer->SEP_SIMPLE(pscsLexer)
 *  -  void      pscsLexer->SEP_LPAR(pscsLexer)
 *  -  void      pscsLexer->SEP_RPAR(pscsLexer)
 *  -  void      pscsLexer->SEP_ATTR_CONST(pscsLexer)
 *  -  void      pscsLexer->SEP_ATTR_VAR(pscsLexer)
 *  -  void      pscsLexer->SEP_IDTF(pscsLexer)
 *  -  void      pscsLexer->SEP_LINT(pscsLexer)
 *  -  void      pscsLexer->SEP_RINT(pscsLexer)
 *  -  void      pscsLexer->SEP_LTUPLE(pscsLexer)
 *  -  void      pscsLexer->SEP_RTUPLE(pscsLexer)
 *  -  void      pscsLexer->SEP_LSET(pscsLexer)
 *  -  void      pscsLexer->SEP_RSET(pscsLexer)
 *  -  void      pscsLexer->SEP_LCONTENT(pscsLexer)
 *  -  void      pscsLexer->SEP_RCONTENT(pscsLexer)
 *  -  void      pscsLexer->SEP_ASSIGN(pscsLexer)
 *  -  void      pscsLexer->ID_SYSTEM(pscsLexer)
 *  -  void      pscsLexer->COMMENT(pscsLexer)
 *  -  void      pscsLexer->CONTENT(pscsLexer)
 *  -  void      pscsLexer->LINK(pscsLexer)
 *  -  void      pscsLexer->CONNECTORS(pscsLexer)
 *  -  void      pscsLexer->HEX_DIGIT(pscsLexer)
 *  -  void      pscsLexer->WS(pscsLexer)
 *  -  void      pscsLexer->OCTAL_ESC(pscsLexer)
 *  -  void      pscsLexer->UNICODE_ESC(pscsLexer)
 *  -  void      pscsLexer->Tokens(pscsLexer)
 *
 * The return type for any particular rule is of course determined by the source
 * grammar file.
 */
// [The "BSD licence"]
// Copyright (c) 2005-2009 Jim Idle, Temporal Wave LLC
// http://www.temporal-wave.com
// http://www.linkedin.com/in/jimidle
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef	_scsLexer_H
#define _scsLexer_H
/* =============================================================================
 * Standard antlr3 C runtime definitions
 */
#include    <antlr3.h>

/* End of standard antlr 3 runtime definitions
 * =============================================================================
 */



 
#ifdef __cplusplus
extern "C" {
#endif

// Forward declare the context typedef so that we can use it before it is
// properly defined. Delegators and delegates (from import statements) are
// interdependent and their context structures contain pointers to each other
// C only allows such things to be declared if you pre-declare the typedef.
//
typedef struct scsLexer_Ctx_struct scsLexer, * pscsLexer;



#ifdef	ANTLR3_WINDOWS
// Disable: Unreferenced parameter,							- Rules with parameters that are not used
//          constant conditional,							- ANTLR realizes that a prediction is always true (synpred usually)
//          initialized but unused variable					- tree rewrite variables declared but not needed
//          Unreferenced local variable						- lexer rule declares but does not always use _type
//          potentially unitialized variable used			- retval always returned from a rule 
//			unreferenced local function has been removed	- susually getTokenNames or freeScope, they can go without warnigns
//
// These are only really displayed at warning level /W4 but that is the code ideal I am aiming at
// and the codegen must generate some of these warnings by necessity, apart from 4100, which is
// usually generated when a parser rule is given a parameter that it does not use. Mostly though
// this is a matter of orthogonality hence I disable that one.
//
#pragma warning( disable : 4100 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4701 )
#endif

/** Context tracking structure for scsLexer
 */
struct scsLexer_Ctx_struct
{
    /** Built in ANTLR3 context tracker contains all the generic elements
     *  required for context tracking.
     */
    pANTLR3_LEXER    pLexer;


     void (*mSEP_SENTENCE)	(struct scsLexer_Ctx_struct * ctx);
     void (*mSEP_SIMPLE)	(struct scsLexer_Ctx_struct * ctx);
     void (*mSEP_LPAR)	(struct scsLexer_Ctx_struct * ctx);
     void (*mSEP_RPAR)	(struct scsLexer_Ctx_struct * ctx);
     void (*mSEP_ATTR_CONST)	(struct scsLexer_Ctx_struct * ctx);
     void (*mSEP_ATTR_VAR)	(struct scsLexer_Ctx_struct * ctx);
     void (*mSEP_IDTF)	(struct scsLexer_Ctx_struct * ctx);
     void (*mSEP_LINT)	(struct scsLexer_Ctx_struct * ctx);
     void (*mSEP_RINT)	(struct scsLexer_Ctx_struct * ctx);
     void (*mSEP_LTUPLE)	(struct scsLexer_Ctx_struct * ctx);
     void (*mSEP_RTUPLE)	(struct scsLexer_Ctx_struct * ctx);
     void (*mSEP_LSET)	(struct scsLexer_Ctx_struct * ctx);
     void (*mSEP_RSET)	(struct scsLexer_Ctx_struct * ctx);
     void (*mSEP_LCONTENT)	(struct scsLexer_Ctx_struct * ctx);
     void (*mSEP_RCONTENT)	(struct scsLexer_Ctx_struct * ctx);
     void (*mSEP_ASSIGN)	(struct scsLexer_Ctx_struct * ctx);
     void (*mID_SYSTEM)	(struct scsLexer_Ctx_struct * ctx);
     void (*mCOMMENT)	(struct scsLexer_Ctx_struct * ctx);
     void (*mCONTENT)	(struct scsLexer_Ctx_struct * ctx);
     void (*mLINK)	(struct scsLexer_Ctx_struct * ctx);
     void (*mCONNECTORS)	(struct scsLexer_Ctx_struct * ctx);
     void (*mHEX_DIGIT)	(struct scsLexer_Ctx_struct * ctx);
     void (*mWS)	(struct scsLexer_Ctx_struct * ctx);
     void (*mOCTAL_ESC)	(struct scsLexer_Ctx_struct * ctx);
     void (*mUNICODE_ESC)	(struct scsLexer_Ctx_struct * ctx);
     void (*mTokens)	(struct scsLexer_Ctx_struct * ctx);    const char * (*getGrammarFileName)();
    void	    (*free)   (struct scsLexer_Ctx_struct * ctx);
        
};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//
ANTLR3_API pscsLexer scsLexerNew         (pANTLR3_INPUT_STREAM instream);
ANTLR3_API pscsLexer scsLexerNewSSD      (pANTLR3_INPUT_STREAM instream, pANTLR3_RECOGNIZER_SHARED_STATE state);

/** Symbolic definitions of all the tokens that the lexer will work with.
 * \{
 *
 * Antlr will define EOF, but we can't use that as it it is too common in
 * in C header files and that would be confusing. There is no way to filter this out at the moment
 * so we just undef it here for now. That isn't the value we get back from C recognizers
 * anyway. We are looking for ANTLR3_TOKEN_EOF.
 */
#ifdef	EOF
#undef	EOF
#endif
#ifdef	Tokens
#undef	Tokens
#endif 
#define SEP_ATTR_CONST      8
#define SEP_RPAR      7
#define SEP_RINT      12
#define SEP_RCONTENT      18
#define SEP_LINT      11
#define SEP_RTUPLE      14
#define SEP_LCONTENT      17
#define UNICODE_ESC      28
#define SEP_LPAR      6
#define OCTAL_ESC      27
#define HEX_DIGIT      25
#define CONNECTORS      20
#define LINK      23
#define CONTENT      21
#define EOF      -1
#define SEP_IDTF      10
#define SEP_LSET      15
#define WS      26
#define SEP_SIMPLE      5
#define SEP_LTUPLE      13
#define SEP_ATTR_VAR      9
#define ID_SYSTEM      22
#define SEP_SENTENCE      4
#define COMMENT      24
#define SEP_RSET      16
#define SEP_ASSIGN      19
#ifdef	EOF
#undef	EOF
#define	EOF	ANTLR3_TOKEN_EOF
#endif

#ifndef TOKENSOURCE
#define TOKENSOURCE(lxr) lxr->pLexer->rec->state->tokSource
#endif

/* End of token definitions for scsLexer
 * =============================================================================
 */
/** \} */

#ifdef __cplusplus
}
#endif

#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */
