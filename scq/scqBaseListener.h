
// Generated from scq-lang/scq-lang.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "scqListener.h"


namespace scq {

/**
 * This class provides an empty implementation of scqListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  scqBaseListener : public scqListener {
public:

  virtual void enterProgram(scqParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(scqParser::ProgramContext * /*ctx*/) override { }

  virtual void enterProcDeclaration(scqParser::ProcDeclarationContext * /*ctx*/) override { }
  virtual void exitProcDeclaration(scqParser::ProcDeclarationContext * /*ctx*/) override { }

  virtual void enterProcDefinition(scqParser::ProcDefinitionContext * /*ctx*/) override { }
  virtual void exitProcDefinition(scqParser::ProcDefinitionContext * /*ctx*/) override { }

  virtual void enterProcParams(scqParser::ProcParamsContext * /*ctx*/) override { }
  virtual void exitProcParams(scqParser::ProcParamsContext * /*ctx*/) override { }

  virtual void enterProcBody(scqParser::ProcBodyContext * /*ctx*/) override { }
  virtual void exitProcBody(scqParser::ProcBodyContext * /*ctx*/) override { }

  virtual void enterObjectCreation(scqParser::ObjectCreationContext * /*ctx*/) override { }
  virtual void exitObjectCreation(scqParser::ObjectCreationContext * /*ctx*/) override { }

  virtual void enterObjectCreationOperand(scqParser::ObjectCreationOperandContext * /*ctx*/) override { }
  virtual void exitObjectCreationOperand(scqParser::ObjectCreationOperandContext * /*ctx*/) override { }

  virtual void enterCommand(scqParser::CommandContext * /*ctx*/) override { }
  virtual void exitCommand(scqParser::CommandContext * /*ctx*/) override { }

  virtual void enterCompositeOperand(scqParser::CompositeOperandContext * /*ctx*/) override { }
  virtual void exitCompositeOperand(scqParser::CompositeOperandContext * /*ctx*/) override { }

  virtual void enterCommandCompositeOperand(scqParser::CommandCompositeOperandContext * /*ctx*/) override { }
  virtual void exitCommandCompositeOperand(scqParser::CommandCompositeOperandContext * /*ctx*/) override { }

  virtual void enterOperand(scqParser::OperandContext * /*ctx*/) override { }
  virtual void exitOperand(scqParser::OperandContext * /*ctx*/) override { }

  virtual void enterNonOrientedSet(scqParser::NonOrientedSetContext * /*ctx*/) override { }
  virtual void exitNonOrientedSet(scqParser::NonOrientedSetContext * /*ctx*/) override { }

  virtual void enterOrientedSet(scqParser::OrientedSetContext * /*ctx*/) override { }
  virtual void exitOrientedSet(scqParser::OrientedSetContext * /*ctx*/) override { }

  virtual void enterTemplateCommand(scqParser::TemplateCommandContext * /*ctx*/) override { }
  virtual void exitTemplateCommand(scqParser::TemplateCommandContext * /*ctx*/) override { }

  virtual void enterTemplateExpression(scqParser::TemplateExpressionContext * /*ctx*/) override { }
  virtual void exitTemplateExpression(scqParser::TemplateExpressionContext * /*ctx*/) override { }

  virtual void enterCommandTemplate(scqParser::CommandTemplateContext * /*ctx*/) override { }
  virtual void exitCommandTemplate(scqParser::CommandTemplateContext * /*ctx*/) override { }

  virtual void enterCommandTemplateResult(scqParser::CommandTemplateResultContext * /*ctx*/) override { }
  virtual void exitCommandTemplateResult(scqParser::CommandTemplateResultContext * /*ctx*/) override { }

  virtual void enterTemplateParam(scqParser::TemplateParamContext * /*ctx*/) override { }
  virtual void exitTemplateParam(scqParser::TemplateParamContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace scq-lang