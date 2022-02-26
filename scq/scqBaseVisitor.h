
// Generated from scq-lang/scq-lang.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "scqVisitor.h"


namespace scq {

/**
 * This class provides an empty implementation of scqVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  scqBaseVisitor : public scqVisitor {
public:

  virtual antlrcpp::Any visitProgram(scqParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcDeclaration(scqParser::ProcDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcDefinition(scqParser::ProcDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcParams(scqParser::ProcParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcBody(scqParser::ProcBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitObjectCreation(scqParser::ObjectCreationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitObjectCreationOperand(scqParser::ObjectCreationOperandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCommand(scqParser::CommandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompositeOperand(scqParser::CompositeOperandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCommandCompositeOperand(scqParser::CommandCompositeOperandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperand(scqParser::OperandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNonOrientedSet(scqParser::NonOrientedSetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOrientedSet(scqParser::OrientedSetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTemplateCommand(scqParser::TemplateCommandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTemplateExpression(scqParser::TemplateExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCommandTemplate(scqParser::CommandTemplateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCommandTemplateResult(scqParser::CommandTemplateResultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTemplateParam(scqParser::TemplateParamContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace scq-lang
