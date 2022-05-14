#ifndef PLANICIE_H
#define PLANICIE_H
#include "Continente.h"
class Planicie :public Continente
{
public:
	Planicie();
	Planicie(string nome,bool conq);
	void skill(int ano,int turno)override;
};
#endif
