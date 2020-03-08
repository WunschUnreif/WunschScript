grammar Wunsch;

program
    : (stmt)*
    ;

stmt
    : expr ';'        
    | varDef ';'      
    | assignment ';'  
    | condStmt        
    | whileStmt       
    | forStmt         
    | returnStmt ';' 
    ;

expr
    : literal                           #literalExpr
    | funcDef                           #funDefLiteral
    | THIS                              #thisExpr
    | ID                                #idExpr
    | '(' expr ')'                      #bracketExpr
    | '<' expr '>'                      #deepCopyExpr
    | expr '.' ID                       #memberAccessExpr
    | expr '[' expr ']'                 #bracoAccessExpr
    | expr '(' exprList ')'             #funcallExpr
    | '!' expr                          #logiNotExpr
    | '~' expr                          #binNotExpr
    | op=('+'|'-') expr                 #unaryPMExpr
    | expr op=('*'|'/'|'%') expr        #multdivExpr
    | expr op=('+'|'-') expr            #addMinExpr
    | expr op=('<'|'<='|'>='|'>') expr  #compareExpr
    | expr op=('=='|'!=') expr          #equalExpr
    | expr '&' expr                     #binAndExpr
    | expr '^' expr                     #binXorExpr
    | expr '|' expr                     #binOrExpr
    | expr '&&' expr                    #logiAndExpr
    | expr '||' expr                    #logiOrExpr
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
listLiteral   : '[' (expr (',' expr)*)? ']';
dictLiteral   : '{' (ID ':' expr (',' ID ':' expr)*)? '}';
nilLiteral    : 'nil';

/* Varible define and assignment */
varDef 
    : 'var' ID '=' expr     #immediateVarDef
    | 'var' ID              #plainVarDef
    ;
assignment 
    : expr '=' expr         #exprAssign
    ;

/* Function define */
funcDef : '(' idList ')' '=>' stmtBlock                     #fixedFunc
        | '(' (idList ',')? '[' ID ']' ')' '=>' stmtBlock   #arrTailFunc
        ;

idList
    : ID (',' ID)*
    |
    ;

stmtBlock
    : '{' (stmt)* '}'
    ;

exprList
    : expr (',' expr)*
    |
    ;

condStmt : 'if' expr stmtBlock ('else' stmtBlock)?;
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
COMMENT : '#' .*? '\n' -> skip;

// deliminater after statements.
WS : (' '|'\t'|'\n') -> skip;
