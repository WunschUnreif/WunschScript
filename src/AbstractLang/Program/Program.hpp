#pragma once 

#include <memory>
#include <list>
#include <string>

#include "Environment/Environment.hpp"
#include "Environment/Scope.hpp"

namespace ws {

namespace asl {

    struct Program {

        std::string filename;

        Environment env;
        std::shared_ptr<Scope> rootScope;

        std::list<std::shared_ptr<StatementBase>> statements;

        void Execute();

        int64_t GenByteCode(vm::ByteCodeBuilder & builder);

    };

}

}
