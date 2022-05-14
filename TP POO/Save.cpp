#include "Save.h"

Save::Save()
{
}

Save::Save(Mundo* novo, string nome):mundo(novo),nome(nome)
{
}

Mundo* Save::getMundo()
{
	return mundo;
}

string Save::getNome()
{
	return nome;
}

void Save::setMundo(Mundo* novo)
{
	mundo = novo;
}

void Save::setNome(string nome)
{
	this->nome = nome;
}
