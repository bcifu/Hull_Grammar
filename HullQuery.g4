grammar HullQuery;
query: funcdecl*; //prog is a list of epxressions

body: (expr ';')*;

expr: LAMBDA var '=>' '(' expr ')' #lambda
    | decl '=' expr #assign
    | var           #variable
    | func          #function
    | var '.' func  #varfunc
    | immediate     #immed
	| RETURN expr   #ret
    | expr op expr  #oper
    ;

func: ID '(' arglist ')' ('.' func)?;

arglist: (expr (',' expr)*)?;

decl: type ID ('[' INT ']')? ;

funcdecl: funcdeclret ID '(' (paramlist|VOID) ')' '{' body '}';

funcdeclret: (type ('[' INT ']')? | VOID);

paramlist: (decl (',' decl)*);

immediate: INT;

var: ID;

type: ID;

op: '+' #add
    |'-' #sub
    |'*' #mult
    |'\\' #div
    | '==' #eq
    ;

fragment DIGIT: '0' ..'9';

LAMBDA: 'lambda';
RETURN: 'return';
VOID: 'void';
WS: [ \t] -> skip;
NL: [\r\n]+ -> skip; //deal with new lines
INT: DIGIT+;
ID: [a-zA-Z_][a-zA-Z_0-9]*;

