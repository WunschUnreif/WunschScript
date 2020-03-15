#pragma once

#include "AbstractLang.hpp"

namespace ws {

namespace sup {

asl::GeneralDataNode PrintImpl(std::vector<asl::GeneralDataNode> params, asl::Environment & env);

asl::GeneralDataNode ReadImpl(std::vector<asl::GeneralDataNode> params, asl::Environment & env);

asl::GeneralDataNode ReadLineImpl(std::vector<asl::GeneralDataNode> params, asl::Environment & env);

}

}
