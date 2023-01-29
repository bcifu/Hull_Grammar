
// Generated from HullQuery.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "HullQueryParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by HullQueryParser.
 */
class  HullQueryListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterQuery(HullQueryParser::QueryContext *ctx) = 0;
  virtual void exitQuery(HullQueryParser::QueryContext *ctx) = 0;

  virtual void enterExpr(HullQueryParser::ExprContext *ctx) = 0;
  virtual void exitExpr(HullQueryParser::ExprContext *ctx) = 0;

  virtual void enterFunc(HullQueryParser::FuncContext *ctx) = 0;
  virtual void exitFunc(HullQueryParser::FuncContext *ctx) = 0;

  virtual void enterArglist(HullQueryParser::ArglistContext *ctx) = 0;
  virtual void exitArglist(HullQueryParser::ArglistContext *ctx) = 0;

  virtual void enterDecl(HullQueryParser::DeclContext *ctx) = 0;
  virtual void exitDecl(HullQueryParser::DeclContext *ctx) = 0;

  virtual void enterVar(HullQueryParser::VarContext *ctx) = 0;
  virtual void exitVar(HullQueryParser::VarContext *ctx) = 0;

  virtual void enterType(HullQueryParser::TypeContext *ctx) = 0;
  virtual void exitType(HullQueryParser::TypeContext *ctx) = 0;


};

