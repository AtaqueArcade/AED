#ifndef _NODO_TRIE_
#define _NODO_TRIE_
#include "stdlib.h"
using namespace std;
class nodoTrie{
	private:									//Atributos
		nodoTrie *ptr;
		nodoTrie *sig;
		char caracter;
	public:
		nodoTrie(char letra);					//Constructores
		nodoTrie();								//Constructores: Sobrecargado
		~nodoTrie();
		void TomaNuevo(char letra);
		void insertar(char letra, nodoTrie* nodoInsertar);
		nodoTrie* consultar(char letra);
		void vaciar(void);
		
		nodoTrie* Hermano(void);				//Métodos para Iterador
		char ElementoActual(void);
		bool esUltimo(void);
		nodoTrie* nodosigHijo(void){
			return this->consultar(this->Hermano()->ElementoActual());
		}
};
#endif
