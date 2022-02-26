#include "antlr4-runtime.h"
#include "scqLexer.h"
#include "scqParser.h"

using namespace scq;

int main(int argc, const char * args[])
{
  const std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
  {
    try
    {
      std::ifstream file("/home/nikita/CLionProjects/scq-lang/examples/test_1.scq", std::ios_base::in);

      antlr4::ANTLRInputStream input(file);

      scqLexer lexer(&input);

      antlr4::CommonTokenStream tokens(&lexer);

      scqParser parser(&tokens);

      antlr4::tree::ParseTree * tree = parser.program();

      std::cout << tree->toStringTree() << std::endl;
    }
    catch (const std::exception & e)
    {
    }
  }
  const std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

  const auto elapsed_time_us  = std::chrono::duration_cast <std::chrono::microseconds> (end - start);
  const auto elapsed_time_sec = (elapsed_time_us.count() / 1000000.0);

  return 0;
}