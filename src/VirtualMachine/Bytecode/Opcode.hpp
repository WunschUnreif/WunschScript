#pragma once 

#include <string>
#include <vector>

#include <cstdlib>

namespace ws {

namespace vm {

enum OpCode : uint8_t {
    /* -------- Arithmetic Operations -------- */
    UADD                        = 0,
    USUB                        = 1,

    ADD                         = 2,
    SUB                         = 3,
    MUL                         = 4,
    DIV                         = 5,
    REM                         = 6,

    /* -------- Comparison Operations -------- */
    LT                          = 7,
    LTE                         = 8,
    GT                          = 9,
    GTE                         = 10,

    EQ                          = 11,
    NE                          = 12,

    /* -------- Binary/Logical Operations -------- */
    BNOT                        = 13,
    BAND                        = 14,
    BXOR                        = 15,
    BOR                         = 16,

    LNOT                        = 17,
    LAND                        = 18,
    LOR                         = 19,

    /* -------- Object Operations -------- */
    DCOPY                       = 20,
    COPY                        = 21,
    WREF                        = 22,
    OPDEREF                     = 23,
    FCDEREF                     = 24,

    /* -------- Dict/List Operations -------- */
    ACCESS                      = 25,
    ACCESSL                     = 26,
    THIS                        = 27,

    /* -------- Function Operations -------- */
    FUNC                        = 28,
    PRECALL                     = 29,
    ARG                         = 30,
    CALL                        = 31,

    /* -------- Other Operations -------- */
    ASSIGN                      = 32,
    RET                         = 33,
    ENDP                        = 34,
    ENDPS                       = 35,

    IMMN                        = 36,

    IMML                        = 37,
    IMMD                        = 38,

    /* -------- Instructions with Argument -------- */
    ACCID                       = 128,
    ACCIDL                      = 129,

    IMMI                        = 130,
    IMMF                        = 131,
    IMMB                        = 132,
    IMMS                        = 133,

    PROC                        = 134,
    PARAM                       = 135,
    ARRPARAM                    = 136,

    BIND                        = 137,
    NAME                        = 138,
    GET                         = 139,
    GETL                        = 140,
    SET                         = 141,

    JFALSE                      = 142,
    JMP                         = 143,
    NEXT                        = 144,
    ITER                        = 145,

    SCOPE                       = 146,
    
    FILE                        = 147,
    LINE                        = 148,
};

constexpr int OpCodeSize = sizeof(OpCode);
bool OpCodeHasArgument(OpCode code);

std::string GetOpName(OpCode code);

bool OpCodeHasArgument(OpCode code);

}

}
