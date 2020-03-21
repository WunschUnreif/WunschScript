#include <memory>

#include "AbstractLang.hpp"
#include "Console.hpp"
#include "List.hpp"

using namespace ws::asl;
using namespace ws::sup;

void LoadSystemFunctions(std::shared_ptr<ws::asl::Scope> rootScope) {
    std::cout << "Loading System Functions" << std::endl;
    auto & target = rootScope->contentStack.top();

    // Load [Console] functions
    target["print"] = GeneralDataNodeFactory::PackSystemFunc(PrintImpl);
    target["read"]  = GeneralDataNodeFactory::PackSystemFunc(ReadImpl);
    target["readline"]  = GeneralDataNodeFactory::PackSystemFunc(ReadLineImpl);
    
    // Load [List] functions
    target["len"] = GeneralDataNodeFactory::PackSystemFunc(LenImpl);
    target["range"]  = GeneralDataNodeFactory::PackSystemFunc(RangeImpl);
    target["frange"]  = GeneralDataNodeFactory::PackSystemFunc(FRangeImpl);
}

