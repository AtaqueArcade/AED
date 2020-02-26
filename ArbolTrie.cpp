#include "ArbolTrie.h"

ArbolTrie::ArbolTrie()
{
	raiz = new nodoTrie();
}

ArbolTrie::~ArbolTrie()														//Destructor recursivo
{
	delete raiz;
}

void ArbolTrie::inserta (string palabra)									//Método de inserción
{
	nodoTrie* posicion = raiz;
	for (unsigned int i = 0; i < palabra.length(); i++)
	{
		if (posicion->consultar(palabra[i]) == NULL)
			posicion->TomaNuevo(palabra[i]);
		posicion = posicion->consultar(palabra[i]);
	}
	if (posicion->consultar('$') != posicion)
		nElem++;
	posicion->insertar('$', posicion);
}

bool ArbolTrie::buscar(string palabra)										//Método de consulta
{
	nodoTrie* posicion = raiz;
	for (unsigned int i=0; i < palabra.length(); i++)
	{
		if (posicion->consultar(palabra[i]) == NULL)
			return false;
			else
			posicion = posicion->consultar(palabra[i]);
	}
	if (posicion->consultar('$') == posicion)
		return true;
		else return false;
}

void ArbolTrie::vaciar()
{
	delete raiz;
	raiz = new nodoTrie();
}

list<string>* ArbolTrie::alocado(string palabra)
{
	list<string>* lista = new list<string>();
	nodoTrie* nodo = raiz;
	int i = 0;
	alocaux(palabra, nodo, lista, "", i);									//Primera llamada al método recursivo
	return lista;
}

void ArbolTrie::alocaux(string palabra, nodoTrie* nodo, list<string>* lista, string resultado, unsigned int i)
{																			//Método Recursivo
	if (i == palabra.length() && nodo->consultar('$') == nodo)				//Cuando se acaba la palabra, la inserta en la lista
	{
		lista->push_back(resultado);
	}
	else	
	if (palabra[i] != '-')													//Caracteres normales y unicode
	{
		nodo = nodo->consultar(palabra[i]);
		if (nodo != NULL)
			alocaux(palabra, nodo, lista, resultado+palabra[i], i+1);		//Llamada recursiva, añade a la cadena resultado las letras de los nodos
	}
	else
	if (palabra[i] == '-')
	{
		while (!nodo->esUltimo())											//Asegura que el iterador no se salga del Arbol
		{
			if (nodo->Hermano()->ElementoActual() < 0)
			{																//Llamada recursiva en caso especial de caracter Unicode
				alocaux(palabra, nodo->nodosigHijo()->nodosigHijo(), lista, resultado+nodo->Hermano()->ElementoActual()+nodo->nodosigHijo()->Hermano()->ElementoActual(), i+1);
				if (!nodo->nodosigHijo()->Hermano()->esUltimo())
				alocaux(palabra, nodo->nodosigHijo()->Hermano()->nodosigHijo(), lista, resultado+nodo->Hermano()->ElementoActual()+nodo->nodosigHijo()->Hermano()->Hermano()->ElementoActual(), i+1);
			}
			else 
				alocaux(palabra, nodo->nodosigHijo(), lista, resultado+nodo->Hermano()->ElementoActual(), i+1);
			nodo = nodo->Hermano();											//Recorre todos los nodos hermanos del Arbol
		}
	}
}
