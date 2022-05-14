#include "Castelo.h"

Castelo::Castelo():Continente("castelo",1,3,1,7)
{
}

Castelo::Castelo(string nome,bool conq):Continente(nome, 1, 3, 1, 7,conq)
{
}

void Castelo::skill(int ano, int turno)
{
	if (turno <= 2) {
		prod = 3;
	}
	else {
		prod = 0;
	}
}
