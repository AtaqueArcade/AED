#ifndef _NODO_
#define _NODO_
#include <string>
#include <iostream>
using namespace std;
class nodo{
	private:
		//Atributos
		string Ord;
		string elemento;
		//Métodos privados
	public:
		//Métodos públicos
		nodo(void);
		bool sustituye(string orden, string palabra);
		//Métodos en línea
		bool esVacia()
		{
			return Ord == "";
		}
		bool coincidente(string palabra)
		{
			return palabra == Ord;
		}
		string getElem()
		{
			return elemento;
		}
};

#endif
