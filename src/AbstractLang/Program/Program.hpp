#pragma once 

#include <memory>
#include <list>

#include "Environment/Environment.hpp"
#include "Environment/Scope.hpp"

namespace ws {

namespace asl {

    struct Program {

        Environment env;
        std::shared_ptr<Scope> rootScope;

        std::list<std::shared_ptr<StatementBase>> statements;

        void Execute();

    };

}

}
