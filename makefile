a.out: 202.o ArbolTrie.o Interprete.o NodoTrie.o TablasHash.o nodo.o
	g++ 202.o ArbolTrie.o Interprete.o NodoTrie.o TablasHash.o nodo.o

202.o: 202.cpp Diccionario.h Interprete.h
	g++ -c 202.cpp

ArbolTrie.o: ArbolTrie.cpp ArbolTrie.h
	g++ -c ArbolTrie.cpp

Interprete.o: Interprete.cpp Interprete.h
	g++ -c Interprete.cpp

NodoTrie.o: NodoTrie.cpp NodoTrie.h
	g++ -c NodoTrie.cpp

TablasHash.o: TablasHash.cpp TablasHash.h
	g++ -c TablasHash.cpp

nodo.o: nodo.cpp nodo.h
	g++ -c nodo.cpp
