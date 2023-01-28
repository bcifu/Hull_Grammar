grammar HullQuery;
query: (expr ';')* EOF; //prog is a list of epxressions

expr: expr '=' expr 
    | var 
    | func 
    | var '.' func;

func: ID '(' arglist ')' ('.' func)?;

arglist: (expr (',' expr)*)?;

var: type ID ('[' INT ']')? 
    | ID;

type: ID;

fragment DIGIT: '0' ..'9';

WS: [ \t] -> skip;
NL: [\r\n]+ -> skip; //deal with new lines
INT: DIGIT+;
ID: [a-zA-Z_][a-zA-Z_0-9]*;

