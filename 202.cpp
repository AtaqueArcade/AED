#include "Diccionario.h"
#include "Interprete.h"

int main(int argc, char** argv)
{
    string comando;
    interprete i;
    while ((cin >> comando) && !(i.interpretar(comando))){}
    return 0;
}

