aux_source_directory(. SRC_VM)
aux_source_directory(DataRepresentation SRC_VM_DR)
aux_source_directory(Machine SRC_VM_M)
aux_source_directory(Machine/InstructionExecutor SRC_VM_M_EXE)

add_subdirectory(Bytecode/)

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
)

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

