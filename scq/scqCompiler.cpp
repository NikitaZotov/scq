#include "antlr4-runtime.h"

#include "scqParser.h"
#include "scqLexer.h"

#include "scqCompiler.hpp"


sc_bool scqCompiler::compile(sc_memory_params const & params)
{
  try
  {
    ScMemory::Initialize(params);

    std::ifstream file("/home/nikita/CLionProjects/ostis-web-platform/sc-machine/scq/examples/test_1.scq", std::ios_base::in);
    antlr4::ANTLRInputStream input(file);
    scqLexer lexer(&input);

    antlr4::CommonTokenStream tokens(&lexer);
    scqParser parser(&tokens);
    antlr4::tree::ParseTree * tree = parser.program();

    file.close();

    ScMemory::Shutdown(true);
  }
  catch (utils::ScException & e)
  {
    SC_LOG_ERROR(e.what());
    return SC_FALSE;
  }

  return SC_TRUE;
}
