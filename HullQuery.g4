grammar HullQuery;
query: funcdecl; //prog is a list of epxressions

body: (expr ';')*;

expr: decl '=' expr 
    | var 
    | func 
    | var '.' func;

func: ID '(' arglist ')' ('.' func)?;

arglist: (expr (',' expr)*)?;

decl: type ID ('[' INT ']')? ;

funcdecl: (type|VOID) ID '(' (paramlist|VOID) ')' '{' '}';

paramlist: (type ID (',' type ID)*);

var: ID;

type: ID;

fragment DIGIT: '0' ..'9';

VOID: 'void';
FUNCTION: 'function';
WS: [ \t] -> skip;
NL: [\r\n]+ -> skip; //deal with new lines
INT: DIGIT+;
ID: [a-zA-Z_][a-zA-Z_0-9]*;

