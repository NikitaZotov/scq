#include "ObjectsStore.hpp"


ObjectsStore::ObjectsStore()
{

}

bool ObjectsStore::declareObject(antlr4::tree::TerminalNode * ctx)
{
  std::string const objectName = ctx->getText();
  if (isObjectDeclared(objectName))
    return false;

  objectDeclarations.emplace_back(objectName);
  return true;
}

bool ObjectsStore::defineObject(antlr4::tree::TerminalNode * ctx)
{
  return true;
}

bool ObjectsStore::isObjectDeclared(std::string const & name)
{
  return std::find(objectDeclarations.begin(), objectDeclarations.end(), name) != objectDeclarations.end();
}
