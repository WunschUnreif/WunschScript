aux_source_directory(. SRC_VM)
aux_source_directory(DataRepresentation SRC_VM_DR)
aux_source_directory(Machine SRC_VM_M)
aux_source_directory(Machine/InstructionExecutor SRC_VM_M_EXE)
aux_source_directory(Shell SRC_VM_SHELL)

# --------- static libs ---------
add_library(WSVirtualMachine 
    ${SRC_VM}
    ${SRC_VM_DR}
    ${SRC_VM_M}
    ${SRC_VM_M_EXE}
)

target_include_directories(WSVirtualMachine PUBLIC 
    ./
    DataRepresentation/
    Machine/
    ../Bytecode
)

# --------- executable vm ---------
add_executable(wsvm 
    ${SRC_VM_SHELL}
)

add_dependencies(wsvm WSVirtualMachine)

target_link_libraries(wsvm PUBLIC 
    WSVirtualMachine
    WSVM_ByteCode

    WSParser
    WSAbstractLang
    WSSyntaxer
    WSTreeDiagram
    WSSupport

    libantlr4-runtime.a
)

target_link_directories(wsvm PUBLIC 
    ../../third/antlr4-cpp-runtime-4/dist
)

target_include_directories(wsvm PUBLIC 
    ./
    DataRepresentation/
    Machine/
    Shell/
    ../Bytecode/

    ../Syntaxer/
    ../AbstractLang/
    ../Parser/
    ../TreeDiagram/

    ../../third/antlr4-cpp-runtime-4/runtime/src
)

# --------- unit tests ---------
if(GEN_UT)
    
    add_executable(UTCodePrint UT/BCPrint.cpp)
    add_dependencies(UTCodePrint WSVM_ByteCode)
    target_include_directories(UTCodePrint PUBLIC ./)
    target_link_libraries(UTCodePrint PUBLIC WSVM_ByteCode)

    add_executable(UTCodeBuild UT/BCBuild.cpp)
    add_dependencies(UTCodeBuild WSVM_ByteCode)
    target_link_libraries(UTCodeBuild PUBLIC WSVM_ByteCode)
    target_include_directories(UTCodeBuild PUBLIC ./)

    add_executable(UTScopeDir UT/ScopeDir.cpp)
    add_dependencies(UTScopeDir WSVM_ByteCode WSVirtualMachine)
    target_link_libraries(UTScopeDir PUBLIC WSVM_ByteCode WSVirtualMachine)
    target_include_directories(UTScopeDir PUBLIC ./)

    add_executable(UTSingleStep UT/SingleStep.cpp)
    add_dependencies(UTSingleStep WSVM_ByteCode WSVirtualMachine)
    target_link_libraries(UTSingleStep PUBLIC WSVM_ByteCode WSVirtualMachine)
    target_include_directories(UTSingleStep PUBLIC ./)

endif()

