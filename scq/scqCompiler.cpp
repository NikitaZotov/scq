#include <thread>
#include "antlr4-runtime.h"

#include "scqParser.h"
#include "scqLexer.h"
#include "executor/scqExecutor.hpp"
#include "executor/scqActionMap.hpp"

#include "scqCompiler.hpp"
#include "sc-memory/utils/sc_signal_handler.hpp"


sc_bool scqCompiler::compile(sc_memory_params const & params, std::string const & filePath)
{
  try
  {
    ScMemory::Initialize(params);

    std::ifstream file(filePath, std::ios_base::in);
    antlr4::ANTLRInputStream input(file);
    scq::scqLexer lexer(&input);

    antlr4::CommonTokenStream tokens(&lexer);
    scq::scqParser parser(&tokens);

    scq::scqParser::ProgramContext * ctx = parser.program();
    file.close();

    auto * executor = new scqExecutor { ctx->procDefs, ctx->objects, ctx->objDefs };
    executor->execute(scqActionMap().actions);
    delete executor;

    ScMemory::Shutdown(true);
  }
  catch (utils::ScException & e)
  {
    SC_LOG_ERROR(e.Message());
    return SC_FALSE;
  }

  return SC_TRUE;
}
