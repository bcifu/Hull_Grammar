
// Generated from HullQuery.g4 by ANTLR 4.9.3


#include "HullQueryListener.h"

#include "HullQueryParser.h"


using namespace antlrcpp;
using namespace antlr4;

HullQueryParser::HullQueryParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

HullQueryParser::~HullQueryParser() {
  delete _interpreter;
}

std::string HullQueryParser::getGrammarFileName() const {
  return "HullQuery.g4";
}

const std::vector<std::string>& HullQueryParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& HullQueryParser::getVocabulary() const {
  return _vocabulary;
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

// Static vars and initialization.
std::vector<dfa::DFA> HullQueryParser::_decisionToDFA;
atn::PredictionContextCache HullQueryParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN HullQueryParser::_atn;
std::vector<uint16_t> HullQueryParser::_serializedATN;

std::vector<std::string> HullQueryParser::_ruleNames = {
  "query", "expr", "func", "arglist", "decl", "var", "type"
};

std::vector<std::string> HullQueryParser::_literalNames = {
  "", "';'", "'='", "'.'", "'('", "')'", "','", "'['", "']'"
};

std::vector<std::string> HullQueryParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "WS", "NL", "INT", "ID"
};

dfa::Vocabulary HullQueryParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> HullQueryParser::_tokenNames;

HullQueryParser::Initializer::Initializer() {
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

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0xe, 0x44, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 
       0x14, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x17, 0xb, 0x2, 0x3, 0x2, 0x3, 
       0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x25, 0xa, 0x3, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 
       0x4, 0x2d, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x32, 
       0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x35, 0xb, 0x5, 0x5, 0x5, 0x37, 0xa, 
       0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 
       0x3e, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
       0x2, 0x2, 0x9, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x2, 0x2, 0x2, 
       0x44, 0x2, 0x15, 0x3, 0x2, 0x2, 0x2, 0x4, 0x24, 0x3, 0x2, 0x2, 0x2, 
       0x6, 0x26, 0x3, 0x2, 0x2, 0x2, 0x8, 0x36, 0x3, 0x2, 0x2, 0x2, 0xa, 
       0x38, 0x3, 0x2, 0x2, 0x2, 0xc, 0x3f, 0x3, 0x2, 0x2, 0x2, 0xe, 0x41, 
       0x3, 0x2, 0x2, 0x2, 0x10, 0x11, 0x5, 0x4, 0x3, 0x2, 0x11, 0x12, 0x7, 
       0x3, 0x2, 0x2, 0x12, 0x14, 0x3, 0x2, 0x2, 0x2, 0x13, 0x10, 0x3, 0x2, 
       0x2, 0x2, 0x14, 0x17, 0x3, 0x2, 0x2, 0x2, 0x15, 0x13, 0x3, 0x2, 0x2, 
       0x2, 0x15, 0x16, 0x3, 0x2, 0x2, 0x2, 0x16, 0x18, 0x3, 0x2, 0x2, 0x2, 
       0x17, 0x15, 0x3, 0x2, 0x2, 0x2, 0x18, 0x19, 0x7, 0x2, 0x2, 0x3, 0x19, 
       0x3, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1b, 0x5, 0xa, 0x6, 0x2, 0x1b, 0x1c, 
       0x7, 0x4, 0x2, 0x2, 0x1c, 0x1d, 0x5, 0x4, 0x3, 0x2, 0x1d, 0x25, 0x3, 
       0x2, 0x2, 0x2, 0x1e, 0x25, 0x5, 0xc, 0x7, 0x2, 0x1f, 0x25, 0x5, 0x6, 
       0x4, 0x2, 0x20, 0x21, 0x5, 0xc, 0x7, 0x2, 0x21, 0x22, 0x7, 0x5, 0x2, 
       0x2, 0x22, 0x23, 0x5, 0x6, 0x4, 0x2, 0x23, 0x25, 0x3, 0x2, 0x2, 0x2, 
       0x24, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x24, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x24, 
       0x1f, 0x3, 0x2, 0x2, 0x2, 0x24, 0x20, 0x3, 0x2, 0x2, 0x2, 0x25, 0x5, 
       0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x7, 0xe, 0x2, 0x2, 0x27, 0x28, 0x7, 
       0x6, 0x2, 0x2, 0x28, 0x29, 0x5, 0x8, 0x5, 0x2, 0x29, 0x2c, 0x7, 0x7, 
       0x2, 0x2, 0x2a, 0x2b, 0x7, 0x5, 0x2, 0x2, 0x2b, 0x2d, 0x5, 0x6, 0x4, 
       0x2, 0x2c, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x3, 0x2, 0x2, 0x2, 
       0x2d, 0x7, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x33, 0x5, 0x4, 0x3, 0x2, 0x2f, 
       0x30, 0x7, 0x8, 0x2, 0x2, 0x30, 0x32, 0x5, 0x4, 0x3, 0x2, 0x31, 0x2f, 
       0x3, 0x2, 0x2, 0x2, 0x32, 0x35, 0x3, 0x2, 0x2, 0x2, 0x33, 0x31, 0x3, 
       0x2, 0x2, 0x2, 0x33, 0x34, 0x3, 0x2, 0x2, 0x2, 0x34, 0x37, 0x3, 0x2, 
       0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 0x36, 0x2e, 0x3, 0x2, 0x2, 
       0x2, 0x36, 0x37, 0x3, 0x2, 0x2, 0x2, 0x37, 0x9, 0x3, 0x2, 0x2, 0x2, 
       0x38, 0x39, 0x5, 0xe, 0x8, 0x2, 0x39, 0x3d, 0x7, 0xe, 0x2, 0x2, 0x3a, 
       0x3b, 0x7, 0x9, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0xd, 0x2, 0x2, 0x3c, 0x3e, 
       0x7, 0xa, 0x2, 0x2, 0x3d, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x3, 
       0x2, 0x2, 0x2, 0x3e, 0xb, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x7, 0xe, 
       0x2, 0x2, 0x40, 0xd, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x7, 0xe, 0x2, 
       0x2, 0x42, 0xf, 0x3, 0x2, 0x2, 0x2, 0x8, 0x15, 0x24, 0x2c, 0x33, 
       0x36, 0x3d, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

HullQueryParser::Initializer HullQueryParser::_init;
