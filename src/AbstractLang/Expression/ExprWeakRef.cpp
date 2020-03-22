#include "ExprWeakRef.hpp"
#include "GeneralDataNodeFactory.hpp"

using namespace ws::asl;

GeneralDataNode ExpressionWeakRef::Eval(Environment & env, bool asLval) {
    /// can only be right value 
    if(asLval) {
        env.ReportError(std::runtime_error("Weakref cannot serve as left value."));
        return GeneralDataNode();
    }

    auto refValue = ref->Eval(env);

    /// Generate weak ref
    auto refNode = std::make_shared<DataNodeWeakReference>();
    refNode->type = refValue.type;
    refNode->ptr = refValue.data;

    GeneralDataNode refGDN;
    refGDN.type = GeneralDataNode::DataType::TypeWeakReference;
    refGDN.data = refNode;

    return refGDN;
}

GeneralDataNode ExpressionOptionalDeref::Eval(Environment & env, bool asLval) {
    /// can only be right value 
    if(asLval) {
        env.ReportError(std::runtime_error("Opt.deref cannot serve as left value."));
        return GeneralDataNode();
    }

    auto weakref = expr->Eval(env);

    // typechecking
    if(weakref.type != GeneralDataNode::DataType::TypeWeakReference) {
        env.ReportError(std::runtime_error("Opt.deref can only apply on type weak_ref."));
        return GeneralDataNode();
    }

    // deref
    auto derefedNode = std::dynamic_pointer_cast<DataNodeWeakReference>(weakref.data)->ptr.lock();

    GeneralDataNode result = GeneralDataNodeFactory::MakeNilGDN();

    if(derefedNode) {
        result.type = std::dynamic_pointer_cast<DataNodeWeakReference>(weakref.data)->type;
        result.data = derefedNode;
    }

    return result;
}

GeneralDataNode ExpressionStrongDeref::Eval(Environment & env, bool asLval) {
    /// can only be right value 
    if(asLval) {
        env.ReportError(std::runtime_error("Force.deref cannot serve as left value."));
        return GeneralDataNode();
    }

    auto weakref = expr->Eval(env);

    // typechecking
    if(weakref.type != GeneralDataNode::DataType::TypeWeakReference) {
        env.ReportError(std::runtime_error("Force.deref can only apply on type weak_ref."));
        return GeneralDataNode();
    }

    // deref
    auto derefedNode = std::dynamic_pointer_cast<DataNodeWeakReference>(weakref.data)->ptr.lock();
    
    if(!derefedNode) {
        env.ReportError(std::runtime_error("Force.deref get nil."));
        return GeneralDataNode();
    }

    GeneralDataNode result;
    result.type = std::dynamic_pointer_cast<DataNodeWeakReference>(weakref.data)->type;
    result.data = derefedNode;

    return result;
}
