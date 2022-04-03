#pragma once

#include "antlr4-runtime.h"

#include "sc-memory/sc_memory.hpp"
#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_keynodes.hpp"

#include "ProceduresStore.hpp"
#include "ObjectsStore.hpp"

#include "scqVisitor.h"


/**
 * This class provides an empty implementation of scqVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class scqBaseVisitor : public scqVisitor
{
public:
  scqBaseVisitor()
  {
    this->procedureStore = new ProceduresStore();
    this->objectsStore = new ObjectsStore();
    this->memoryCtx = new ScMemoryContext(sc_access_lvl_make_min, "scqVisitor");
  }

  antlrcpp::Any visitProgram(scqParser::ProgramContext * ctx) override
  {
    // check procedures definitions with their declarations
    std::vector<scqParser::ProcDeclarationContext *> multProcDeclarations = ctx->procDeclaration();
    for (auto * multProcDeclaration: multProcDeclarations)
      visit(multProcDeclaration);

    std::vector<scqParser::ProcDefinitionContext *> multProcDefinitions = ctx->procDefinition();
    for (auto * multProcDefinition: multProcDefinitions)
      visit(multProcDefinition);

    return visitChildren(ctx->block());
  }

  antlrcpp::Any visitProcDeclaration(scqParser::ProcDeclarationContext * ctx) override
  {
    // store procedure declarations
    std::vector<antlr4::tree::TerminalNode *> singleProcDeclarations = ctx->NAME();
    for (auto * singleProcDeclaration: singleProcDeclarations)
    {
      std::cout << singleProcDeclaration->getText() << std::endl;
      if (!procedureStore->declareProcedure(singleProcDeclaration->getText()))
      {
        SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The function isn't declared.")
      }
    }

    return visitChildren(ctx);
  }

  antlrcpp::Any visitProcDefinition(scqParser::ProcDefinitionContext * ctx) override
  {
    if (!procedureStore->defineProcedure(ctx))
    {
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The function isn't declared.")
    }

    return {};
  }

  antlrcpp::Any visitProcParams(scqParser::ProcParamsContext * ctx) override
  {
    return visitChildren(ctx);
  }

  antlrcpp::Any visitProcBody(scqParser::BlockContext * ctx) override
  {
    std::cout << ctx->toStringTree() << std::endl;
    return visitChildren(ctx);
  }

  antlrcpp::Any visitObjectDeclaration(scqParser::ObjectDeclarationContext * ctx) override
  {
    std::vector<antlr4::tree::TerminalNode *> objDeclarations = ctx->NAME();
    for (auto const & objDeclaration : objDeclarations)
    {
      std::cout << objDeclaration->getText() << std::endl;
      if (!objectsStore->declareObject(objDeclaration))
      {
        SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object isn't declared.")
      }
    }

    return visitChildren(ctx);
  }

  antlrcpp::Any visitObjectDefinition(scqParser::ObjectDefinitionContext * ctx) override
  {
    std::vector<antlr4::tree::TerminalNode *> objDefinitions = ctx->NAME();
    for (auto const & objDefinition : objDefinitions)
    {
      std::cout << objDefinition->getText() << std::endl;
      if (!procedureStore->declareProcedure(objDefinition->getText()) && !objectsStore->defineObject(objDefinition))
      {
        SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object isn't declared.")
      }
    }

    return visitChildren(ctx);
  }

  antlrcpp::Any visitOperation(scqParser::OperationContext * ctx) override
  {
    return visitChildren(ctx);
  }

  antlrcpp::Any visitCompositeOperand(scqParser::CompositeOperandContext * ctx) override
  {
    return visitChildren(ctx);
  }

  antlrcpp::Any visitOperationOperand(scqParser::OperationOperandContext * ctx) override
  {
    return visitChildren(ctx);
  }

  antlrcpp::Any visitOperand(scqParser::OperandContext * ctx) override
  {
    return visitChildren(ctx);
  }

  antlrcpp::Any visitNonOrientedSet(scqParser::NonOrientedSetContext * ctx) override
  {
    return visitChildren(ctx);
  }

  antlrcpp::Any visitOrientedSet(scqParser::OrientedSetContext * ctx) override
  {
    return visitChildren(ctx);
  }

  antlrcpp::Any visitTemplateCommand(scqParser::TemplateCommandContext * ctx) override
  {
    return visitChildren(ctx);
  }

  antlrcpp::Any visitTemplateExpression(scqParser::TemplateExpressionContext * ctx) override
  {
    return visitChildren(ctx);
  }

  antlrcpp::Any visitCommandTemplate(scqParser::CommandTemplateContext * ctx) override
  {
    return visitChildren(ctx);
  }

  antlrcpp::Any visitCommandTemplateResult(scqParser::CommandTemplateResultContext * ctx) override
  {
    return visitChildren(ctx);
  }

  antlrcpp::Any visitTemplateParam(scqParser::TemplateParamContext * ctx) override
  {
    return visitChildren(ctx);
  }

  ~scqBaseVisitor() override
  {
    delete procedureStore;
  }

private:
  ProceduresStore * procedureStore;
  ObjectsStore * objectsStore;

  ScMemoryContext * memoryCtx {};
};

