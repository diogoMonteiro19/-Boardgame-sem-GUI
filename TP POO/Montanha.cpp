#include "Montanha.h"

Montanha::Montanha():Continente("montanha",0,0,1,6)
{
}

Montanha::Montanha(string nome,bool conq) : Continente(nome, 0, 0, 1, 6,conq)
{
}

void Montanha::skill(int ano, int turno)
{
	if ((turno - turnoConquista) == 2) {
		prod = 1;
	}
}
