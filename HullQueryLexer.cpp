
// Generated from HullQuery.g4 by ANTLR 4.11.1


#include "HullQueryLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct HullQueryLexerStaticData final {
  HullQueryLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  HullQueryLexerStaticData(const HullQueryLexerStaticData&) = delete;
  HullQueryLexerStaticData(HullQueryLexerStaticData&&) = delete;
  HullQueryLexerStaticData& operator=(const HullQueryLexerStaticData&) = delete;
  HullQueryLexerStaticData& operator=(HullQueryLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag hullquerylexerLexerOnceFlag;
HullQueryLexerStaticData *hullquerylexerLexerStaticData = nullptr;

void hullquerylexerLexerInitialize() {
  assert(hullquerylexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<HullQueryLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "DIGIT", 
      "WS", "NL", "INT", "ID"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "';'", "'='", "'.'", "'('", "')'", "','", "'['", "']'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "WS", "NL", "INT", "ID"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,12,68,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,1,0,1,0,1,1,1,
  	1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,9,
  	1,9,1,10,4,10,51,8,10,11,10,12,10,52,1,10,1,10,1,11,4,11,58,8,11,11,11,
  	12,11,59,1,12,1,12,5,12,64,8,12,10,12,12,12,67,9,12,0,0,13,1,1,3,2,5,
  	3,7,4,9,5,11,6,13,7,15,8,17,0,19,9,21,10,23,11,25,12,1,0,4,2,0,9,9,32,
  	32,2,0,10,10,13,13,3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,
  	69,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,
  	0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,
  	0,0,25,1,0,0,0,1,27,1,0,0,0,3,29,1,0,0,0,5,31,1,0,0,0,7,33,1,0,0,0,9,
  	35,1,0,0,0,11,37,1,0,0,0,13,39,1,0,0,0,15,41,1,0,0,0,17,43,1,0,0,0,19,
  	45,1,0,0,0,21,50,1,0,0,0,23,57,1,0,0,0,25,61,1,0,0,0,27,28,5,59,0,0,28,
  	2,1,0,0,0,29,30,5,61,0,0,30,4,1,0,0,0,31,32,5,46,0,0,32,6,1,0,0,0,33,
  	34,5,40,0,0,34,8,1,0,0,0,35,36,5,41,0,0,36,10,1,0,0,0,37,38,5,44,0,0,
  	38,12,1,0,0,0,39,40,5,91,0,0,40,14,1,0,0,0,41,42,5,93,0,0,42,16,1,0,0,
  	0,43,44,2,48,57,0,44,18,1,0,0,0,45,46,7,0,0,0,46,47,1,0,0,0,47,48,6,9,
  	0,0,48,20,1,0,0,0,49,51,7,1,0,0,50,49,1,0,0,0,51,52,1,0,0,0,52,50,1,0,
  	0,0,52,53,1,0,0,0,53,54,1,0,0,0,54,55,6,10,0,0,55,22,1,0,0,0,56,58,3,
  	17,8,0,57,56,1,0,0,0,58,59,1,0,0,0,59,57,1,0,0,0,59,60,1,0,0,0,60,24,
  	1,0,0,0,61,65,7,2,0,0,62,64,7,3,0,0,63,62,1,0,0,0,64,67,1,0,0,0,65,63,
  	1,0,0,0,65,66,1,0,0,0,66,26,1,0,0,0,67,65,1,0,0,0,4,0,52,59,65,1,6,0,
  	0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  hullquerylexerLexerStaticData = staticData.release();
}

}

HullQueryLexer::HullQueryLexer(CharStream *input) : Lexer(input) {
  HullQueryLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *hullquerylexerLexerStaticData->atn, hullquerylexerLexerStaticData->decisionToDFA, hullquerylexerLexerStaticData->sharedContextCache);
}

HullQueryLexer::~HullQueryLexer() {
  delete _interpreter;
}

std::string HullQueryLexer::getGrammarFileName() const {
  return "HullQuery.g4";
}

const std::vector<std::string>& HullQueryLexer::getRuleNames() const {
  return hullquerylexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& HullQueryLexer::getChannelNames() const {
  return hullquerylexerLexerStaticData->channelNames;
}

const std::vector<std::string>& HullQueryLexer::getModeNames() const {
  return hullquerylexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& HullQueryLexer::getVocabulary() const {
  return hullquerylexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView HullQueryLexer::getSerializedATN() const {
  return hullquerylexerLexerStaticData->serializedATN;
}

const atn::ATN& HullQueryLexer::getATN() const {
  return *hullquerylexerLexerStaticData->atn;
}




void HullQueryLexer::initialize() {
  ::antlr4::internal::call_once(hullquerylexerLexerOnceFlag, hullquerylexerLexerInitialize);
}
