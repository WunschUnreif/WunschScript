#ifndef __WS_ASL_DATA_NODE_BASE_HPP__
#define __WS_ASL_DATA_NODE_BASE_HPP__

#include <string>
#include <memory>

namespace ws {

namespace asl {

    struct DataNodeBase {

        virtual ~DataNodeBase() {}

        virtual std::string ToString() = 0;

        virtual bool IsEqualTo(std::shared_ptr<DataNodeBase> rhs) = 0;

        virtual std::shared_ptr<DataNodeBase> DeepCopy() = 0;
        
    };

} // namespace asl

} // namespace ws 

#endif // __WS_ASL_DATA_NODE_BASE_HPP__
