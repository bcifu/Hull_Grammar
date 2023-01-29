
// Generated from HullQuery.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "HullQueryListener.h"


/**
 * This class provides an empty implementation of HullQueryListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  HullQueryBaseListener : public HullQueryListener {
public:

  virtual void enterQuery(HullQueryParser::QueryContext * /*ctx*/) override { }
  virtual void exitQuery(HullQueryParser::QueryContext * /*ctx*/) override { }

  virtual void enterExpr(HullQueryParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(HullQueryParser::ExprContext * /*ctx*/) override { }

  virtual void enterFunc(HullQueryParser::FuncContext * /*ctx*/) override { }
  virtual void exitFunc(HullQueryParser::FuncContext * /*ctx*/) override { }

  virtual void enterArglist(HullQueryParser::ArglistContext * /*ctx*/) override { }
  virtual void exitArglist(HullQueryParser::ArglistContext * /*ctx*/) override { }

  virtual void enterDecl(HullQueryParser::DeclContext * /*ctx*/) override { }
  virtual void exitDecl(HullQueryParser::DeclContext * /*ctx*/) override { }

  virtual void enterVar(HullQueryParser::VarContext * /*ctx*/) override { }
  virtual void exitVar(HullQueryParser::VarContext * /*ctx*/) override { }

  virtual void enterType(HullQueryParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(HullQueryParser::TypeContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

