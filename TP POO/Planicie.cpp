#include "Planicie.h"

Planicie::Planicie():Continente("planicie",1,1,1,5)
{
}

Planicie::Planicie(string nome,bool conq) : Continente(nome, 1, 1, 1, 5,conq)
{
}



void Planicie::skill(int ano, int turno)
{
    if (ano == 1) {
        prod = 1;
    }
    if (ano == 2) {
        prod = 2;
    }
}
