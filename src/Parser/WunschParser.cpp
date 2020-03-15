
// Generated from Wunsch.g4 by ANTLR 4.7.2


#include "WunschListener.h"
#include "WunschVisitor.h"

#include "WunschParser.h"


using namespace antlrcpp;
using namespace antlr4;

WunschParser::WunschParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

WunschParser::~WunschParser() {
  delete _interpreter;
}

std::string WunschParser::getGrammarFileName() const {
  return "Wunsch.g4";
}

const std::vector<std::string>& WunschParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& WunschParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

WunschParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<WunschParser::StmtContext *> WunschParser::ProgramContext::stmt() {
  return getRuleContexts<WunschParser::StmtContext>();
}

WunschParser::StmtContext* WunschParser::ProgramContext::stmt(size_t i) {
  return getRuleContext<WunschParser::StmtContext>(i);
}


size_t WunschParser::ProgramContext::getRuleIndex() const {
  return WunschParser::RuleProgram;
}

void WunschParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void WunschParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


antlrcpp::Any WunschParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

WunschParser::ProgramContext* WunschParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, WunschParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(45);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WunschParser::T__1)
      | (1ULL << WunschParser::T__3)
      | (1ULL << WunschParser::T__7)
      | (1ULL << WunschParser::T__9)
      | (1ULL << WunschParser::T__10)
      | (1ULL << WunschParser::T__11)
      | (1ULL << WunschParser::T__12)
      | (1ULL << WunschParser::T__26)
      | (1ULL << WunschParser::T__29)
      | (1ULL << WunschParser::T__30)
      | (1ULL << WunschParser::T__32)
      | (1ULL << WunschParser::T__34)
      | (1ULL << WunschParser::T__35)
      | (1ULL << WunschParser::T__37)
      | (1ULL << WunschParser::DEC_INT)
      | (1ULL << WunschParser::OCT_INT)
      | (1ULL << WunschParser::HEX_INT)
      | (1ULL << WunschParser::FLOAT)
      | (1ULL << WunschParser::BOOLEANLIT)
      | (1ULL << WunschParser::STRING)
      | (1ULL << WunschParser::THIS)
      | (1ULL << WunschParser::ID))) != 0)) {
      setState(42);
      stmt();
      setState(47);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

WunschParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WunschParser::ExprContext* WunschParser::StmtContext::expr() {
  return getRuleContext<WunschParser::ExprContext>(0);
}

WunschParser::VarDefContext* WunschParser::StmtContext::varDef() {
  return getRuleContext<WunschParser::VarDefContext>(0);
}

WunschParser::AssignmentContext* WunschParser::StmtContext::assignment() {
  return getRuleContext<WunschParser::AssignmentContext>(0);
}

WunschParser::CondStmtContext* WunschParser::StmtContext::condStmt() {
  return getRuleContext<WunschParser::CondStmtContext>(0);
}

WunschParser::WhileStmtContext* WunschParser::StmtContext::whileStmt() {
  return getRuleContext<WunschParser::WhileStmtContext>(0);
}

WunschParser::ForStmtContext* WunschParser::StmtContext::forStmt() {
  return getRuleContext<WunschParser::ForStmtContext>(0);
}

WunschParser::ReturnStmtContext* WunschParser::StmtContext::returnStmt() {
  return getRuleContext<WunschParser::ReturnStmtContext>(0);
}


size_t WunschParser::StmtContext::getRuleIndex() const {
  return WunschParser::RuleStmt;
}

void WunschParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void WunschParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}


antlrcpp::Any WunschParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

WunschParser::StmtContext* WunschParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 2, WunschParser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(63);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(48);
      expr(0);
      setState(49);
      match(WunschParser::T__0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(51);
      varDef();
      setState(52);
      match(WunschParser::T__0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(54);
      assignment();
      setState(55);
      match(WunschParser::T__0);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(57);
      condStmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(58);
      whileStmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(59);
      forStmt();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(60);
      returnStmt();
      setState(61);
      match(WunschParser::T__0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

WunschParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t WunschParser::ExprContext::getRuleIndex() const {
  return WunschParser::RuleExpr;
}

void WunschParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ThisExprContext ------------------------------------------------------------------

tree::TerminalNode* WunschParser::ThisExprContext::THIS() {
  return getToken(WunschParser::THIS, 0);
}

WunschParser::ThisExprContext::ThisExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WunschParser::ThisExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThisExpr(this);
}
void WunschParser::ThisExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThisExpr(this);
}

antlrcpp::Any WunschParser::ThisExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitThisExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeepCopyExprContext ------------------------------------------------------------------

WunschParser::ExprContext* WunschParser::DeepCopyExprContext::expr() {
  return getRuleContext<WunschParser::ExprContext>(0);
}

WunschParser::DeepCopyExprContext::DeepCopyExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WunschParser::DeepCopyExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeepCopyExpr(this);
}
void WunschParser::DeepCopyExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeepCopyExpr(this);
}

antlrcpp::Any WunschParser::DeepCopyExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitDeepCopyExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinNotExprContext ------------------------------------------------------------------

WunschParser::ExprContext* WunschParser::BinNotExprContext::expr() {
  return getRuleContext<WunschParser::ExprContext>(0);
}

WunschParser::BinNotExprContext::BinNotExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WunschParser::BinNotExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinNotExpr(this);
}
void WunschParser::BinNotExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinNotExpr(this);
}

antlrcpp::Any WunschParser::BinNotExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitBinNotExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogiAndExprContext ------------------------------------------------------------------

std::vector<WunschParser::ExprContext *> WunschParser::LogiAndExprContext::expr() {
  return getRuleContexts<WunschParser::ExprContext>();
}

WunschParser::ExprContext* WunschParser::LogiAndExprContext::expr(size_t i) {
  return getRuleContext<WunschParser::ExprContext>(i);
}

WunschParser::LogiAndExprContext::LogiAndExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WunschParser::LogiAndExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogiAndExpr(this);
}
void WunschParser::LogiAndExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogiAndExpr(this);
}

antlrcpp::Any WunschParser::LogiAndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitLogiAndExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultdivExprContext ------------------------------------------------------------------

std::vector<WunschParser::ExprContext *> WunschParser::MultdivExprContext::expr() {
  return getRuleContexts<WunschParser::ExprContext>();
}

WunschParser::ExprContext* WunschParser::MultdivExprContext::expr(size_t i) {
  return getRuleContext<WunschParser::ExprContext>(i);
}

WunschParser::MultdivExprContext::MultdivExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WunschParser::MultdivExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultdivExpr(this);
}
void WunschParser::MultdivExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultdivExpr(this);
}

antlrcpp::Any WunschParser::MultdivExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitMultdivExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BracketExprContext ------------------------------------------------------------------

WunschParser::ExprContext* WunschParser::BracketExprContext::expr() {
  return getRuleContext<WunschParser::ExprContext>(0);
}

WunschParser::BracketExprContext::BracketExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WunschParser::BracketExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBracketExpr(this);
}
void WunschParser::BracketExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBracketExpr(this);
}

antlrcpp::Any WunschParser::BracketExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitBracketExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddMinExprContext ------------------------------------------------------------------

std::vector<WunschParser::ExprContext *> WunschParser::AddMinExprContext::expr() {
  return getRuleContexts<WunschParser::ExprContext>();
}

WunschParser::ExprContext* WunschParser::AddMinExprContext::expr(size_t i) {
  return getRuleContext<WunschParser::ExprContext>(i);
}

WunschParser::AddMinExprContext::AddMinExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WunschParser::AddMinExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddMinExpr(this);
}
void WunschParser::AddMinExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddMinExpr(this);
}

antlrcpp::Any WunschParser::AddMinExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitAddMinExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeepCopyModifyExprContext ------------------------------------------------------------------

std::vector<WunschParser::ExprContext *> WunschParser::DeepCopyModifyExprContext::expr() {
  return getRuleContexts<WunschParser::ExprContext>();
}

WunschParser::ExprContext* WunschParser::DeepCopyModifyExprContext::expr(size_t i) {
  return getRuleContext<WunschParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> WunschParser::DeepCopyModifyExprContext::ID() {
  return getTokens(WunschParser::ID);
}

tree::TerminalNode* WunschParser::DeepCopyModifyExprContext::ID(size_t i) {
  return getToken(WunschParser::ID, i);
}

WunschParser::DeepCopyModifyExprContext::DeepCopyModifyExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WunschParser::DeepCopyModifyExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeepCopyModifyExpr(this);
}
void WunschParser::DeepCopyModifyExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeepCopyModifyExpr(this);
}

antlrcpp::Any WunschParser::DeepCopyModifyExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitDeepCopyModifyExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogiNotExprContext ------------------------------------------------------------------

WunschParser::ExprContext* WunschParser::LogiNotExprContext::expr() {
  return getRuleContext<WunschParser::ExprContext>(0);
}

WunschParser::LogiNotExprContext::LogiNotExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WunschParser::LogiNotExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogiNotExpr(this);
}
void WunschParser::LogiNotExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogiNotExpr(this);
}

antlrcpp::Any WunschParser::LogiNotExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitLogiNotExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BracoAccessExprContext ------------------------------------------------------------------

std::vector<WunschParser::ExprContext *> WunschParser::BracoAccessExprContext::expr() {
  return getRuleContexts<WunschParser::ExprContext>();
}

WunschParser::ExprContext* WunschParser::BracoAccessExprContext::expr(size_t i) {
  return getRuleContext<WunschParser::ExprContext>(i);
}

WunschParser::BracoAccessExprContext::BracoAccessExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WunschParser::BracoAccessExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBracoAccessExpr(this);
}
void WunschParser::BracoAccessExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBracoAccessExpr(this);
}

antlrcpp::Any WunschParser::BracoAccessExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitBracoAccessExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinOrExprContext ------------------------------------------------------------------

std::vector<WunschParser::ExprContext *> WunschParser::BinOrExprContext::expr() {
  return getRuleContexts<WunschParser::ExprContext>();
}

WunschParser::ExprContext* WunschParser::BinOrExprContext::expr(size_t i) {
  return getRuleContext<WunschParser::ExprContext>(i);
}

WunschParser::BinOrExprContext::BinOrExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WunschParser::BinOrExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinOrExpr(this);
}
void WunschParser::BinOrExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinOrExpr(this);
}

antlrcpp::Any WunschParser::BinOrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitBinOrExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinXorExprContext ------------------------------------------------------------------

std::vector<WunschParser::ExprContext *> WunschParser::BinXorExprContext::expr() {
  return getRuleContexts<WunschParser::ExprContext>();
}

WunschParser::ExprContext* WunschParser::BinXorExprContext::expr(size_t i) {
  return getRuleContext<WunschParser::ExprContext>(i);
}

WunschParser::BinXorExprContext::BinXorExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WunschParser::BinXorExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinXorExpr(this);
}
void WunschParser::BinXorExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinXorExpr(this);
}

antlrcpp::Any WunschParser::BinXorExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitBinXorExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FuncallExprContext ------------------------------------------------------------------

WunschParser::ExprContext* WunschParser::FuncallExprContext::expr() {
  return getRuleContext<WunschParser::ExprContext>(0);
}

WunschParser::ExprListContext* WunschParser::FuncallExprContext::exprList() {
  return getRuleContext<WunschParser::ExprListContext>(0);
}

WunschParser::FuncallExprContext::FuncallExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WunschParser::FuncallExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncallExpr(this);
}
void WunschParser::FuncallExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncallExpr(this);
}

antlrcpp::Any WunschParser::FuncallExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitFuncallExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunDefLiteralContext ------------------------------------------------------------------

WunschParser::FuncDefContext* WunschParser::FunDefLiteralContext::funcDef() {
  return getRuleContext<WunschParser::FuncDefContext>(0);
}

WunschParser::FunDefLiteralContext::FunDefLiteralContext(ExprContext *ctx) { copyFrom(ctx); }

void WunschParser::FunDefLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunDefLiteral(this);
}
void WunschParser::FunDefLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunDefLiteral(this);
}

antlrcpp::Any WunschParser::FunDefLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitFunDefLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralExprContext ------------------------------------------------------------------

WunschParser::LiteralContext* WunschParser::LiteralExprContext::literal() {
  return getRuleContext<WunschParser::LiteralContext>(0);
}

WunschParser::LiteralExprContext::LiteralExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WunschParser::LiteralExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteralExpr(this);
}
void WunschParser::LiteralExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteralExpr(this);
}

antlrcpp::Any WunschParser::LiteralExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitLiteralExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogiOrExprContext ------------------------------------------------------------------

std::vector<WunschParser::ExprContext *> WunschParser::LogiOrExprContext::expr() {
  return getRuleContexts<WunschParser::ExprContext>();
}

WunschParser::ExprContext* WunschParser::LogiOrExprContext::expr(size_t i) {
  return getRuleContext<WunschParser::ExprContext>(i);
}

WunschParser::LogiOrExprContext::LogiOrExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WunschParser::LogiOrExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogiOrExpr(this);
}
void WunschParser::LogiOrExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogiOrExpr(this);
}

antlrcpp::Any WunschParser::LogiOrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitLogiOrExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinAndExprContext ------------------------------------------------------------------

std::vector<WunschParser::ExprContext *> WunschParser::BinAndExprContext::expr() {
  return getRuleContexts<WunschParser::ExprContext>();
}

WunschParser::ExprContext* WunschParser::BinAndExprContext::expr(size_t i) {
  return getRuleContext<WunschParser::ExprContext>(i);
}

WunschParser::BinAndExprContext::BinAndExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WunschParser::BinAndExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinAndExpr(this);
}
void WunschParser::BinAndExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinAndExpr(this);
}

antlrcpp::Any WunschParser::BinAndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitBinAndExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MemberAccessExprContext ------------------------------------------------------------------

WunschParser::ExprContext* WunschParser::MemberAccessExprContext::expr() {
  return getRuleContext<WunschParser::ExprContext>(0);
}

tree::TerminalNode* WunschParser::MemberAccessExprContext::ID() {
  return getToken(WunschParser::ID, 0);
}

WunschParser::MemberAccessExprContext::MemberAccessExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WunschParser::MemberAccessExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMemberAccessExpr(this);
}
void WunschParser::MemberAccessExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMemberAccessExpr(this);
}

antlrcpp::Any WunschParser::MemberAccessExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitMemberAccessExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryPMExprContext ------------------------------------------------------------------

WunschParser::ExprContext* WunschParser::UnaryPMExprContext::expr() {
  return getRuleContext<WunschParser::ExprContext>(0);
}

WunschParser::UnaryPMExprContext::UnaryPMExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WunschParser::UnaryPMExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryPMExpr(this);
}
void WunschParser::UnaryPMExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryPMExpr(this);
}

antlrcpp::Any WunschParser::UnaryPMExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitUnaryPMExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdExprContext ------------------------------------------------------------------

tree::TerminalNode* WunschParser::IdExprContext::ID() {
  return getToken(WunschParser::ID, 0);
}

WunschParser::IdExprContext::IdExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WunschParser::IdExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdExpr(this);
}
void WunschParser::IdExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdExpr(this);
}

antlrcpp::Any WunschParser::IdExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitIdExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CompareExprContext ------------------------------------------------------------------

std::vector<WunschParser::ExprContext *> WunschParser::CompareExprContext::expr() {
  return getRuleContexts<WunschParser::ExprContext>();
}

WunschParser::ExprContext* WunschParser::CompareExprContext::expr(size_t i) {
  return getRuleContext<WunschParser::ExprContext>(i);
}

WunschParser::CompareExprContext::CompareExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WunschParser::CompareExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompareExpr(this);
}
void WunschParser::CompareExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompareExpr(this);
}

antlrcpp::Any WunschParser::CompareExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitCompareExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqualExprContext ------------------------------------------------------------------

std::vector<WunschParser::ExprContext *> WunschParser::EqualExprContext::expr() {
  return getRuleContexts<WunschParser::ExprContext>();
}

WunschParser::ExprContext* WunschParser::EqualExprContext::expr(size_t i) {
  return getRuleContext<WunschParser::ExprContext>(i);
}

WunschParser::EqualExprContext::EqualExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WunschParser::EqualExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqualExpr(this);
}
void WunschParser::EqualExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqualExpr(this);
}

antlrcpp::Any WunschParser::EqualExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitEqualExpr(this);
  else
    return visitor->visitChildren(this);
}

WunschParser::ExprContext* WunschParser::expr() {
   return expr(0);
}

WunschParser::ExprContext* WunschParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  WunschParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  WunschParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, WunschParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(95);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<LiteralExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(66);
      literal();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<FunDefLiteralContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(67);
      funcDef();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ThisExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(68);
      match(WunschParser::THIS);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<IdExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(69);
      match(WunschParser::ID);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<BracketExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(70);
      match(WunschParser::T__1);
      setState(71);
      expr(0);
      setState(72);
      match(WunschParser::T__2);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<DeepCopyExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(74);
      match(WunschParser::T__3);
      setState(75);
      expr(0);
      setState(76);
      match(WunschParser::T__4);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<DeepCopyModifyExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(78);
      match(WunschParser::T__3);
      setState(79);
      expr(0);
      setState(83); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(80);
        match(WunschParser::ID);
        setState(81);
        match(WunschParser::T__5);
        setState(82);
        expr(0);
        setState(85); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == WunschParser::ID);
      setState(87);
      match(WunschParser::T__4);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<LogiNotExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(89);
      match(WunschParser::T__9);
      setState(90);
      expr(12);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<BinNotExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(91);
      match(WunschParser::T__10);
      setState(92);
      expr(11);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<UnaryPMExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(93);
      dynamic_cast<UnaryPMExprContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == WunschParser::T__11

      || _la == WunschParser::T__12)) {
        dynamic_cast<UnaryPMExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(94);
      expr(10);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(139);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(137);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultdivExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(97);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(98);
          dynamic_cast<MultdivExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << WunschParser::T__13)
            | (1ULL << WunschParser::T__14)
            | (1ULL << WunschParser::T__15))) != 0))) {
            dynamic_cast<MultdivExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(99);
          expr(10);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddMinExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(100);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(101);
          dynamic_cast<AddMinExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == WunschParser::T__11

          || _la == WunschParser::T__12)) {
            dynamic_cast<AddMinExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(102);
          expr(9);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<CompareExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(103);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(104);
          dynamic_cast<CompareExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << WunschParser::T__3)
            | (1ULL << WunschParser::T__4)
            | (1ULL << WunschParser::T__16)
            | (1ULL << WunschParser::T__17))) != 0))) {
            dynamic_cast<CompareExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(105);
          expr(8);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<EqualExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(106);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(107);
          dynamic_cast<EqualExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == WunschParser::T__18

          || _la == WunschParser::T__19)) {
            dynamic_cast<EqualExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(108);
          expr(7);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BinAndExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(109);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(110);
          match(WunschParser::T__20);
          setState(111);
          expr(6);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BinXorExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(112);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(113);
          match(WunschParser::T__21);
          setState(114);
          expr(5);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BinOrExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(115);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(116);
          match(WunschParser::T__22);
          setState(117);
          expr(4);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<LogiAndExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(118);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(119);
          match(WunschParser::T__23);
          setState(120);
          expr(3);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<LogiOrExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(121);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(122);
          match(WunschParser::T__24);
          setState(123);
          expr(2);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<MemberAccessExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(124);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(125);
          match(WunschParser::T__6);
          setState(126);
          match(WunschParser::ID);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<BracoAccessExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(127);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(128);
          match(WunschParser::T__7);
          setState(129);
          expr(0);
          setState(130);
          match(WunschParser::T__8);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<FuncallExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(132);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(133);
          match(WunschParser::T__1);
          setState(134);
          exprList();
          setState(135);
          match(WunschParser::T__2);
          break;
        }

        } 
      }
      setState(141);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

WunschParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WunschParser::IntegerLiteralContext* WunschParser::LiteralContext::integerLiteral() {
  return getRuleContext<WunschParser::IntegerLiteralContext>(0);
}

WunschParser::FloatLiteralContext* WunschParser::LiteralContext::floatLiteral() {
  return getRuleContext<WunschParser::FloatLiteralContext>(0);
}

WunschParser::BoolLiteralContext* WunschParser::LiteralContext::boolLiteral() {
  return getRuleContext<WunschParser::BoolLiteralContext>(0);
}

WunschParser::StringLiteralContext* WunschParser::LiteralContext::stringLiteral() {
  return getRuleContext<WunschParser::StringLiteralContext>(0);
}

WunschParser::ListLiteralContext* WunschParser::LiteralContext::listLiteral() {
  return getRuleContext<WunschParser::ListLiteralContext>(0);
}

WunschParser::DictLiteralContext* WunschParser::LiteralContext::dictLiteral() {
  return getRuleContext<WunschParser::DictLiteralContext>(0);
}

WunschParser::NilLiteralContext* WunschParser::LiteralContext::nilLiteral() {
  return getRuleContext<WunschParser::NilLiteralContext>(0);
}


size_t WunschParser::LiteralContext::getRuleIndex() const {
  return WunschParser::RuleLiteral;
}

void WunschParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void WunschParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}


antlrcpp::Any WunschParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

WunschParser::LiteralContext* WunschParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 6, WunschParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(149);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case WunschParser::DEC_INT:
      case WunschParser::OCT_INT:
      case WunschParser::HEX_INT: {
        enterOuterAlt(_localctx, 1);
        setState(142);
        integerLiteral();
        break;
      }

      case WunschParser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(143);
        floatLiteral();
        break;
      }

      case WunschParser::BOOLEANLIT: {
        enterOuterAlt(_localctx, 3);
        setState(144);
        boolLiteral();
        break;
      }

      case WunschParser::STRING: {
        enterOuterAlt(_localctx, 4);
        setState(145);
        stringLiteral();
        break;
      }

      case WunschParser::T__7: {
        enterOuterAlt(_localctx, 5);
        setState(146);
        listLiteral();
        break;
      }

      case WunschParser::T__26: {
        enterOuterAlt(_localctx, 6);
        setState(147);
        dictLiteral();
        break;
      }

      case WunschParser::T__29: {
        enterOuterAlt(_localctx, 7);
        setState(148);
        nilLiteral();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntegerLiteralContext ------------------------------------------------------------------

WunschParser::IntegerLiteralContext::IntegerLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t WunschParser::IntegerLiteralContext::getRuleIndex() const {
  return WunschParser::RuleIntegerLiteral;
}

void WunschParser::IntegerLiteralContext::copyFrom(IntegerLiteralContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- HexIntegerContext ------------------------------------------------------------------

tree::TerminalNode* WunschParser::HexIntegerContext::HEX_INT() {
  return getToken(WunschParser::HEX_INT, 0);
}

WunschParser::HexIntegerContext::HexIntegerContext(IntegerLiteralContext *ctx) { copyFrom(ctx); }

void WunschParser::HexIntegerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterHexInteger(this);
}
void WunschParser::HexIntegerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitHexInteger(this);
}

antlrcpp::Any WunschParser::HexIntegerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitHexInteger(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OctIntegerContext ------------------------------------------------------------------

tree::TerminalNode* WunschParser::OctIntegerContext::OCT_INT() {
  return getToken(WunschParser::OCT_INT, 0);
}

WunschParser::OctIntegerContext::OctIntegerContext(IntegerLiteralContext *ctx) { copyFrom(ctx); }

void WunschParser::OctIntegerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOctInteger(this);
}
void WunschParser::OctIntegerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOctInteger(this);
}

antlrcpp::Any WunschParser::OctIntegerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitOctInteger(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DecIntegerContext ------------------------------------------------------------------

tree::TerminalNode* WunschParser::DecIntegerContext::DEC_INT() {
  return getToken(WunschParser::DEC_INT, 0);
}

WunschParser::DecIntegerContext::DecIntegerContext(IntegerLiteralContext *ctx) { copyFrom(ctx); }

void WunschParser::DecIntegerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecInteger(this);
}
void WunschParser::DecIntegerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecInteger(this);
}

antlrcpp::Any WunschParser::DecIntegerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitDecInteger(this);
  else
    return visitor->visitChildren(this);
}
WunschParser::IntegerLiteralContext* WunschParser::integerLiteral() {
  IntegerLiteralContext *_localctx = _tracker.createInstance<IntegerLiteralContext>(_ctx, getState());
  enterRule(_localctx, 8, WunschParser::RuleIntegerLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(154);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case WunschParser::DEC_INT: {
        _localctx = dynamic_cast<IntegerLiteralContext *>(_tracker.createInstance<WunschParser::DecIntegerContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(151);
        match(WunschParser::DEC_INT);
        break;
      }

      case WunschParser::OCT_INT: {
        _localctx = dynamic_cast<IntegerLiteralContext *>(_tracker.createInstance<WunschParser::OctIntegerContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(152);
        match(WunschParser::OCT_INT);
        break;
      }

      case WunschParser::HEX_INT: {
        _localctx = dynamic_cast<IntegerLiteralContext *>(_tracker.createInstance<WunschParser::HexIntegerContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(153);
        match(WunschParser::HEX_INT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FloatLiteralContext ------------------------------------------------------------------

WunschParser::FloatLiteralContext::FloatLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WunschParser::FloatLiteralContext::FLOAT() {
  return getToken(WunschParser::FLOAT, 0);
}


size_t WunschParser::FloatLiteralContext::getRuleIndex() const {
  return WunschParser::RuleFloatLiteral;
}

void WunschParser::FloatLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFloatLiteral(this);
}

void WunschParser::FloatLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFloatLiteral(this);
}


antlrcpp::Any WunschParser::FloatLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitFloatLiteral(this);
  else
    return visitor->visitChildren(this);
}

WunschParser::FloatLiteralContext* WunschParser::floatLiteral() {
  FloatLiteralContext *_localctx = _tracker.createInstance<FloatLiteralContext>(_ctx, getState());
  enterRule(_localctx, 10, WunschParser::RuleFloatLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    match(WunschParser::FLOAT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BoolLiteralContext ------------------------------------------------------------------

WunschParser::BoolLiteralContext::BoolLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WunschParser::BoolLiteralContext::BOOLEANLIT() {
  return getToken(WunschParser::BOOLEANLIT, 0);
}


size_t WunschParser::BoolLiteralContext::getRuleIndex() const {
  return WunschParser::RuleBoolLiteral;
}

void WunschParser::BoolLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolLiteral(this);
}

void WunschParser::BoolLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolLiteral(this);
}


antlrcpp::Any WunschParser::BoolLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitBoolLiteral(this);
  else
    return visitor->visitChildren(this);
}

WunschParser::BoolLiteralContext* WunschParser::boolLiteral() {
  BoolLiteralContext *_localctx = _tracker.createInstance<BoolLiteralContext>(_ctx, getState());
  enterRule(_localctx, 12, WunschParser::RuleBoolLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(158);
    match(WunschParser::BOOLEANLIT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringLiteralContext ------------------------------------------------------------------

WunschParser::StringLiteralContext::StringLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> WunschParser::StringLiteralContext::STRING() {
  return getTokens(WunschParser::STRING);
}

tree::TerminalNode* WunschParser::StringLiteralContext::STRING(size_t i) {
  return getToken(WunschParser::STRING, i);
}


size_t WunschParser::StringLiteralContext::getRuleIndex() const {
  return WunschParser::RuleStringLiteral;
}

void WunschParser::StringLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStringLiteral(this);
}

void WunschParser::StringLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStringLiteral(this);
}


antlrcpp::Any WunschParser::StringLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitStringLiteral(this);
  else
    return visitor->visitChildren(this);
}

WunschParser::StringLiteralContext* WunschParser::stringLiteral() {
  StringLiteralContext *_localctx = _tracker.createInstance<StringLiteralContext>(_ctx, getState());
  enterRule(_localctx, 14, WunschParser::RuleStringLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(161); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(160);
              match(WunschParser::STRING);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(163); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ListLiteralContext ------------------------------------------------------------------

WunschParser::ListLiteralContext::ListLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<WunschParser::ExprContext *> WunschParser::ListLiteralContext::expr() {
  return getRuleContexts<WunschParser::ExprContext>();
}

WunschParser::ExprContext* WunschParser::ListLiteralContext::expr(size_t i) {
  return getRuleContext<WunschParser::ExprContext>(i);
}


size_t WunschParser::ListLiteralContext::getRuleIndex() const {
  return WunschParser::RuleListLiteral;
}

void WunschParser::ListLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterListLiteral(this);
}

void WunschParser::ListLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitListLiteral(this);
}


antlrcpp::Any WunschParser::ListLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitListLiteral(this);
  else
    return visitor->visitChildren(this);
}

WunschParser::ListLiteralContext* WunschParser::listLiteral() {
  ListLiteralContext *_localctx = _tracker.createInstance<ListLiteralContext>(_ctx, getState());
  enterRule(_localctx, 16, WunschParser::RuleListLiteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    match(WunschParser::T__7);
    setState(174);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WunschParser::T__1)
      | (1ULL << WunschParser::T__3)
      | (1ULL << WunschParser::T__7)
      | (1ULL << WunschParser::T__9)
      | (1ULL << WunschParser::T__10)
      | (1ULL << WunschParser::T__11)
      | (1ULL << WunschParser::T__12)
      | (1ULL << WunschParser::T__26)
      | (1ULL << WunschParser::T__29)
      | (1ULL << WunschParser::DEC_INT)
      | (1ULL << WunschParser::OCT_INT)
      | (1ULL << WunschParser::HEX_INT)
      | (1ULL << WunschParser::FLOAT)
      | (1ULL << WunschParser::BOOLEANLIT)
      | (1ULL << WunschParser::STRING)
      | (1ULL << WunschParser::THIS)
      | (1ULL << WunschParser::ID))) != 0)) {
      setState(166);
      expr(0);
      setState(171);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WunschParser::T__25) {
        setState(167);
        match(WunschParser::T__25);
        setState(168);
        expr(0);
        setState(173);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(176);
    match(WunschParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DictLiteralContext ------------------------------------------------------------------

WunschParser::DictLiteralContext::DictLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> WunschParser::DictLiteralContext::ID() {
  return getTokens(WunschParser::ID);
}

tree::TerminalNode* WunschParser::DictLiteralContext::ID(size_t i) {
  return getToken(WunschParser::ID, i);
}

std::vector<WunschParser::ExprContext *> WunschParser::DictLiteralContext::expr() {
  return getRuleContexts<WunschParser::ExprContext>();
}

WunschParser::ExprContext* WunschParser::DictLiteralContext::expr(size_t i) {
  return getRuleContext<WunschParser::ExprContext>(i);
}


size_t WunschParser::DictLiteralContext::getRuleIndex() const {
  return WunschParser::RuleDictLiteral;
}

void WunschParser::DictLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDictLiteral(this);
}

void WunschParser::DictLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDictLiteral(this);
}


antlrcpp::Any WunschParser::DictLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitDictLiteral(this);
  else
    return visitor->visitChildren(this);
}

WunschParser::DictLiteralContext* WunschParser::dictLiteral() {
  DictLiteralContext *_localctx = _tracker.createInstance<DictLiteralContext>(_ctx, getState());
  enterRule(_localctx, 18, WunschParser::RuleDictLiteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(178);
    match(WunschParser::T__26);
    setState(191);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == WunschParser::ID) {
      setState(179);
      match(WunschParser::ID);
      setState(180);
      match(WunschParser::T__27);
      setState(181);
      expr(0);
      setState(188);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WunschParser::T__25) {
        setState(182);
        match(WunschParser::T__25);
        setState(183);
        match(WunschParser::ID);
        setState(184);
        match(WunschParser::T__27);
        setState(185);
        expr(0);
        setState(190);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(193);
    match(WunschParser::T__28);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NilLiteralContext ------------------------------------------------------------------

WunschParser::NilLiteralContext::NilLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t WunschParser::NilLiteralContext::getRuleIndex() const {
  return WunschParser::RuleNilLiteral;
}

void WunschParser::NilLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNilLiteral(this);
}

void WunschParser::NilLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNilLiteral(this);
}


antlrcpp::Any WunschParser::NilLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitNilLiteral(this);
  else
    return visitor->visitChildren(this);
}

WunschParser::NilLiteralContext* WunschParser::nilLiteral() {
  NilLiteralContext *_localctx = _tracker.createInstance<NilLiteralContext>(_ctx, getState());
  enterRule(_localctx, 20, WunschParser::RuleNilLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(195);
    match(WunschParser::T__29);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext ------------------------------------------------------------------

WunschParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t WunschParser::VarDefContext::getRuleIndex() const {
  return WunschParser::RuleVarDef;
}

void WunschParser::VarDefContext::copyFrom(VarDefContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ImmediateVarDefContext ------------------------------------------------------------------

tree::TerminalNode* WunschParser::ImmediateVarDefContext::ID() {
  return getToken(WunschParser::ID, 0);
}

WunschParser::ExprContext* WunschParser::ImmediateVarDefContext::expr() {
  return getRuleContext<WunschParser::ExprContext>(0);
}

WunschParser::ImmediateVarDefContext::ImmediateVarDefContext(VarDefContext *ctx) { copyFrom(ctx); }

void WunschParser::ImmediateVarDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImmediateVarDef(this);
}
void WunschParser::ImmediateVarDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImmediateVarDef(this);
}

antlrcpp::Any WunschParser::ImmediateVarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitImmediateVarDef(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PlainVarDefContext ------------------------------------------------------------------

tree::TerminalNode* WunschParser::PlainVarDefContext::ID() {
  return getToken(WunschParser::ID, 0);
}

WunschParser::PlainVarDefContext::PlainVarDefContext(VarDefContext *ctx) { copyFrom(ctx); }

void WunschParser::PlainVarDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPlainVarDef(this);
}
void WunschParser::PlainVarDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPlainVarDef(this);
}

antlrcpp::Any WunschParser::PlainVarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitPlainVarDef(this);
  else
    return visitor->visitChildren(this);
}
WunschParser::VarDefContext* WunschParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 22, WunschParser::RuleVarDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(203);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<VarDefContext *>(_tracker.createInstance<WunschParser::ImmediateVarDefContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(197);
      match(WunschParser::T__30);
      setState(198);
      match(WunschParser::ID);
      setState(199);
      match(WunschParser::T__5);
      setState(200);
      expr(0);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<VarDefContext *>(_tracker.createInstance<WunschParser::PlainVarDefContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(201);
      match(WunschParser::T__30);
      setState(202);
      match(WunschParser::ID);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

WunschParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t WunschParser::AssignmentContext::getRuleIndex() const {
  return WunschParser::RuleAssignment;
}

void WunschParser::AssignmentContext::copyFrom(AssignmentContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprAssignContext ------------------------------------------------------------------

std::vector<WunschParser::ExprContext *> WunschParser::ExprAssignContext::expr() {
  return getRuleContexts<WunschParser::ExprContext>();
}

WunschParser::ExprContext* WunschParser::ExprAssignContext::expr(size_t i) {
  return getRuleContext<WunschParser::ExprContext>(i);
}

WunschParser::ExprAssignContext::ExprAssignContext(AssignmentContext *ctx) { copyFrom(ctx); }

void WunschParser::ExprAssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprAssign(this);
}
void WunschParser::ExprAssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprAssign(this);
}

antlrcpp::Any WunschParser::ExprAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitExprAssign(this);
  else
    return visitor->visitChildren(this);
}
WunschParser::AssignmentContext* WunschParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 24, WunschParser::RuleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<AssignmentContext *>(_tracker.createInstance<WunschParser::ExprAssignContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(205);
    expr(0);
    setState(206);
    match(WunschParser::T__5);
    setState(207);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefContext ------------------------------------------------------------------

WunschParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t WunschParser::FuncDefContext::getRuleIndex() const {
  return WunschParser::RuleFuncDef;
}

void WunschParser::FuncDefContext::copyFrom(FuncDefContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ArrTailFuncContext ------------------------------------------------------------------

tree::TerminalNode* WunschParser::ArrTailFuncContext::ID() {
  return getToken(WunschParser::ID, 0);
}

WunschParser::StmtBlockContext* WunschParser::ArrTailFuncContext::stmtBlock() {
  return getRuleContext<WunschParser::StmtBlockContext>(0);
}

std::vector<WunschParser::IdListContext *> WunschParser::ArrTailFuncContext::idList() {
  return getRuleContexts<WunschParser::IdListContext>();
}

WunschParser::IdListContext* WunschParser::ArrTailFuncContext::idList(size_t i) {
  return getRuleContext<WunschParser::IdListContext>(i);
}

WunschParser::ArrTailFuncContext::ArrTailFuncContext(FuncDefContext *ctx) { copyFrom(ctx); }

void WunschParser::ArrTailFuncContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrTailFunc(this);
}
void WunschParser::ArrTailFuncContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrTailFunc(this);
}

antlrcpp::Any WunschParser::ArrTailFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitArrTailFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FixedFuncContext ------------------------------------------------------------------

std::vector<WunschParser::IdListContext *> WunschParser::FixedFuncContext::idList() {
  return getRuleContexts<WunschParser::IdListContext>();
}

WunschParser::IdListContext* WunschParser::FixedFuncContext::idList(size_t i) {
  return getRuleContext<WunschParser::IdListContext>(i);
}

WunschParser::StmtBlockContext* WunschParser::FixedFuncContext::stmtBlock() {
  return getRuleContext<WunschParser::StmtBlockContext>(0);
}

WunschParser::FixedFuncContext::FixedFuncContext(FuncDefContext *ctx) { copyFrom(ctx); }

void WunschParser::FixedFuncContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFixedFunc(this);
}
void WunschParser::FixedFuncContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFixedFunc(this);
}

antlrcpp::Any WunschParser::FixedFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitFixedFunc(this);
  else
    return visitor->visitChildren(this);
}
WunschParser::FuncDefContext* WunschParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 26, WunschParser::RuleFuncDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(239);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<FuncDefContext *>(_tracker.createInstance<WunschParser::FixedFuncContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(209);
      match(WunschParser::T__1);
      setState(210);
      idList();
      setState(211);
      match(WunschParser::T__2);
      setState(216);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == WunschParser::T__7) {
        setState(212);
        match(WunschParser::T__7);
        setState(213);
        dynamic_cast<FixedFuncContext *>(_localctx)->cap = idList();
        setState(214);
        match(WunschParser::T__8);
      }
      setState(218);
      match(WunschParser::T__31);
      setState(219);
      stmtBlock();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<FuncDefContext *>(_tracker.createInstance<WunschParser::ArrTailFuncContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(221);
      match(WunschParser::T__1);
      setState(225);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == WunschParser::T__25

      || _la == WunschParser::ID) {
        setState(222);
        dynamic_cast<ArrTailFuncContext *>(_localctx)->param = idList();
        setState(223);
        match(WunschParser::T__25);
      }
      setState(227);
      match(WunschParser::T__7);
      setState(228);
      match(WunschParser::ID);
      setState(229);
      match(WunschParser::T__8);
      setState(230);
      match(WunschParser::T__2);
      setState(235);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == WunschParser::T__7) {
        setState(231);
        match(WunschParser::T__7);
        setState(232);
        dynamic_cast<ArrTailFuncContext *>(_localctx)->cap = idList();
        setState(233);
        match(WunschParser::T__8);
      }
      setState(237);
      match(WunschParser::T__31);
      setState(238);
      stmtBlock();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdListContext ------------------------------------------------------------------

WunschParser::IdListContext::IdListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> WunschParser::IdListContext::ID() {
  return getTokens(WunschParser::ID);
}

tree::TerminalNode* WunschParser::IdListContext::ID(size_t i) {
  return getToken(WunschParser::ID, i);
}


size_t WunschParser::IdListContext::getRuleIndex() const {
  return WunschParser::RuleIdList;
}

void WunschParser::IdListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdList(this);
}

void WunschParser::IdListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdList(this);
}


antlrcpp::Any WunschParser::IdListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitIdList(this);
  else
    return visitor->visitChildren(this);
}

WunschParser::IdListContext* WunschParser::idList() {
  IdListContext *_localctx = _tracker.createInstance<IdListContext>(_ctx, getState());
  enterRule(_localctx, 28, WunschParser::RuleIdList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(250);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case WunschParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(241);
        match(WunschParser::ID);
        setState(246);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(242);
            match(WunschParser::T__25);
            setState(243);
            match(WunschParser::ID); 
          }
          setState(248);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
        }
        break;
      }

      case WunschParser::T__2:
      case WunschParser::T__8:
      case WunschParser::T__25: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtBlockContext ------------------------------------------------------------------

WunschParser::StmtBlockContext::StmtBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<WunschParser::StmtContext *> WunschParser::StmtBlockContext::stmt() {
  return getRuleContexts<WunschParser::StmtContext>();
}

WunschParser::StmtContext* WunschParser::StmtBlockContext::stmt(size_t i) {
  return getRuleContext<WunschParser::StmtContext>(i);
}


size_t WunschParser::StmtBlockContext::getRuleIndex() const {
  return WunschParser::RuleStmtBlock;
}

void WunschParser::StmtBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtBlock(this);
}

void WunschParser::StmtBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtBlock(this);
}


antlrcpp::Any WunschParser::StmtBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitStmtBlock(this);
  else
    return visitor->visitChildren(this);
}

WunschParser::StmtBlockContext* WunschParser::stmtBlock() {
  StmtBlockContext *_localctx = _tracker.createInstance<StmtBlockContext>(_ctx, getState());
  enterRule(_localctx, 30, WunschParser::RuleStmtBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(252);
    match(WunschParser::T__26);
    setState(256);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WunschParser::T__1)
      | (1ULL << WunschParser::T__3)
      | (1ULL << WunschParser::T__7)
      | (1ULL << WunschParser::T__9)
      | (1ULL << WunschParser::T__10)
      | (1ULL << WunschParser::T__11)
      | (1ULL << WunschParser::T__12)
      | (1ULL << WunschParser::T__26)
      | (1ULL << WunschParser::T__29)
      | (1ULL << WunschParser::T__30)
      | (1ULL << WunschParser::T__32)
      | (1ULL << WunschParser::T__34)
      | (1ULL << WunschParser::T__35)
      | (1ULL << WunschParser::T__37)
      | (1ULL << WunschParser::DEC_INT)
      | (1ULL << WunschParser::OCT_INT)
      | (1ULL << WunschParser::HEX_INT)
      | (1ULL << WunschParser::FLOAT)
      | (1ULL << WunschParser::BOOLEANLIT)
      | (1ULL << WunschParser::STRING)
      | (1ULL << WunschParser::THIS)
      | (1ULL << WunschParser::ID))) != 0)) {
      setState(253);
      stmt();
      setState(258);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(259);
    match(WunschParser::T__28);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprListContext ------------------------------------------------------------------

WunschParser::ExprListContext::ExprListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<WunschParser::ExprContext *> WunschParser::ExprListContext::expr() {
  return getRuleContexts<WunschParser::ExprContext>();
}

WunschParser::ExprContext* WunschParser::ExprListContext::expr(size_t i) {
  return getRuleContext<WunschParser::ExprContext>(i);
}


size_t WunschParser::ExprListContext::getRuleIndex() const {
  return WunschParser::RuleExprList;
}

void WunschParser::ExprListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprList(this);
}

void WunschParser::ExprListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprList(this);
}


antlrcpp::Any WunschParser::ExprListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitExprList(this);
  else
    return visitor->visitChildren(this);
}

WunschParser::ExprListContext* WunschParser::exprList() {
  ExprListContext *_localctx = _tracker.createInstance<ExprListContext>(_ctx, getState());
  enterRule(_localctx, 32, WunschParser::RuleExprList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(270);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case WunschParser::T__1:
      case WunschParser::T__3:
      case WunschParser::T__7:
      case WunschParser::T__9:
      case WunschParser::T__10:
      case WunschParser::T__11:
      case WunschParser::T__12:
      case WunschParser::T__26:
      case WunschParser::T__29:
      case WunschParser::DEC_INT:
      case WunschParser::OCT_INT:
      case WunschParser::HEX_INT:
      case WunschParser::FLOAT:
      case WunschParser::BOOLEANLIT:
      case WunschParser::STRING:
      case WunschParser::THIS:
      case WunschParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(261);
        expr(0);
        setState(266);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == WunschParser::T__25) {
          setState(262);
          match(WunschParser::T__25);
          setState(263);
          expr(0);
          setState(268);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case WunschParser::T__2: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondStmtContext ------------------------------------------------------------------

WunschParser::CondStmtContext::CondStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WunschParser::ExprContext* WunschParser::CondStmtContext::expr() {
  return getRuleContext<WunschParser::ExprContext>(0);
}

std::vector<WunschParser::StmtBlockContext *> WunschParser::CondStmtContext::stmtBlock() {
  return getRuleContexts<WunschParser::StmtBlockContext>();
}

WunschParser::StmtBlockContext* WunschParser::CondStmtContext::stmtBlock(size_t i) {
  return getRuleContext<WunschParser::StmtBlockContext>(i);
}


size_t WunschParser::CondStmtContext::getRuleIndex() const {
  return WunschParser::RuleCondStmt;
}

void WunschParser::CondStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCondStmt(this);
}

void WunschParser::CondStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCondStmt(this);
}


antlrcpp::Any WunschParser::CondStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitCondStmt(this);
  else
    return visitor->visitChildren(this);
}

WunschParser::CondStmtContext* WunschParser::condStmt() {
  CondStmtContext *_localctx = _tracker.createInstance<CondStmtContext>(_ctx, getState());
  enterRule(_localctx, 34, WunschParser::RuleCondStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(272);
    match(WunschParser::T__32);
    setState(273);
    expr(0);
    setState(274);
    stmtBlock();
    setState(277);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == WunschParser::T__33) {
      setState(275);
      match(WunschParser::T__33);
      setState(276);
      stmtBlock();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStmtContext ------------------------------------------------------------------

WunschParser::WhileStmtContext::WhileStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WunschParser::ExprContext* WunschParser::WhileStmtContext::expr() {
  return getRuleContext<WunschParser::ExprContext>(0);
}

WunschParser::StmtBlockContext* WunschParser::WhileStmtContext::stmtBlock() {
  return getRuleContext<WunschParser::StmtBlockContext>(0);
}


size_t WunschParser::WhileStmtContext::getRuleIndex() const {
  return WunschParser::RuleWhileStmt;
}

void WunschParser::WhileStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStmt(this);
}

void WunschParser::WhileStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStmt(this);
}


antlrcpp::Any WunschParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}

WunschParser::WhileStmtContext* WunschParser::whileStmt() {
  WhileStmtContext *_localctx = _tracker.createInstance<WhileStmtContext>(_ctx, getState());
  enterRule(_localctx, 36, WunschParser::RuleWhileStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(279);
    match(WunschParser::T__34);
    setState(280);
    expr(0);
    setState(281);
    stmtBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStmtContext ------------------------------------------------------------------

WunschParser::ForStmtContext::ForStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WunschParser::ForStmtContext::ID() {
  return getToken(WunschParser::ID, 0);
}

WunschParser::ExprContext* WunschParser::ForStmtContext::expr() {
  return getRuleContext<WunschParser::ExprContext>(0);
}

WunschParser::StmtBlockContext* WunschParser::ForStmtContext::stmtBlock() {
  return getRuleContext<WunschParser::StmtBlockContext>(0);
}


size_t WunschParser::ForStmtContext::getRuleIndex() const {
  return WunschParser::RuleForStmt;
}

void WunschParser::ForStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStmt(this);
}

void WunschParser::ForStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStmt(this);
}


antlrcpp::Any WunschParser::ForStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitForStmt(this);
  else
    return visitor->visitChildren(this);
}

WunschParser::ForStmtContext* WunschParser::forStmt() {
  ForStmtContext *_localctx = _tracker.createInstance<ForStmtContext>(_ctx, getState());
  enterRule(_localctx, 38, WunschParser::RuleForStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(283);
    match(WunschParser::T__35);
    setState(284);
    match(WunschParser::ID);
    setState(285);
    match(WunschParser::T__36);
    setState(286);
    expr(0);
    setState(287);
    stmtBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStmtContext ------------------------------------------------------------------

WunschParser::ReturnStmtContext::ReturnStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WunschParser::ExprContext* WunschParser::ReturnStmtContext::expr() {
  return getRuleContext<WunschParser::ExprContext>(0);
}


size_t WunschParser::ReturnStmtContext::getRuleIndex() const {
  return WunschParser::RuleReturnStmt;
}

void WunschParser::ReturnStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStmt(this);
}

void WunschParser::ReturnStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WunschListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStmt(this);
}


antlrcpp::Any WunschParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WunschVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}

WunschParser::ReturnStmtContext* WunschParser::returnStmt() {
  ReturnStmtContext *_localctx = _tracker.createInstance<ReturnStmtContext>(_ctx, getState());
  enterRule(_localctx, 40, WunschParser::RuleReturnStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(289);
    match(WunschParser::T__37);
    setState(290);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool WunschParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool WunschParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 9);
    case 1: return precpred(_ctx, 8);
    case 2: return precpred(_ctx, 7);
    case 3: return precpred(_ctx, 6);
    case 4: return precpred(_ctx, 5);
    case 5: return precpred(_ctx, 4);
    case 6: return precpred(_ctx, 3);
    case 7: return precpred(_ctx, 2);
    case 8: return precpred(_ctx, 1);
    case 9: return precpred(_ctx, 15);
    case 10: return precpred(_ctx, 14);
    case 11: return precpred(_ctx, 13);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> WunschParser::_decisionToDFA;
atn::PredictionContextCache WunschParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN WunschParser::_atn;
std::vector<uint16_t> WunschParser::_serializedATN;

std::vector<std::string> WunschParser::_ruleNames = {
  "program", "stmt", "expr", "literal", "integerLiteral", "floatLiteral", 
  "boolLiteral", "stringLiteral", "listLiteral", "dictLiteral", "nilLiteral", 
  "varDef", "assignment", "funcDef", "idList", "stmtBlock", "exprList", 
  "condStmt", "whileStmt", "forStmt", "returnStmt"
};

std::vector<std::string> WunschParser::_literalNames = {
  "", "';'", "'('", "')'", "'<'", "'>'", "'='", "'.'", "'['", "']'", "'!'", 
  "'~'", "'+'", "'-'", "'*'", "'/'", "'%'", "'<='", "'>='", "'=='", "'!='", 
  "'&'", "'^'", "'|'", "'&&'", "'||'", "','", "'{'", "':'", "'}'", "'nil'", 
  "'var'", "'=>'", "'if'", "'else'", "'while'", "'for'", "'in'", "'return'", 
  "", "", "", "", "", "", "", "'this'"
};

std::vector<std::string> WunschParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "DEC_INT", "OCT_INT", "HEX_INT", "FLOAT", "BOOLEANLIT", "STRING", 
  "ESC", "THIS", "ID", "COMMENT", "WS"
};

dfa::Vocabulary WunschParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> WunschParser::_tokenNames;

WunschParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x33, 0x127, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x3, 0x2, 0x7, 0x2, 0x2e, 0xa, 0x2, 
    0xc, 0x2, 0xe, 0x2, 0x31, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x42, 0xa, 0x3, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x6, 0x4, 0x56, 0xa, 0x4, 0xd, 
    0x4, 0xe, 0x4, 0x57, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x62, 0xa, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x8c, 0xa, 0x4, 0xc, 0x4, 
    0xe, 0x4, 0x8f, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x98, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x5, 0x6, 0x9d, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x9, 0x6, 0x9, 0xa4, 0xa, 0x9, 0xd, 0x9, 0xe, 0x9, 0xa5, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xac, 0xa, 0xa, 0xc, 0xa, 
    0xe, 0xa, 0xaf, 0xb, 0xa, 0x5, 0xa, 0xb1, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x7, 0xb, 0xbd, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xc0, 0xb, 0xb, 
    0x5, 0xb, 0xc2, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xce, 
    0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xdb, 0xa, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x5, 0xf, 0xe4, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xee, 0xa, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x5, 0xf, 0xf2, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x7, 0x10, 0xf7, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0xfa, 0xb, 0x10, 
    0x3, 0x10, 0x5, 0x10, 0xfd, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 
    0x101, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x104, 0xb, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x10b, 0xa, 0x12, 
    0xc, 0x12, 0xe, 0x12, 0x10e, 0xb, 0x12, 0x3, 0x12, 0x5, 0x12, 0x111, 
    0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 
    0x13, 0x118, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x2, 0x3, 0x6, 0x17, 0x2, 0x4, 
    0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2, 0x6, 0x3, 0x2, 0xe, 0xf, 0x3, 
    0x2, 0x10, 0x12, 0x4, 0x2, 0x6, 0x7, 0x13, 0x14, 0x3, 0x2, 0x15, 0x16, 
    0x2, 0x146, 0x2, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x4, 0x41, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x61, 0x3, 0x2, 0x2, 0x2, 0x8, 0x97, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x9c, 0x3, 0x2, 0x2, 0x2, 0xc, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xe, 0xa0, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x12, 0xa7, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0xb4, 0x3, 0x2, 0x2, 0x2, 0x16, 0xc5, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xcf, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0xf1, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xfc, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x22, 0x110, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x112, 0x3, 0x2, 0x2, 0x2, 0x26, 0x119, 0x3, 0x2, 0x2, 0x2, 0x28, 0x11d, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x123, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2e, 0x5, 
    0x4, 0x3, 0x2, 0x2d, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0x2f, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 0x3, 0x2, 0x2, 
    0x2, 0x30, 0x3, 0x3, 0x2, 0x2, 0x2, 0x31, 0x2f, 0x3, 0x2, 0x2, 0x2, 
    0x32, 0x33, 0x5, 0x6, 0x4, 0x2, 0x33, 0x34, 0x7, 0x3, 0x2, 0x2, 0x34, 
    0x42, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x5, 0x18, 0xd, 0x2, 0x36, 0x37, 
    0x7, 0x3, 0x2, 0x2, 0x37, 0x42, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x5, 
    0x1a, 0xe, 0x2, 0x39, 0x3a, 0x7, 0x3, 0x2, 0x2, 0x3a, 0x42, 0x3, 0x2, 
    0x2, 0x2, 0x3b, 0x42, 0x5, 0x24, 0x13, 0x2, 0x3c, 0x42, 0x5, 0x26, 0x14, 
    0x2, 0x3d, 0x42, 0x5, 0x28, 0x15, 0x2, 0x3e, 0x3f, 0x5, 0x2a, 0x16, 
    0x2, 0x3f, 0x40, 0x7, 0x3, 0x2, 0x2, 0x40, 0x42, 0x3, 0x2, 0x2, 0x2, 
    0x41, 0x32, 0x3, 0x2, 0x2, 0x2, 0x41, 0x35, 0x3, 0x2, 0x2, 0x2, 0x41, 
    0x38, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3c, 
    0x3, 0x2, 0x2, 0x2, 0x41, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3e, 0x3, 
    0x2, 0x2, 0x2, 0x42, 0x5, 0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x8, 0x4, 
    0x1, 0x2, 0x44, 0x62, 0x5, 0x8, 0x5, 0x2, 0x45, 0x62, 0x5, 0x1c, 0xf, 
    0x2, 0x46, 0x62, 0x7, 0x30, 0x2, 0x2, 0x47, 0x62, 0x7, 0x31, 0x2, 0x2, 
    0x48, 0x49, 0x7, 0x4, 0x2, 0x2, 0x49, 0x4a, 0x5, 0x6, 0x4, 0x2, 0x4a, 
    0x4b, 0x7, 0x5, 0x2, 0x2, 0x4b, 0x62, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 
    0x7, 0x6, 0x2, 0x2, 0x4d, 0x4e, 0x5, 0x6, 0x4, 0x2, 0x4e, 0x4f, 0x7, 
    0x7, 0x2, 0x2, 0x4f, 0x62, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0x7, 0x6, 
    0x2, 0x2, 0x51, 0x55, 0x5, 0x6, 0x4, 0x2, 0x52, 0x53, 0x7, 0x31, 0x2, 
    0x2, 0x53, 0x54, 0x7, 0x8, 0x2, 0x2, 0x54, 0x56, 0x5, 0x6, 0x4, 0x2, 
    0x55, 0x52, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0x3, 0x2, 0x2, 0x2, 0x57, 
    0x55, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 
    0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x7, 0x7, 0x2, 0x2, 0x5a, 0x62, 0x3, 
    0x2, 0x2, 0x2, 0x5b, 0x5c, 0x7, 0xc, 0x2, 0x2, 0x5c, 0x62, 0x5, 0x6, 
    0x4, 0xe, 0x5d, 0x5e, 0x7, 0xd, 0x2, 0x2, 0x5e, 0x62, 0x5, 0x6, 0x4, 
    0xd, 0x5f, 0x60, 0x9, 0x2, 0x2, 0x2, 0x60, 0x62, 0x5, 0x6, 0x4, 0xc, 
    0x61, 0x43, 0x3, 0x2, 0x2, 0x2, 0x61, 0x45, 0x3, 0x2, 0x2, 0x2, 0x61, 
    0x46, 0x3, 0x2, 0x2, 0x2, 0x61, 0x47, 0x3, 0x2, 0x2, 0x2, 0x61, 0x48, 
    0x3, 0x2, 0x2, 0x2, 0x61, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x61, 0x50, 0x3, 
    0x2, 0x2, 0x2, 0x61, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x61, 0x5d, 0x3, 0x2, 
    0x2, 0x2, 0x61, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x62, 0x8d, 0x3, 0x2, 0x2, 
    0x2, 0x63, 0x64, 0xc, 0xb, 0x2, 0x2, 0x64, 0x65, 0x9, 0x3, 0x2, 0x2, 
    0x65, 0x8c, 0x5, 0x6, 0x4, 0xc, 0x66, 0x67, 0xc, 0xa, 0x2, 0x2, 0x67, 
    0x68, 0x9, 0x2, 0x2, 0x2, 0x68, 0x8c, 0x5, 0x6, 0x4, 0xb, 0x69, 0x6a, 
    0xc, 0x9, 0x2, 0x2, 0x6a, 0x6b, 0x9, 0x4, 0x2, 0x2, 0x6b, 0x8c, 0x5, 
    0x6, 0x4, 0xa, 0x6c, 0x6d, 0xc, 0x8, 0x2, 0x2, 0x6d, 0x6e, 0x9, 0x5, 
    0x2, 0x2, 0x6e, 0x8c, 0x5, 0x6, 0x4, 0x9, 0x6f, 0x70, 0xc, 0x7, 0x2, 
    0x2, 0x70, 0x71, 0x7, 0x17, 0x2, 0x2, 0x71, 0x8c, 0x5, 0x6, 0x4, 0x8, 
    0x72, 0x73, 0xc, 0x6, 0x2, 0x2, 0x73, 0x74, 0x7, 0x18, 0x2, 0x2, 0x74, 
    0x8c, 0x5, 0x6, 0x4, 0x7, 0x75, 0x76, 0xc, 0x5, 0x2, 0x2, 0x76, 0x77, 
    0x7, 0x19, 0x2, 0x2, 0x77, 0x8c, 0x5, 0x6, 0x4, 0x6, 0x78, 0x79, 0xc, 
    0x4, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x1a, 0x2, 0x2, 0x7a, 0x8c, 0x5, 0x6, 
    0x4, 0x5, 0x7b, 0x7c, 0xc, 0x3, 0x2, 0x2, 0x7c, 0x7d, 0x7, 0x1b, 0x2, 
    0x2, 0x7d, 0x8c, 0x5, 0x6, 0x4, 0x4, 0x7e, 0x7f, 0xc, 0x11, 0x2, 0x2, 
    0x7f, 0x80, 0x7, 0x9, 0x2, 0x2, 0x80, 0x8c, 0x7, 0x31, 0x2, 0x2, 0x81, 
    0x82, 0xc, 0x10, 0x2, 0x2, 0x82, 0x83, 0x7, 0xa, 0x2, 0x2, 0x83, 0x84, 
    0x5, 0x6, 0x4, 0x2, 0x84, 0x85, 0x7, 0xb, 0x2, 0x2, 0x85, 0x8c, 0x3, 
    0x2, 0x2, 0x2, 0x86, 0x87, 0xc, 0xf, 0x2, 0x2, 0x87, 0x88, 0x7, 0x4, 
    0x2, 0x2, 0x88, 0x89, 0x5, 0x22, 0x12, 0x2, 0x89, 0x8a, 0x7, 0x5, 0x2, 
    0x2, 0x8a, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x63, 0x3, 0x2, 0x2, 0x2, 
    0x8b, 0x66, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x69, 0x3, 0x2, 0x2, 0x2, 0x8b, 
    0x6c, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x72, 
    0x3, 0x2, 0x2, 0x2, 0x8b, 0x75, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x78, 0x3, 
    0x2, 0x2, 0x2, 0x8b, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x7e, 0x3, 0x2, 
    0x2, 0x2, 0x8b, 0x81, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x86, 0x3, 0x2, 0x2, 
    0x2, 0x8c, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8b, 0x3, 0x2, 0x2, 0x2, 
    0x8d, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x7, 0x3, 0x2, 0x2, 0x2, 0x8f, 
    0x8d, 0x3, 0x2, 0x2, 0x2, 0x90, 0x98, 0x5, 0xa, 0x6, 0x2, 0x91, 0x98, 
    0x5, 0xc, 0x7, 0x2, 0x92, 0x98, 0x5, 0xe, 0x8, 0x2, 0x93, 0x98, 0x5, 
    0x10, 0x9, 0x2, 0x94, 0x98, 0x5, 0x12, 0xa, 0x2, 0x95, 0x98, 0x5, 0x14, 
    0xb, 0x2, 0x96, 0x98, 0x5, 0x16, 0xc, 0x2, 0x97, 0x90, 0x3, 0x2, 0x2, 
    0x2, 0x97, 0x91, 0x3, 0x2, 0x2, 0x2, 0x97, 0x92, 0x3, 0x2, 0x2, 0x2, 
    0x97, 0x93, 0x3, 0x2, 0x2, 0x2, 0x97, 0x94, 0x3, 0x2, 0x2, 0x2, 0x97, 
    0x95, 0x3, 0x2, 0x2, 0x2, 0x97, 0x96, 0x3, 0x2, 0x2, 0x2, 0x98, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x99, 0x9d, 0x7, 0x29, 0x2, 0x2, 0x9a, 0x9d, 0x7, 
    0x2a, 0x2, 0x2, 0x9b, 0x9d, 0x7, 0x2b, 0x2, 0x2, 0x9c, 0x99, 0x3, 0x2, 
    0x2, 0x2, 0x9c, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9b, 0x3, 0x2, 0x2, 
    0x2, 0x9d, 0xb, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0x2c, 0x2, 0x2, 
    0x9f, 0xd, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0x7, 0x2d, 0x2, 0x2, 0xa1, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa4, 0x7, 0x2e, 0x2, 0x2, 0xa3, 0xa2, 
    0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa3, 0x3, 
    0x2, 0x2, 0x2, 0xa5, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x11, 0x3, 0x2, 
    0x2, 0x2, 0xa7, 0xb0, 0x7, 0xa, 0x2, 0x2, 0xa8, 0xad, 0x5, 0x6, 0x4, 
    0x2, 0xa9, 0xaa, 0x7, 0x1c, 0x2, 0x2, 0xaa, 0xac, 0x5, 0x6, 0x4, 0x2, 
    0xab, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xac, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xad, 
    0xab, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x3, 0x2, 0x2, 0x2, 0xae, 0xb1, 
    0x3, 0x2, 0x2, 0x2, 0xaf, 0xad, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xa8, 0x3, 
    0x2, 0x2, 0x2, 0xb0, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x3, 0x2, 
    0x2, 0x2, 0xb2, 0xb3, 0x7, 0xb, 0x2, 0x2, 0xb3, 0x13, 0x3, 0x2, 0x2, 
    0x2, 0xb4, 0xc1, 0x7, 0x1d, 0x2, 0x2, 0xb5, 0xb6, 0x7, 0x31, 0x2, 0x2, 
    0xb6, 0xb7, 0x7, 0x1e, 0x2, 0x2, 0xb7, 0xbe, 0x5, 0x6, 0x4, 0x2, 0xb8, 
    0xb9, 0x7, 0x1c, 0x2, 0x2, 0xb9, 0xba, 0x7, 0x31, 0x2, 0x2, 0xba, 0xbb, 
    0x7, 0x1e, 0x2, 0x2, 0xbb, 0xbd, 0x5, 0x6, 0x4, 0x2, 0xbc, 0xb8, 0x3, 
    0x2, 0x2, 0x2, 0xbd, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbc, 0x3, 0x2, 
    0x2, 0x2, 0xbe, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc2, 0x3, 0x2, 0x2, 
    0x2, 0xc0, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xb5, 0x3, 0x2, 0x2, 0x2, 
    0xc1, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc3, 
    0xc4, 0x7, 0x1f, 0x2, 0x2, 0xc4, 0x15, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc6, 
    0x7, 0x20, 0x2, 0x2, 0xc6, 0x17, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 0x7, 
    0x21, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0x31, 0x2, 0x2, 0xc9, 0xca, 0x7, 0x8, 
    0x2, 0x2, 0xca, 0xce, 0x5, 0x6, 0x4, 0x2, 0xcb, 0xcc, 0x7, 0x21, 0x2, 
    0x2, 0xcc, 0xce, 0x7, 0x31, 0x2, 0x2, 0xcd, 0xc7, 0x3, 0x2, 0x2, 0x2, 
    0xcd, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xce, 0x19, 0x3, 0x2, 0x2, 0x2, 0xcf, 
    0xd0, 0x5, 0x6, 0x4, 0x2, 0xd0, 0xd1, 0x7, 0x8, 0x2, 0x2, 0xd1, 0xd2, 
    0x5, 0x6, 0x4, 0x2, 0xd2, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x7, 
    0x4, 0x2, 0x2, 0xd4, 0xd5, 0x5, 0x1e, 0x10, 0x2, 0xd5, 0xda, 0x7, 0x5, 
    0x2, 0x2, 0xd6, 0xd7, 0x7, 0xa, 0x2, 0x2, 0xd7, 0xd8, 0x5, 0x1e, 0x10, 
    0x2, 0xd8, 0xd9, 0x7, 0xb, 0x2, 0x2, 0xd9, 0xdb, 0x3, 0x2, 0x2, 0x2, 
    0xda, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdb, 
    0xdc, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0x22, 0x2, 0x2, 0xdd, 0xde, 
    0x5, 0x20, 0x11, 0x2, 0xde, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe3, 0x7, 
    0x4, 0x2, 0x2, 0xe0, 0xe1, 0x5, 0x1e, 0x10, 0x2, 0xe1, 0xe2, 0x7, 0x1c, 
    0x2, 0x2, 0xe2, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe0, 0x3, 0x2, 0x2, 
    0x2, 0xe3, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe5, 0x3, 0x2, 0x2, 0x2, 
    0xe5, 0xe6, 0x7, 0xa, 0x2, 0x2, 0xe6, 0xe7, 0x7, 0x31, 0x2, 0x2, 0xe7, 
    0xe8, 0x7, 0xb, 0x2, 0x2, 0xe8, 0xed, 0x7, 0x5, 0x2, 0x2, 0xe9, 0xea, 
    0x7, 0xa, 0x2, 0x2, 0xea, 0xeb, 0x5, 0x1e, 0x10, 0x2, 0xeb, 0xec, 0x7, 
    0xb, 0x2, 0x2, 0xec, 0xee, 0x3, 0x2, 0x2, 0x2, 0xed, 0xe9, 0x3, 0x2, 
    0x2, 0x2, 0xed, 0xee, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x3, 0x2, 0x2, 
    0x2, 0xef, 0xf0, 0x7, 0x22, 0x2, 0x2, 0xf0, 0xf2, 0x5, 0x20, 0x11, 0x2, 
    0xf1, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xf2, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf8, 0x7, 0x31, 0x2, 0x2, 0xf4, 0xf5, 
    0x7, 0x1c, 0x2, 0x2, 0xf5, 0xf7, 0x7, 0x31, 0x2, 0x2, 0xf6, 0xf4, 0x3, 
    0x2, 0x2, 0x2, 0xf7, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf6, 0x3, 0x2, 
    0x2, 0x2, 0xf8, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfd, 0x3, 0x2, 0x2, 
    0x2, 0xfa, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfd, 0x3, 0x2, 0x2, 0x2, 
    0xfc, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfd, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0xfe, 0x102, 0x7, 0x1d, 0x2, 0x2, 0xff, 0x101, 
    0x5, 0x4, 0x3, 0x2, 0x100, 0xff, 0x3, 0x2, 0x2, 0x2, 0x101, 0x104, 0x3, 
    0x2, 0x2, 0x2, 0x102, 0x100, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0x3, 
    0x2, 0x2, 0x2, 0x103, 0x105, 0x3, 0x2, 0x2, 0x2, 0x104, 0x102, 0x3, 
    0x2, 0x2, 0x2, 0x105, 0x106, 0x7, 0x1f, 0x2, 0x2, 0x106, 0x21, 0x3, 
    0x2, 0x2, 0x2, 0x107, 0x10c, 0x5, 0x6, 0x4, 0x2, 0x108, 0x109, 0x7, 
    0x1c, 0x2, 0x2, 0x109, 0x10b, 0x5, 0x6, 0x4, 0x2, 0x10a, 0x108, 0x3, 
    0x2, 0x2, 0x2, 0x10b, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10a, 0x3, 
    0x2, 0x2, 0x2, 0x10c, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x111, 0x3, 
    0x2, 0x2, 0x2, 0x10e, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x111, 0x3, 
    0x2, 0x2, 0x2, 0x110, 0x107, 0x3, 0x2, 0x2, 0x2, 0x110, 0x10f, 0x3, 
    0x2, 0x2, 0x2, 0x111, 0x23, 0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 0x7, 0x23, 
    0x2, 0x2, 0x113, 0x114, 0x5, 0x6, 0x4, 0x2, 0x114, 0x117, 0x5, 0x20, 
    0x11, 0x2, 0x115, 0x116, 0x7, 0x24, 0x2, 0x2, 0x116, 0x118, 0x5, 0x20, 
    0x11, 0x2, 0x117, 0x115, 0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x3, 0x2, 
    0x2, 0x2, 0x118, 0x25, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 0x7, 0x25, 
    0x2, 0x2, 0x11a, 0x11b, 0x5, 0x6, 0x4, 0x2, 0x11b, 0x11c, 0x5, 0x20, 
    0x11, 0x2, 0x11c, 0x27, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11e, 0x7, 0x26, 
    0x2, 0x2, 0x11e, 0x11f, 0x7, 0x31, 0x2, 0x2, 0x11f, 0x120, 0x7, 0x27, 
    0x2, 0x2, 0x120, 0x121, 0x5, 0x6, 0x4, 0x2, 0x121, 0x122, 0x5, 0x20, 
    0x11, 0x2, 0x122, 0x29, 0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 0x7, 0x28, 
    0x2, 0x2, 0x124, 0x125, 0x5, 0x6, 0x4, 0x2, 0x125, 0x2b, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x2f, 0x41, 0x57, 0x61, 0x8b, 0x8d, 0x97, 0x9c, 0xa5, 0xad, 
    0xb0, 0xbe, 0xc1, 0xcd, 0xda, 0xe3, 0xed, 0xf1, 0xf8, 0xfc, 0x102, 0x10c, 
    0x110, 0x117, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

WunschParser::Initializer WunschParser::_init;
