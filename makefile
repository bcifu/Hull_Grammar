all:
	g++ *.cpp -I /usr/include/antlr4-runtime -l antlr4-runtime

antlr4:
	antlr4 -Dlanguage=Cpp HullQuery.g4
