#ifndef PESCARIA_H
#define PESCARIA_H
#include "Ilhas.h"
class Pescaria :public Ilhas
{
public:
	Pescaria();
	Pescaria(string nome,bool conq);
	void skill(int ano, int turno)override;
};
#endif
