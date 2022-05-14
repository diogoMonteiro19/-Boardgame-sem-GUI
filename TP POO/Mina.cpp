#include "Mina.h"

Mina::Mina():Continente("mina",1,0,1,5)
{
}

Mina::Mina(string nome,bool conq) : Continente(nome, 1, 0, 1, 5,conq)
{

}

void Mina::skill(int ano, int turno)
{
	if (turno <= 3) {
		ouro = 1;
	}
	if (turno > 3) {
		ouro = 2;
	}
}
