#include "Continente.h"

Continente::Continente(string n, int ouro, int prod, int pontos, int res):Territorio(n,ouro,prod,pontos,res)
{
}

Continente::Continente(string n, int ouro, int prod, int pontos, int res, bool conq):Territorio(n,ouro,prod,pontos,res,conq)
{
}
