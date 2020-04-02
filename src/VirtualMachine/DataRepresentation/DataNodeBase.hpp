#pragma once

#include <string>
#include <memory>

namespace ws {

namespace vm {

    struct DataNodeBase {

        virtual ~DataNodeBase() {}

        virtual std::string ToString() = 0;

        virtual bool IsEqualTo(std::shared_ptr<DataNodeBase> rhs) = 0;

        virtual std::shared_ptr<DataNodeBase> DeepCopy() = 0;
        
    };

} // namespace vm

} // namespace ws 

