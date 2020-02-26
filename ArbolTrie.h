#ifndef _ARBOL_TRIE_
#define _ARBOL_TRIE_
#include <string>
#include <list>
#include "NodoTrie.h"
using namespace std;

class ArbolTrie
{	private:
		nodoTrie* raiz;
		unsigned int nElem;
		//Método Privado.
		void alocaux(string palabra, nodoTrie* nodo, list<string>* lista , string resultado, unsigned int i);
	public:
		ArbolTrie();
		~ArbolTrie();
		list<string>* alocado(string palabra);
		void inserta (string palabra);
		bool buscar (string palabra);
		void vaciar (void);
};

#endif
