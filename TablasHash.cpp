#include "TablasHash.h"

//Métodos Privados

int TablaHash::funcionHash(string palabra)									//Hash Iterativo.
{
	unsigned int resultado = 0;
	unsigned int exponente = 1;
	for (unsigned int i=0; i<palabra.length(); i++)
	{
		exponente = exponente * 2;
		resultado = (resultado + (int) palabra[i] * exponente)*Prim;
	}	
	return (palabra.length()*resultado)%Tam;
}

string TablaHash::ordenacion(string palabra)								//Ordenacion de los string (No tiene en cuenta UC pero no es necesario)
{
	for (unsigned int i=1;i<palabra.length();i++)
	{
		int inf=0;
		int sup=i-1;
		char letra=palabra[i];
		while (inf <= sup)
		{
			int med = (inf+sup)/2;
			if (letra < palabra[med])
				sup=med-1;
			else
				inf=med+1;
		}
		for (int j=i-1; j>=inf; j--)
			palabra[j+1] = palabra[j];
		palabra[inf]=letra;
	}
	return palabra;
}

int TablaHash::HashOrd(string palabra)										//Hash de Juanagra, necesario que las palabras esten ordenadas
{
	string Ordenada = ordenacion(palabra);
	unsigned int resultado = 1;
	for (unsigned int i=0; i<palabra.length(); i++)
		resultado = (resultado + (int) Ordenada[i])*Prim;
	return ((palabra.length())+resultado)%Tam;
}

void TablaHash::insertarOrd(string palabra)									//Inserción en TablaJuanagra.
{
	string orden = ordenacion(palabra);
	unsigned int intentos = 0;
	unsigned int i=HashOrd(palabra);
	unsigned int j=i;
	if (!(TablaJuanagra[i].sustituye(orden, palabra)))
	{
		while(!(TablaJuanagra[i].sustituye(orden, palabra)))
		{
			i = redispersionOrd(j, intentos);
			intentos++;
		}
	}	
}

void TablaHash::redimensionar()												//Redimensiona las dos tablas 
{
	delete[] TablaJuanagra;
	int OTam = Tam;
	Tam = Tam * 3;
	nElem = 0;
	string *Tab = Tabla;
	Tabla = new string[Tam];
	TablaJuanagra = new nodo[Tam];
	for (int i=0; i<OTam; i++)
	if (Tab[i] != "") 
		insertar(Tab[i]);
	delete[] Tab;
}

//Métodos Públicos

TablaHash::TablaHash()		//Constructor
{
	Tam = TamInic;
	Tabla = new string[Tam];
	TablaJuanagra = new nodo[Tam];
	nElem = 0;
}

TablaHash::~TablaHash()		//Destructor
{
	delete[] Tabla;
	delete[] TablaJuanagra;
}
	
void TablaHash::insertar(string palabra){
	unsigned int intentos = 0;
	unsigned int i=funcionHash(palabra);
	unsigned int j = i;
	if (Tabla[i] != "" && Tabla[i] != palabra)
	{
		while (Tabla[i] != "" && Tabla[i] != palabra)
		{
			i = redispersion(j, intentos);
			intentos++;
		}
		if (Tabla[i] != palabra)
		{
			Tabla[i] = palabra;
			insertarOrd(palabra);
			nElem++;
		}	
	}
	else
	if (Tabla[i] != palabra)
	{
		Tabla[i] = palabra;
		insertarOrd(palabra);
		nElem++;
	}
	if (numElem()>0.75*Tam)
		redimensionar();
}
 	
bool TablaHash::busqueda(string palabra)
{
	unsigned int intentos = 0;
	unsigned int i = funcionHash(palabra);
	unsigned int j = i;
	if (Tabla[i] != "" && Tabla[i] != palabra){
		while (Tabla[i] != "" && Tabla[i] != palabra){
			i = redispersion(j, intentos);
			intentos++;}
		if (Tabla[i] == palabra)
			return true;
		else return false;
	}else
	if (Tabla[i] == palabra)
		return true;
	else return false;
}

void TablaHash::vaciar()
{
	Tam = TamInic;
	delete[] Tabla;
	delete[] TablaJuanagra;
	Tabla = new string[Tam];
	TablaJuanagra = new nodo[Tam];
	nElem = 0;
}

string TablaHash::juanagra(string palabra)
{
	unsigned int intentos = 0;
	unsigned int i = HashOrd(palabra);
	unsigned int j = i;
	string orden = ordenacion(palabra);
	if (!(TablaJuanagra[i].esVacia()) && !(TablaJuanagra[i].coincidente(orden)))
	{
		while (!(TablaJuanagra[i].esVacia()) && !(TablaJuanagra[i].coincidente(orden)))
		{
			i = redispersionOrd(j, intentos);
			intentos++;
		}
		if (TablaJuanagra[i].coincidente(orden))
			return TablaJuanagra[i].getElem();
		else return "";
	}else
	if (TablaJuanagra[i].coincidente(orden))
		return TablaJuanagra[i].getElem();
	else return "";
}

