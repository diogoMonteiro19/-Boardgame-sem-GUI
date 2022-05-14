#ifndef MINA_H
#define MINA_H
#include "Continente.h"
class Mina :public Continente
{
public:
	Mina();
	Mina(string nome,bool conq);
	void skill(int ano,int turno)override;
};
#endif
