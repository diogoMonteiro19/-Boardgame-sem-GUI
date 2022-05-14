#include "Fortaleza.h"

Fortaleza::Fortaleza():Continente("fortaleza",0,0,1,8)
{
}

Fortaleza::Fortaleza(string nome,bool conq) : Continente(nome, 0, 0, 1, 8,conq)
{
}
