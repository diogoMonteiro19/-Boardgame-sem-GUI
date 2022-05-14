#ifndef ILHAS_H
#define ILHAS_H
#include "Territorio.h"
class Ilhas :public Territorio
{
public:
	Ilhas(string n,int ouro,int prod,int pontos,int res);
	Ilhas(string n, int ouro, int prod, int pontos, int res,bool conq);
};
#endif
