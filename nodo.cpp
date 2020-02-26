#include "nodo.h"

bool nodo::sustituye(string orden, string palabra)
{
	if (Ord == "" || Ord == orden)
	{
		if ((Ord == orden && palabra < elemento) && (orden.length() == Ord.length()))
		{
			Ord = orden;
			elemento = palabra;
			return true;
		}
		else if (Ord == "")
				{
					Ord = orden;
					elemento = palabra;
					return true;
				}
	}
	return false;
	
}

nodo::nodo(void)
{
	
}
