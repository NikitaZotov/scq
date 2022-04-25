#include "scqExecutor.hpp"
#include "sc-memory/sc_link.hpp"


scqExecutor::scqExecutor(ProcedureDefinitions * procDefs, ObjectsTypes * types, ObjectsDefinitions * definitions)
  : procDefs(procDefs), types(types), definitions(definitions)
{
  context = new ScMemoryContext("scqExecutor");
  objects = new Objects();
  objects->insert({ "", {} });

  setTypes.insert({ "terminal", context->HelperResolveSystemIdtf("concept_terminal", ScType::NodeConstClass) });
  setTypes.insert({ "tuple", context->HelperResolveSystemIdtf("concept_oriented_set", ScType::NodeConstClass) });
  setTypes.insert({ "set", context->HelperResolveSystemIdtf("concept_non_oriented_set", ScType::NodeConstClass) });
}

sc_bool scqExecutor::execute(std::unordered_map<std::string, scqAction *> actions, std::string const & function)
{
  try
  {
    FunctionContext & functionCtx = objects->find(function)->second;

    scqAction * action = nullptr;
    ScAddrVector params;
    std::vector<ScAddrVector> linkedAddrs;
    for (size_t i = 0; i < definitions->size(); ++i)
    {
      auto & definition = definitions->at(i);

      std::string const & operationType = definition[0];
      std::string const & objName = definition[1];
      std::string const & depthStr = definition[2];

      if (operationType != "param")
      {
        auto const it = actions.find(operationType);

        if (action != nullptr)
        {
          action->apply(context, params, procDefs, types, definitions, &functionCtx);
          if (action->index + params.size() != i - 1)
          {
            i = action->index;
            definition = definitions->at(i);
          }
        }

        params.clear();
        linkedAddrs.clear();

        if (operationType == "end")
        {
          action = nullptr;
          continue;
        }

        action = actions.find(operationType)->second;
        action->name = objName;
        action->index = i;
      }
      else
      {
        ScAddr param = resolveParam(objName, functionCtx);
        params.push_back(param);

        size_t depth = std::stoi(depthStr);
        if (linkedAddrs.size() <= depth)
          linkedAddrs.emplace_back();

        linkedAddrs.at(depth).push_back(param);

        if (depth > 0)
        {
          ScAddrVector addrsOnDepth = linkedAddrs.at(depth - 1);
          if (!addrsOnDepth.empty())
            context->CreateEdge(ScType::EdgeAccessConstPosPerm, addrsOnDepth.back(), param);
        }
      }
    }

    if (action != nullptr)
      action->apply(context, params, procDefs, types, definitions, &functionCtx);
  }
  catch (utils::ScException & e)
  {
    SC_LOG_ERROR(e.Message());
    return SC_FALSE;
  }

  return SC_TRUE;
}

ScAddr scqExecutor::createObject(std::string const & objName, FunctionContext & functionCtx)
{
  if (objName == "{}" || objName == "()")
  {
    ScAddr node = context->CreateNode(ScType::NodeConst);
    context->CreateEdge(
          ScType::EdgeAccessConstPosPerm,
          setTypes.find(objName == "{}" ? "set" : "tuple")->second,
          node);

    return node;
  }

  auto const typeIt = types->find(objName);

  ScAddr node = context->CreateNode(ScType::NodeConst);
  context->CreateEdge(
        ScType::EdgeAccessConstPosPerm,
        setTypes.find(typeIt->second)->second,
        node);

  functionCtx.insert({ objName, node });

  return node;
}

ScAddr scqExecutor::resolveParam(std::string const & objName, FunctionContext & functionCtx)
{
  auto const objectIt = functionCtx.find(objName);
  ScAddr param;
  if (objectIt == functionCtx.end())
  {
    if (objName[0] == '\'')
    {
      param = context->CreateLink();
      ScLink link{ *context, param };

      link.Set(objName.substr(1, objName.size() - 2));
    }
    else if (objName[0] == '<')
      param = context->HelperResolveSystemIdtf(objName.substr(1, objName.size() - 2), ScType::NodeVar);
    else
      param = createObject(objName, functionCtx);
  }
  else
    param = objectIt->second;

  return param;
}

scqExecutor::~scqExecutor()
{
  context->Destroy();
}
