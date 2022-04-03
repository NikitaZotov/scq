
// Generated from /home/nikita/CLionProjects/sc-machine/scq/scq/scq.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "../scqParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by scqParser.
 */
class  scqListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(scqParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(scqParser::ProgramContext *ctx) = 0;

  virtual void enterProcDeclaration(scqParser::ProcDeclarationContext *ctx) = 0;
  virtual void exitProcDeclaration(scqParser::ProcDeclarationContext *ctx) = 0;

  virtual void enterProcDefinition(scqParser::ProcDefinitionContext *ctx) = 0;
  virtual void exitProcDefinition(scqParser::ProcDefinitionContext *ctx) = 0;

  virtual void enterProcParams(scqParser::ProcParamsContext *ctx) = 0;
  virtual void exitProcParams(scqParser::ProcParamsContext *ctx) = 0;

  virtual void enterProcBody(scqParser::BlockContext *ctx) = 0;
  virtual void exitProcBody(scqParser::BlockContext *ctx) = 0;

  virtual void enterObjectDeclaration(scqParser::ObjectDeclarationContext *ctx) = 0;
  virtual void exitObjectDeclaration(scqParser::ObjectDeclarationContext *ctx) = 0;

  virtual void enterObjectDefinition(scqParser::ObjectDefinitionContext *ctx) = 0;
  virtual void exitObjectDefinition(scqParser::ObjectDefinitionContext *ctx) = 0;

  virtual void enterOperation(scqParser::OperationContext *ctx) = 0;
  virtual void exitOperation(scqParser::OperationContext *ctx) = 0;

  virtual void enterCompositeOperand(scqParser::CompositeOperandContext *ctx) = 0;
  virtual void exitCompositeOperand(scqParser::CompositeOperandContext *ctx) = 0;

  virtual void enterOperationOperand(scqParser::OperationOperandContext *ctx) = 0;
  virtual void exitOperationOperand(scqParser::OperationOperandContext *ctx) = 0;

  virtual void enterOperand(scqParser::OperandContext *ctx) = 0;
  virtual void exitOperand(scqParser::OperandContext *ctx) = 0;

  virtual void enterNonOrientedSet(scqParser::NonOrientedSetContext *ctx) = 0;
  virtual void exitNonOrientedSet(scqParser::NonOrientedSetContext *ctx) = 0;

  virtual void enterOrientedSet(scqParser::OrientedSetContext *ctx) = 0;
  virtual void exitOrientedSet(scqParser::OrientedSetContext *ctx) = 0;

  virtual void enterTemplateCommand(scqParser::TemplateCommandContext *ctx) = 0;
  virtual void exitTemplateCommand(scqParser::TemplateCommandContext *ctx) = 0;

  virtual void enterTemplateExpression(scqParser::TemplateExpressionContext *ctx) = 0;
  virtual void exitTemplateExpression(scqParser::TemplateExpressionContext *ctx) = 0;

  virtual void enterCommandTemplate(scqParser::CommandTemplateContext *ctx) = 0;
  virtual void exitCommandTemplate(scqParser::CommandTemplateContext *ctx) = 0;

  virtual void enterCommandTemplateResult(scqParser::CommandTemplateResultContext *ctx) = 0;
  virtual void exitCommandTemplateResult(scqParser::CommandTemplateResultContext *ctx) = 0;

  virtual void enterTemplateParam(scqParser::TemplateParamContext *ctx) = 0;
  virtual void exitTemplateParam(scqParser::TemplateParamContext *ctx) = 0;


};

