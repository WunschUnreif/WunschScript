#pragma once

#include "Environment/Environment.hpp"
#include "Environment/Scope.hpp"

#include "DataRepresentation/DataNode.hpp"
#include "DataRepresentation/DataNodeBase.hpp"
#include "DataRepresentation/GeneralDataNode.hpp"

#include "Expression/ExpressionBase.hpp"
#include "Expression/ExprBin.hpp"
#include "Expression/ExprCompare.hpp"
#include "Expression/ExprID.hpp"
#include "Expression/ExprLiteral.hpp"
#include "Expression/ExprLogical.hpp"
#include "Expression/ExprMemberAccess.hpp"
#include "Expression/ExprUnary.hpp"
#include "Expression/ExprEqual.hpp"
#include "Expression/ExprAddMinus.hpp"
#include "Expression/ExprFuncCall.hpp"
#include "Expression/ExprMultDiv.hpp"

#include "Statement/Statement.hpp"
#include "Statement/StmtAssignment.hpp"
#include "Statement/StmtExpr.hpp"
#include "Statement/StmtReturn.hpp"
#include "Statement/StmtVarDef.hpp"
#include "Statement/StmtCond.hpp"
#include "Statement/StmtWhileLoop.hpp"
