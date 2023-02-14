grammar HullQuery;
query: funcdecl*; //prog is a list of epxressions

body: (expr ';')*;

expr: decl '=' expr #assign
    | var           #variable
    | func          #function
    | var '.' func  #varfunc
    | immediate     #immed
	| RETURN expr   #return
    | expr op expr  #oper
    ;

func: ID '(' arglist ')' ('.' func)?;

arglist: (expr (',' expr)*)?;

decl: type ID ('[' INT ']')? ;

funcdecl: (type|VOID) ID '(' (paramlist|VOID) ')' '{' body '}';

paramlist: (type ID (',' type ID)*);

immediate: INT;

var: ID;

type: ID;

op: '+' #add
    |'-' #sub
    |'*' #mult
    |'\\' #div
    ;

fragment DIGIT: '0' ..'9';

RETURN: 'return';
VOID: 'void';
WS: [ \t] -> skip;
NL: [\r\n]+ -> skip; //deal with new lines
INT: DIGIT+;
ID: [a-zA-Z_][a-zA-Z_0-9]*;

