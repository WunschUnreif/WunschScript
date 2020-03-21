#pragma once

#include "AbstractLang.hpp"

namespace ws {

namespace sup {

/// len(list)
asl::GeneralDataNode LenImpl(std::vector<asl::GeneralDataNode> params, asl::Environment & env);

asl::GeneralDataNode RangeImpl(std::vector<asl::GeneralDataNode> params, asl::Environment & env);

asl::GeneralDataNode FRangeImpl(std::vector<asl::GeneralDataNode> params, asl::Environment & env);

}

}
