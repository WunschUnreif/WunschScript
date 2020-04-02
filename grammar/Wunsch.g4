grammar Wunsch;

program
    : br (stmt)* br
    ;

stmt
    : expr          (ENDL | (br ';' br) | EOF)
    | varDef        (ENDL | (br ';' br) | EOF)
    | assignment    (ENDL | (br ';' br) | EOF)
    | condStmt      (ENDL | (br ';' br) | EOF)
    | whileStmt     (ENDL | (br ';' br) | EOF)
    | forStmt       (ENDL | (br ';' br) | EOF)
    | returnStmt    (ENDL | (br ';' br) | EOF)
    ;

expr
    : literal                                               #literalExpr
    | funcDef                                               #funDefLiteral
    | THIS                                                  #thisExpr
    | ID                                                    #idExpr
    | '(' br expr br ')'                                    #bracketExpr
    | '<' br expr br '>'                                    #deepCopyExpr
    | '<' br expr ( br ID br '=' br expr br)+ br '>'        #deepCopyModifyExpr
    | expr br '.' br ID                                     #memberAccessExpr
    | expr '[' br expr br ']'                               #bracoAccessExpr
    | expr '(' br exprList br ')'                           #funcallExpr
    | expr op=('?'|'!')                                     #derefExpr
    | '@' expr                                              #weakrefExpr
    | '!' expr                                              #logiNotExpr
    | '~' expr                                              #binNotExpr
    | op=('+'|'-') expr                                     #unaryPMExpr
    | expr op=('*'|'/'|'%') br expr                         #multdivExpr
    | expr op=('+'|'-') br expr                             #addMinExpr
    | expr op=('<'|'<='|'>='|'>') br expr                   #compareExpr
    | expr op=('=='|'!=') br expr                           #equalExpr
    | expr '&' br expr                                      #binAndExpr
    | expr '^' br expr                                      #binXorExpr
    | expr '|' br expr                                      #binOrExpr
    | expr '&&' br expr                                     #logiAndExpr
    | expr '||' br expr                                     #logiOrExpr
    ;

literal 
    : integerLiteral 
    | floatLiteral 
    | boolLiteral 
    | stringLiteral
    | listLiteral 
    | dictLiteral 
    | nilLiteral;

/* Basic typed literals */
integerLiteral
    : DEC_INT   #decInteger
    | OCT_INT   #octInteger
    | HEX_INT   #hexInteger
    ;
floatLiteral  : FLOAT;
boolLiteral   : BOOLEANLIT;
stringLiteral : STRING+;
listLiteral   : '[' br (expr ( br ',' br expr)*)? br ']';
dictLiteral   : '{' br (ID br ':' br expr ( ((br ',' br)|ENDL) ID br ':' br expr)*)? br '}';
nilLiteral    : 'nil';

/* Varible define and assignment */
varDef 
    : 'var' ID br '=' br expr       #immediateVarDef
    | 'var' ID                      #plainVarDef
    ;
assignment 
    : expr br '=' br expr           #exprAssign
    ;

/* Function define */
funcDef : '(' br idList br ')'
            (br '[' br cap=idList br ']' br)? 
            '=>' br (body=stmtBlock | res=expr)     #fixedFunc

        | '(' br (param=idList br ',' br)? '[' br ID br ']' br ')' br
            ( br '[' br cap=idList br ']' br)?
             '=>' br (body=stmtBlock | res=expr)    #arrTailFunc
        ;

idList
    : ID (br ',' br ID)*
    |
    ;

stmtBlock
    : '{' br (stmt)* br '}'
    ;

exprList
    : expr (br ',' br expr)*
    |
    ;

condStmt : 'if' expr stmtBlock (br 'else' br (elbr=stmtBlock|elif=condStmt))?;
whileStmt : 'while' expr stmtBlock;
forStmt : 'for' ID 'in' expr stmtBlock;
returnStmt : 'return' expr;

/*************** LEXICAL PART ***************/

// Integers
DEC_INT : ('1'..'9') ('0'..'9')*;
OCT_INT : '0' ('0'..'7')*;
HEX_INT : '0x' ('0'..'9' | 'a'..'f' | 'A'..'F')+;

// Floats
FLOAT : ('0'| (('1'..'9') ('0'..'9')*)) 
        '.' ('0'..'9')+ 
        (('e' | 'E') ('+'|'-')? ('0'| (('1'..'9') ('0'..'9')*)))?;

// Boolean
BOOLEANLIT : 'true' | 'false';

// String
STRING : '"' (ESC | ~["\\])* '"';
ESC : '\\' [abnrtvf\\"0];

// this
THIS : 'this';

// identifier
ID : ('_' | ('a'..'z') | ('A'..'Z')) ('_' | ('a'..'z') | ('A'..'Z') | '0'..'9')* ;

// comment
COMMENT : '#' .*? ENDL -> skip;

// deliminater after statements.
WS : (' '|'\t') -> skip;

br : ENDL?;

// end line
ENDL : ('\n' WS*)+;
