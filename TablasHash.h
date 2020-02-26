#ifndef _TABLA_HASH_
#define _TABLA_HASH_
#include <iostream>
#include <string>
#include <list>
#include "nodo.h"
using namespace std;
class TablaHash{
	private:
		//Atributos.
		string *Tabla;
		nodo *TablaJuanagra;							//Tabla de dispersion cerrada para el comando Juanagra, utiliza objetos nodo.
		static const unsigned int Prim = 31;			//Num. Primo para dispersión.
		static const unsigned int TamInic = 997;
		unsigned int Tam;
		int nElem;										//nElem Tabla < nElem TablaJuanagra.
		
		//Métodos privados.
		int funcionHash(string palabra);				// Hash Tabla.
		void insertarOrd(string palabra);				// Inserción en TablaJuanagra.
		int HashOrd(string palabra);					// Hash TablaJuanagra.
		void redimensionar();
		int contarUC(string palabra);
		//Métodos en línea
		int redispersion(unsigned int hash, int clave)		//Redisp. Tabla.
		{
			unsigned int resultado=((hash + clave*clave));
			return resultado%Tam;
		}
		int redispersionOrd(unsigned int hash, int clave)	//Redisp. TablaJuanagra.
		{
			unsigned int resultado=((hash + clave*clave));
			return resultado%Tam;
		}
		string ordenacion(string palabra);
	public:
		//Métodos públicos.
		TablaHash();									//constructor.
		~TablaHash();									//destructor.
		void insertar(string palabra);
		bool busqueda(string palabra);
		void vaciar();
		string juanagra(string palabra);
		//Métodos en línea
		int numElem()
		{
			return nElem;
		}
};
#endif
