
// Generated from HullQuery.g4 by ANTLR 4.11.1


#include "HullQueryListener.h"

#include "HullQueryParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct HullQueryParserStaticData final {
  HullQueryParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  HullQueryParserStaticData(const HullQueryParserStaticData&) = delete;
  HullQueryParserStaticData(HullQueryParserStaticData&&) = delete;
  HullQueryParserStaticData& operator=(const HullQueryParserStaticData&) = delete;
  HullQueryParserStaticData& operator=(HullQueryParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag hullqueryParserOnceFlag;
HullQueryParserStaticData *hullqueryParserStaticData = nullptr;

void hullqueryParserInitialize() {
  assert(hullqueryParserStaticData == nullptr);
  auto staticData = std::make_unique<HullQueryParserStaticData>(
    std::vector<std::string>{
      "query", "expr", "func", "arglist", "decl", "var", "type"
    },
    std::vector<std::string>{
      "", "';'", "'='", "'.'", "'('", "')'", "','", "'['", "']'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "WS", "NL", "INT", "ID"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,12,66,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,1,0,
  	1,0,1,0,5,0,18,8,0,10,0,12,0,21,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,3,1,35,8,1,1,2,1,2,1,2,1,2,1,2,1,2,3,2,43,8,2,1,3,1,3,1,
  	3,5,3,48,8,3,10,3,12,3,51,9,3,3,3,53,8,3,1,4,1,4,1,4,1,4,1,4,3,4,60,8,
  	4,1,5,1,5,1,6,1,6,1,6,0,0,7,0,2,4,6,8,10,12,0,0,66,0,19,1,0,0,0,2,34,
  	1,0,0,0,4,36,1,0,0,0,6,52,1,0,0,0,8,54,1,0,0,0,10,61,1,0,0,0,12,63,1,
  	0,0,0,14,15,3,2,1,0,15,16,5,1,0,0,16,18,1,0,0,0,17,14,1,0,0,0,18,21,1,
  	0,0,0,19,17,1,0,0,0,19,20,1,0,0,0,20,22,1,0,0,0,21,19,1,0,0,0,22,23,5,
  	0,0,1,23,1,1,0,0,0,24,25,3,8,4,0,25,26,5,2,0,0,26,27,3,2,1,0,27,35,1,
  	0,0,0,28,35,3,10,5,0,29,35,3,4,2,0,30,31,3,10,5,0,31,32,5,3,0,0,32,33,
  	3,4,2,0,33,35,1,0,0,0,34,24,1,0,0,0,34,28,1,0,0,0,34,29,1,0,0,0,34,30,
  	1,0,0,0,35,3,1,0,0,0,36,37,5,12,0,0,37,38,5,4,0,0,38,39,3,6,3,0,39,42,
  	5,5,0,0,40,41,5,3,0,0,41,43,3,4,2,0,42,40,1,0,0,0,42,43,1,0,0,0,43,5,
  	1,0,0,0,44,49,3,2,1,0,45,46,5,6,0,0,46,48,3,2,1,0,47,45,1,0,0,0,48,51,
  	1,0,0,0,49,47,1,0,0,0,49,50,1,0,0,0,50,53,1,0,0,0,51,49,1,0,0,0,52,44,
  	1,0,0,0,52,53,1,0,0,0,53,7,1,0,0,0,54,55,3,12,6,0,55,59,5,12,0,0,56,57,
  	5,7,0,0,57,58,5,11,0,0,58,60,5,8,0,0,59,56,1,0,0,0,59,60,1,0,0,0,60,9,
  	1,0,0,0,61,62,5,12,0,0,62,11,1,0,0,0,63,64,5,12,0,0,64,13,1,0,0,0,6,19,
  	34,42,49,52,59
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  hullqueryParserStaticData = staticData.release();
}

}

HullQueryParser::HullQueryParser(TokenStream *input) : HullQueryParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

HullQueryParser::HullQueryParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  HullQueryParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *hullqueryParserStaticData->atn, hullqueryParserStaticData->decisionToDFA, hullqueryParserStaticData->sharedContextCache, options);
}

HullQueryParser::~HullQueryParser() {
  delete _interpreter;
}

const atn::ATN& HullQueryParser::getATN() const {
  return *hullqueryParserStaticData->atn;
}

std::string HullQueryParser::getGrammarFileName() const {
  return "HullQuery.g4";
}

const std::vector<std::string>& HullQueryParser::getRuleNames() const {
  return hullqueryParserStaticData->ruleNames;
}

const dfa::Vocabulary& HullQueryParser::getVocabulary() const {
  return hullqueryParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView HullQueryParser::getSerializedATN() const {
  return hullqueryParserStaticData->serializedATN;
}


//----------------- QueryContext ------------------------------------------------------------------

HullQueryParser::QueryContext::QueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* HullQueryParser::QueryContext::EOF() {
  return getToken(HullQueryParser::EOF, 0);
}

std::vector<HullQueryParser::ExprContext *> HullQueryParser::QueryContext::expr() {
  return getRuleContexts<HullQueryParser::ExprContext>();
}

HullQueryParser::ExprContext* HullQueryParser::QueryContext::expr(size_t i) {
  return getRuleContext<HullQueryParser::ExprContext>(i);
}


size_t HullQueryParser::QueryContext::getRuleIndex() const {
  return HullQueryParser::RuleQuery;
}

void HullQueryParser::QueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HullQueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuery(this);
}

void HullQueryParser::QueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HullQueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuery(this);
}

HullQueryParser::QueryContext* HullQueryParser::query() {
  QueryContext *_localctx = _tracker.createInstance<QueryContext>(_ctx, getState());
  enterRule(_localctx, 0, HullQueryParser::RuleQuery);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(19);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == HullQueryParser::ID) {
      setState(14);
      expr();
      setState(15);
      match(HullQueryParser::T__0);
      setState(21);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(22);
    match(HullQueryParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

HullQueryParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HullQueryParser::DeclContext* HullQueryParser::ExprContext::decl() {
  return getRuleContext<HullQueryParser::DeclContext>(0);
}

HullQueryParser::ExprContext* HullQueryParser::ExprContext::expr() {
  return getRuleContext<HullQueryParser::ExprContext>(0);
}

HullQueryParser::VarContext* HullQueryParser::ExprContext::var() {
  return getRuleContext<HullQueryParser::VarContext>(0);
}

HullQueryParser::FuncContext* HullQueryParser::ExprContext::func() {
  return getRuleContext<HullQueryParser::FuncContext>(0);
}


size_t HullQueryParser::ExprContext::getRuleIndex() const {
  return HullQueryParser::RuleExpr;
}

void HullQueryParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HullQueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void HullQueryParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HullQueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}

HullQueryParser::ExprContext* HullQueryParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 2, HullQueryParser::RuleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(34);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(24);
      decl();
      setState(25);
      match(HullQueryParser::T__1);
      setState(26);
      expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(28);
      var();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(29);
      func();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(30);
      var();
      setState(31);
      match(HullQueryParser::T__2);
      setState(32);
      func();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncContext ------------------------------------------------------------------

HullQueryParser::FuncContext::FuncContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* HullQueryParser::FuncContext::ID() {
  return getToken(HullQueryParser::ID, 0);
}

HullQueryParser::ArglistContext* HullQueryParser::FuncContext::arglist() {
  return getRuleContext<HullQueryParser::ArglistContext>(0);
}

HullQueryParser::FuncContext* HullQueryParser::FuncContext::func() {
  return getRuleContext<HullQueryParser::FuncContext>(0);
}


size_t HullQueryParser::FuncContext::getRuleIndex() const {
  return HullQueryParser::RuleFunc;
}

void HullQueryParser::FuncContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HullQueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc(this);
}

void HullQueryParser::FuncContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HullQueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc(this);
}

HullQueryParser::FuncContext* HullQueryParser::func() {
  FuncContext *_localctx = _tracker.createInstance<FuncContext>(_ctx, getState());
  enterRule(_localctx, 4, HullQueryParser::RuleFunc);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(36);
    match(HullQueryParser::ID);
    setState(37);
    match(HullQueryParser::T__3);
    setState(38);
    arglist();
    setState(39);
    match(HullQueryParser::T__4);
    setState(42);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == HullQueryParser::T__2) {
      setState(40);
      match(HullQueryParser::T__2);
      setState(41);
      func();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArglistContext ------------------------------------------------------------------

HullQueryParser::ArglistContext::ArglistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<HullQueryParser::ExprContext *> HullQueryParser::ArglistContext::expr() {
  return getRuleContexts<HullQueryParser::ExprContext>();
}

HullQueryParser::ExprContext* HullQueryParser::ArglistContext::expr(size_t i) {
  return getRuleContext<HullQueryParser::ExprContext>(i);
}


size_t HullQueryParser::ArglistContext::getRuleIndex() const {
  return HullQueryParser::RuleArglist;
}

void HullQueryParser::ArglistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HullQueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArglist(this);
}

void HullQueryParser::ArglistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HullQueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArglist(this);
}

HullQueryParser::ArglistContext* HullQueryParser::arglist() {
  ArglistContext *_localctx = _tracker.createInstance<ArglistContext>(_ctx, getState());
  enterRule(_localctx, 6, HullQueryParser::RuleArglist);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(52);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == HullQueryParser::ID) {
      setState(44);
      expr();
      setState(49);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == HullQueryParser::T__5) {
        setState(45);
        match(HullQueryParser::T__5);
        setState(46);
        expr();
        setState(51);
        _errHandler->sync(this);
        _la = _input->LA(1);
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

//----------------- DeclContext ------------------------------------------------------------------

HullQueryParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

HullQueryParser::TypeContext* HullQueryParser::DeclContext::type() {
  return getRuleContext<HullQueryParser::TypeContext>(0);
}

tree::TerminalNode* HullQueryParser::DeclContext::ID() {
  return getToken(HullQueryParser::ID, 0);
}

tree::TerminalNode* HullQueryParser::DeclContext::INT() {
  return getToken(HullQueryParser::INT, 0);
}


size_t HullQueryParser::DeclContext::getRuleIndex() const {
  return HullQueryParser::RuleDecl;
}

void HullQueryParser::DeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HullQueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecl(this);
}

void HullQueryParser::DeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HullQueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecl(this);
}

HullQueryParser::DeclContext* HullQueryParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 8, HullQueryParser::RuleDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    type();
    setState(55);
    match(HullQueryParser::ID);
    setState(59);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == HullQueryParser::T__6) {
      setState(56);
      match(HullQueryParser::T__6);
      setState(57);
      match(HullQueryParser::INT);
      setState(58);
      match(HullQueryParser::T__7);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarContext ------------------------------------------------------------------

HullQueryParser::VarContext::VarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* HullQueryParser::VarContext::ID() {
  return getToken(HullQueryParser::ID, 0);
}


size_t HullQueryParser::VarContext::getRuleIndex() const {
  return HullQueryParser::RuleVar;
}

void HullQueryParser::VarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HullQueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar(this);
}

void HullQueryParser::VarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HullQueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar(this);
}

HullQueryParser::VarContext* HullQueryParser::var() {
  VarContext *_localctx = _tracker.createInstance<VarContext>(_ctx, getState());
  enterRule(_localctx, 10, HullQueryParser::RuleVar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    match(HullQueryParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

HullQueryParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* HullQueryParser::TypeContext::ID() {
  return getToken(HullQueryParser::ID, 0);
}


size_t HullQueryParser::TypeContext::getRuleIndex() const {
  return HullQueryParser::RuleType;
}

void HullQueryParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HullQueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void HullQueryParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<HullQueryListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

HullQueryParser::TypeContext* HullQueryParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 12, HullQueryParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(63);
    match(HullQueryParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void HullQueryParser::initialize() {
  ::antlr4::internal::call_once(hullqueryParserOnceFlag, hullqueryParserInitialize);
}
