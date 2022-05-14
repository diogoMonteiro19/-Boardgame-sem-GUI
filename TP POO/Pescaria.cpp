#include "Pescaria.h"

Pescaria::Pescaria():Ilhas("pescaria",0,2,2,9)
{
}

Pescaria::Pescaria(string nome,bool conq) : Ilhas(nome, 0, 2, 2, 9,conq)
{
}

void Pescaria::skill(int ano, int turno)
{
	if (ano == 1) {
		prod = 2;
	}
	if (ano == 2) {
		prod = 4;
	}
}
