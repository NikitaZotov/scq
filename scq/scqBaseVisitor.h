
#include "sc-memory/sc_memory.hpp"
#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_keynodes.hpp"


// Generated from /home/nikita/CLionProjects/ostis-web-platform/sc-machine/scq/scq/scq.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "scqVisitor.h"


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

  virtual antlrcpp::Any visitBlock(scqParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitObjectDeclaration(scqParser::ObjectDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitObjectDefinition(scqParser::ObjectDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperation(scqParser::OperationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompositeOperand(scqParser::CompositeOperandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperationOperand(scqParser::OperationOperandContext *ctx) override {
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

  virtual antlrcpp::Any visitSetOperation(scqParser::SetOperationContext *ctx) override {
    return visitChildren(ctx);
  }


};

