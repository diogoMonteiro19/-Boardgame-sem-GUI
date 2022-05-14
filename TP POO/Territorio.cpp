#include "Territorio.h"
#include <sstream>

int Territorio::minas = 0;
int Territorio::planicies = 0;
int Territorio::fortalezas = 0;
int Territorio::montanhas = 0;
int Territorio::dunas = 0;
int Territorio::castelos = 0;
int Territorio::refugio = 0;
int Territorio::pescaria = 0;

Territorio::Territorio(string n) :nome(n), ouro(1), prod(1), pontos(0), resistencia(9), conquistado(true)
{
}

Territorio::Territorio(string nome, int ouro, int prod, int pontos, int res) : nome(nome), ouro(ouro), prod(prod), pontos(pontos), resistencia(res), conquistado(false)
{
	if (nome == "planicie")
		this->nome = nome + to_string(++planicies);
	if (nome == "montanha")
		this->nome = nome + to_string(++montanhas);
	if (nome == "mina")
		this->nome = nome + to_string(++minas);
	if (nome == "fortaleza")
		this->nome = nome + to_string(++fortalezas);
	if (nome == "duna")
		this->nome = nome + to_string(++dunas);
	if (nome == "castelo")
		this->nome = nome + to_string(++castelos);
	if (nome == "refugiodospiratas")
		this->nome = nome + to_string(++refugio);
	if (nome == "pescaria")
		this->nome = nome + to_string(++pescaria);

}
Territorio::Territorio(string nome, int ouro, int prod, int pontos, int res,bool conq) : nome(nome), ouro(ouro), prod(prod), pontos(pontos), resistencia(res), conquistado(conq)
{

}

string Territorio::getNome() const
{
	return nome;
}

int Territorio::getResistencia() const
{
	return resistencia;
}

int Territorio::getOuro() const
{
	return ouro;
}

int Territorio::getProd() const
{
	return prod;
}

bool Territorio::getConquistado() const
{
	return conquistado;
}

void Territorio::setConquistado()
{
	if (conquistado == false)
		conquistado = true;
	else
		conquistado = false;
}

string Territorio::toString() const
{
	ostringstream oss;

	oss << "Territorio Nome: " << nome << " | Ouro: " << ouro << " | Prod: " << prod << " | Pontos: " << pontos << " | Res: " << resistencia << " | Conq: " << conquistado;

	return oss.str();
}

void Territorio::skill(int ano, int turno)
{
}

int Territorio::getPont() const
{
	return pontos;
}


