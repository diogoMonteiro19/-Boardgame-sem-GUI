#ifndef CONTINENTE_H
#define CONTINENTE_H
#include "Territorio.h"
class Continente:public Territorio
{
public:
	Continente(string n, int ouro, int prod, int pontos, int res);
	Continente(string n, int ouro, int prod, int pontos, int res,bool conq);
};
#endif
