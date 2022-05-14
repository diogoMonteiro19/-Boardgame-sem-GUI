#ifndef CASTELO_H
#define CASTELO_H
#include "Continente.h"
class Castelo :public Continente
{
public:
	Castelo();
	Castelo(string nome,bool conq);
	void skill(int ano, int turno)override;
};
#endif
