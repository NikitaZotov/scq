
#include "sc-memory/sc_memory.hpp"
#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_keynodes.hpp"


// Generated from /home/nikita/CLionProjects/ostis-web-platform/sc-machine/scq/scq/scq.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "scqParser.h"



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

    virtual antlrcpp::Any visitBlock(scqParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitObjectDeclaration(scqParser::ObjectDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitObjectDefinition(scqParser::ObjectDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitOperation(scqParser::OperationContext *context) = 0;

    virtual antlrcpp::Any visitCompositeOperand(scqParser::CompositeOperandContext *context) = 0;

    virtual antlrcpp::Any visitOperationOperand(scqParser::OperationOperandContext *context) = 0;

    virtual antlrcpp::Any visitOperand(scqParser::OperandContext *context) = 0;

    virtual antlrcpp::Any visitNonOrientedSet(scqParser::NonOrientedSetContext *context) = 0;

    virtual antlrcpp::Any visitOrientedSet(scqParser::OrientedSetContext *context) = 0;

    virtual antlrcpp::Any visitTemplateCommand(scqParser::TemplateCommandContext *context) = 0;

    virtual antlrcpp::Any visitTemplateExpression(scqParser::TemplateExpressionContext *context) = 0;

    virtual antlrcpp::Any visitCommandTemplate(scqParser::CommandTemplateContext *context) = 0;

    virtual antlrcpp::Any visitCommandTemplateResult(scqParser::CommandTemplateResultContext *context) = 0;

    virtual antlrcpp::Any visitTemplateParam(scqParser::TemplateParamContext *context) = 0;

    virtual antlrcpp::Any visitSetOperation(scqParser::SetOperationContext *context) = 0;


};

