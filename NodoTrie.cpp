#include "NodoTrie.h"

nodoTrie::nodoTrie(char letra)
{
	caracter = letra;
	sig = NULL;
	ptr = NULL;
}

nodoTrie::nodoTrie()
{
	sig = NULL;
	ptr = NULL;
}

nodoTrie::~nodoTrie()
{
	if (ptr == this)
		ptr = NULL;
	delete ptr;
	delete sig;
}

void nodoTrie::insertar(char letra, nodoTrie* nodoInsertar)
{
	if (letra=='$')
	{
		caracter = '$';
		ptr = nodoInsertar;
	}
	else{
		nodoTrie* nodoActual = this;
		while (nodoActual->sig != NULL && (unsigned) nodoActual->sig->caracter < (unsigned) letra)
			nodoActual = nodoActual->sig;
		if (nodoActual != NULL && (unsigned) nodoActual->sig->caracter == (unsigned) letra)
			nodoActual->sig->ptr = nodoInsertar;
		else{
			nodoTrie* nodoAux = new nodoTrie(letra);
			nodoAux->sig = nodoActual->sig;
			nodoActual->sig = nodoAux;
			nodoAux->ptr = nodoInsertar;
		}	
	}
}	

void nodoTrie::TomaNuevo(char letra)
{
	nodoTrie* nodoActual = this;
	while (nodoActual->sig != NULL && (unsigned) nodoActual->sig->caracter < (unsigned) letra)
		nodoActual = nodoActual->sig;
	if (nodoActual->sig == NULL)
	{
		nodoActual->sig = new nodoTrie(letra);
		nodoActual->sig->ptr = new nodoTrie();
	}
	else if (nodoActual->sig != NULL && (unsigned) nodoActual->sig->caracter != (unsigned) letra)
			{
				nodoTrie* aux = new nodoTrie(letra);
				aux->sig = nodoActual->sig;
				nodoActual->sig = aux;
				aux->ptr = new nodoTrie();
			}		
}

nodoTrie* nodoTrie::consultar(char letra)									//Devuelve el nodo hijo que es apuntado por esa letra
{
	nodoTrie* nodoActual = this;
	if (letra == '$')
		return nodoActual->ptr;
	while (nodoActual->sig != NULL && (unsigned) nodoActual->sig->caracter < (unsigned) letra)
		nodoActual = nodoActual->sig;
	if (nodoActual->sig != NULL && (unsigned) nodoActual->sig->caracter == (unsigned) letra)
		return nodoActual->sig->ptr;
	else return NULL;
}
	
nodoTrie* nodoTrie::Hermano(void)											//Devuelve el nodo Hermano del nodo sobre el que 
{																			//se hace la llamada, como siguiente Elemento en acceso secuencial
	if (this->sig != NULL)
		return this->sig;
	else return NULL;
}

char nodoTrie::ElementoActual(void)											//Devuelve el caracter correspondiente al elemento actual del nodo
{
	return caracter;
}

bool nodoTrie::esUltimo(void)												//Condicion que evita el desbordamiento del 
{
	if (this->sig == NULL)
		return true;
	else return false;
}
