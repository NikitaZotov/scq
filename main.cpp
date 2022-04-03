#include <boost/program_options.hpp>

#include <iostream>

#include <sc-memory/sc_memory.hpp>
#include <sc-memory/utils/sc_signal_handler.hpp>

#include "scq/scqCompiler.hpp"


int main(int argc, const char * argv[]) try
{
  boost::program_options::options_description options_description("SCq-compiler usage");
  options_description.add_options()
        ("help", "Display this message")
        ("ext-path,e", boost::program_options::value<std::string>(), "Path to directory with sc-memory extensions")
        ("repo-path,r", boost::program_options::value<std::string>(), "Path to repository")
        ("verbose,v", "Flag to don't save sc-memory state on exit")
        ("clear,c", "Flag to clear sc-memory on start")
        ("config-file,i", boost::program_options::value<std::string>(), "Path to configuration file");

  boost::program_options::variables_map vm;
  boost::program_options::store(boost::program_options::command_line_parser(argc, argv).options(options_description).run(), vm);
  boost::program_options::notify(vm);

  std::string configFile;
  if (vm.count("config-file"))
    configFile = vm["config-file"].as<std::string>();

  std::string extPath;
  if (vm.count("ext-path"))
    extPath = vm["ext-path"].as<std::string>();

  std::string repoPath;
  if (vm.count("repo-path"))
    repoPath = vm["repo-path"].as<std::string>();

  bool clear = false;
  if (vm.count("clear"))
    clear = true;

  if (vm.count("help"))
  {
    std::cout << options_description;
    return 0;
  }

  utils::ScSignalHandler::Initialize();

  sc_memory_params params;
  sc_memory_params_clear(&params);

  params.clear = clear ? SC_TRUE : SC_FALSE;
  params.config_file = configFile.c_str();
  params.enabled_exts = nullptr;
  params.ext_path = extPath.c_str();
  params.repo_path = repoPath.c_str();

  scqCompiler compiler {};

  return compiler.compile(params) ? EXIT_SUCCESS : EXIT_FAILURE;
}
catch (utils::ScException & e)
{
  SC_LOG_ERROR(e.what())
}