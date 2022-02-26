
// Generated from scq-lang/scq-lang.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "scqParser.h"


namespace scq {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by scqParser.
 */
class  scqVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by scqParser.
   */
    virtual antlrcpp::Any visitProgram(scqParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitProcDeclaration(scqParser::ProcDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitProcDefinition(scqParser::ProcDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitProcParams(scqParser::ProcParamsContext *context) = 0;

    virtual antlrcpp::Any visitProcBody(scqParser::ProcBodyContext *context) = 0;

    virtual antlrcpp::Any visitObjectCreation(scqParser::ObjectCreationContext *context) = 0;

    virtual antlrcpp::Any visitObjectCreationOperand(scqParser::ObjectCreationOperandContext *context) = 0;

    virtual antlrcpp::Any visitCommand(scqParser::CommandContext *context) = 0;

    virtual antlrcpp::Any visitCompositeOperand(scqParser::CompositeOperandContext *context) = 0;

    virtual antlrcpp::Any visitCommandCompositeOperand(scqParser::CommandCompositeOperandContext *context) = 0;

    virtual antlrcpp::Any visitOperand(scqParser::OperandContext *context) = 0;

    virtual antlrcpp::Any visitNonOrientedSet(scqParser::NonOrientedSetContext *context) = 0;

    virtual antlrcpp::Any visitOrientedSet(scqParser::OrientedSetContext *context) = 0;

    virtual antlrcpp::Any visitTemplateCommand(scqParser::TemplateCommandContext *context) = 0;

    virtual antlrcpp::Any visitTemplateExpression(scqParser::TemplateExpressionContext *context) = 0;

    virtual antlrcpp::Any visitCommandTemplate(scqParser::CommandTemplateContext *context) = 0;

    virtual antlrcpp::Any visitCommandTemplateResult(scqParser::CommandTemplateResultContext *context) = 0;

    virtual antlrcpp::Any visitTemplateParam(scqParser::TemplateParamContext *context) = 0;


};

}  // namespace scq-lang
