aux_source_directory(. SRC_VM2)
aux_source_directory(Objects SRC_VM2_OBJ)

# --------- static libs ---------
add_library(WSVM2 STATIC
    ${SRC_VM2_OBJ}
)

target_include_directories(WSVM2 PUBLIC 
    ./
    DataRepresentation/
    Machine/

    ../VirtualMachine/Bytecode
)

# --------- executable vm ---------


# --------- unit tests ---------
if(GEN_UT)

endif()

