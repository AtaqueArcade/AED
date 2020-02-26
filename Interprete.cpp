#include "Interprete.h"
interprete::interprete()
{

}

string interprete::normalizar (string palabra)
{
    string salida;
    for(unsigned int i = 0; i < palabra.length(); i++)
    {
        switch ( palabra[i] )
        {
        case 'a'...'z':
            salida += toupper(palabra[i]);
            break;
        case (char)0xC3:
            if ((palabra[i+1]==(char)0xA1)||(palabra[i+1]==(char)0x81))
		{
		   salida += 'A';
                   i++;
                }
                else
                if ((palabra[i+1]==(char)0xA9)||(palabra[i+1]==(char)0x89))
		    {
			salida+= 'E';
			i++;
		    }
                    else
                    if ((palabra[i+1]==(char)0xAD)||(palabra[i+1]==(char)0x8D))
			{
                           salida+= 'I';
			   i++;
			}
                        else
                        if ((palabra[i+1]==(char)0xB3)||(palabra[i+1]==(char)0x93))
			    {
                               salida+= 'O';
			       i++;
                            }
                            else
                            if ((palabra[i+1]==(char)0xBA)||(palabra[i+1]==(char)0x9A))
			 	{
                                   salida+= 'U';
				   i++;
  				}
                                else
                                if ((palabra[i+1]==(char)0xBC)||(palabra[i+1]==(char)0x9C))
				    {
                                       salida+= 0xC3;
                                       salida+= 0x9C;
				       i++;
                                    }
                                    else
                                    if ((palabra[i+1]==(char)0xB1)||(palabra[i+1]==(char)0x91))
                                        {
                                           salida+= 0xC3;
                                           salida+= 0x91;
					   i++;
                                        }
					else
					{
					   salida+= 0xC3;
					   salida+= palabra[i+1];
					   i++;
					}
					break;
	default:
	salida+= palabra[i];
	break;
        }
    }
    return salida;
}
void interprete::insertar(void)
{
	int i = 0;
	string palabra;
	while ((cin >> palabra) && (palabra != "</insertar>"))
	{
		diccionario.insertar(normalizar(palabra));
		i++;
	}
	cout << "Insertando: " << i << " palabras" << endl;
	cout << "Total diccionario: " << diccionario.numElem() << " palabras" << endl;
}

void interprete::vaciar(void)
{
	diccionario.vaciar();
	cout << "Vaciando" << endl << "Total diccionario: " << diccionario.numElem() << " palabras" << endl;
}

void interprete::buscar(void)
{
	string palabra;
	cin >> palabra;
	if (diccionario.consultar(normalizar(palabra)))
		cout << "Buscando: " << normalizar(palabra) << " -> Encontrada" << endl;
	else cout << "Buscando: " << normalizar(palabra) << " -> No encontrada" << endl;
}

void interprete::partidas(void)
{
	string entrada;
	cout << "Partidas:";
	while ((cin >> entrada) && (entrada != "</partidas>"))
	{
		cout << " " << normalizar(entrada);
	}
	cout << endl << "No implementado"<< endl;
}

void interprete::alocado(void)
{
	string entrada;
	cin >> entrada;
	cout << "Alocado: " << normalizar(entrada) << " ->";
	list<string>* lista = diccionario.aloca(normalizar(entrada));
	list<string>::iterator EA = lista->begin(); 
	while (EA != lista->end()){
		cout << " " << *EA;
		EA++;
	}
	cout<< endl;
	delete lista;
}

void interprete::cesar(void)
{
	string entrada;
	cin >> entrada;
	cout << "César: " << normalizar(entrada) << endl << "No implementado" << endl;
}

void interprete::juanagrama(void)
{
	string entrada, resultado;
	cin >> entrada;
	resultado = diccionario.anagra(normalizar(entrada));
	if (resultado != "")
		cout << "Juanagrama: " << normalizar(entrada) << " -> " << resultado << endl;
		else cout << "Juanagrama: " << normalizar(entrada) << " ->" << endl;
}

void interprete::saco(void)
{
	string entrada;
	cout << "Saco:";
	for ( int i=0; i < 2; i++)
	{
		cin >> entrada;
		cout << " "  << normalizar(entrada);
	}
	cout << endl << "No implementado" << endl;
}

void interprete::consome(void)
{
	string entrada;
	cin >> entrada;
	cout << "Consomé: " << normalizar(entrada) << endl << "No implementado" << endl;
}

void interprete::alargapalabras(void)
{
	string entrada;
	cin >> entrada;
	cout << "Alarga: " << normalizar(entrada) << endl << "No implementado" << endl;
}

void interprete::salida(void)
{
    cout << "Saliendo..." << endl;
}

bool interprete::interpretar(string comando)
{
	if (comando == "<insertar>"){
		insertar();
		return false;
	}else if (comando == "<vaciar>"){
		vaciar();
		return false;
	}else if (comando == "<buscar>"){
		buscar();
		return false;
	}else if (comando == "<partidas>"){
		partidas();
		return false;
	}else if (comando == "<alocado>"){
		alocado();
		return false;
	}else if (comando == "<césar>"){
		cesar();
		return false;
	}else if (comando == "<juanagra>"){
		juanagrama();
		return false;
	}else if (comando == "<saco>"){
		saco();
		return false;
	}else if (comando == "<consomé>"){
		consome();
		return false;
	}else if (comando == "<alarga>"){
		alargapalabras();
		return false;
	}else if (comando == "<exit>"){
		salida();
		return true;
	}else return false;
}
