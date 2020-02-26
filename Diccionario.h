#ifndef _DICCIONARIO_PALABRAS_
#define _DICCIONARIO_PALABRAS_
#include "TablasHash.h"
#include "ArbolTrie.h"
using namespace std;
class DicPalabras{
	private:
		TablaHash Tabla;
		ArbolTrie Arbol;
	public:
		void vaciar(){
			Tabla.vaciar();
			Arbol.vaciar();
		}
		void insertar(string palabra){
			Tabla.insertar(palabra);
			Arbol.inserta(palabra);
		}
		bool consultar(string palabra){
			return Arbol.buscar(palabra);
		}
		int numElem(){
			return Tabla.numElem();
		}
		string anagra(string palabra){
			return Tabla.juanagra(palabra);
		}
		list<string>* aloca(string palabra){
			return Arbol.alocado(palabra);
		}
};
#endif
