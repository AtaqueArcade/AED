#ifndef _INTERPRETE_
#define _INTERPRETE_
#include "Diccionario.h"

#include <iostream>
using namespace std;
class interprete{
	private:
		//Atributos
		string comando;
		DicPalabras diccionario;
	public:
		//Métodos públicos
		string normalizar (string palabra);
		interprete();
		void insertar(void);
		void vaciar(void);
		void buscar(void);
		void partidas(void);
		void alocado(void);
		void cesar(void);
		void juanagrama(void);
		void saco(void);
		void consome(void);
		void alargapalabras(void);
		void salida(void);
		bool interpretar(string comando);

};
#endif
