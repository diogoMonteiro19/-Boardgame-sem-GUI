#ifndef MONTANHA_H
#define MONTANHA_H
#include "Continente.h"
class Montanha:public Continente
{
	int turnoConquista;
public:
	Montanha();
	Montanha(string nome,bool conq);
	void skill(int ano,int turno)override;
};
#endif
