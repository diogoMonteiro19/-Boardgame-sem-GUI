#include "Ilhas.h"

Ilhas::Ilhas(string n, int ouro, int prod, int pontos, int res):Territorio(n,ouro,prod,pontos,res)
{
}

Ilhas::Ilhas(string n, int ouro, int prod, int pontos, int res, bool conq) : Territorio(n, ouro, prod, pontos, res,conq)
{
}
