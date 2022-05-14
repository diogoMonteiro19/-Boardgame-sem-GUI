#include "Tecnologias.h"
#include<sstream>
using namespace std;
Tecnologias::Tecnologias(std::string nome, int custo):nome(nome),custo(custo),obtida(false)
{
}

std::string Tecnologias::getNome()
{
	return nome;
}

int Tecnologias::getCusto()
{
	return custo;
}

bool Tecnologias::getObtida()
{
	return obtida;
}

void Tecnologias::setObtida()
{
	obtida = true;
}

std::string Tecnologias::getAsString()
{
	ostringstream os;
	if (obtida == false)
	{
		os << nome << ", Custo: " << custo << "|| Nao adquirida"<< endl;
	}
	else
	{
		os << nome << ", Custo: " << custo << "|| Adquirida" << endl;
	}
	return os.str();
}
