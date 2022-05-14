#include "Jogador.h"
#include <cstdlib>
#include<sstream>
#include <ctime>

Jogador::Jogador() :pontuacao(0), forca_militar(1), ouro(1), prod(1), sorte(0), max_ouro(3), max_prod(3), max_forcaM(3), conq_inicial(false)
{
	srand((int)time(0));
}

int Jogador::getPont() const
{
	return pontuacao;
}

int Jogador::getOuro() const
{
	return ouro;
}

int Jogador::getProd() const
{
	return prod;
}

int Jogador::getForcaM() const
{
	return forca_militar;
}

int Jogador::getSorte() const
{
	return sorte;
}

int Jogador::getMaxOuro() const
{
	return max_ouro;
}

int Jogador::getMaxProd() const
{
	return max_prod;
}

int Jogador::getMaxForcaM() const
{
	return max_forcaM;
}

int Jogador::getGanhoOuro() const
{
	int soma = 0;

	for (unsigned int i = 0; i < conquistas.size(); i++)
	{
		soma += conquistas[i]->getOuro();
	}

	return soma;
}

int Jogador::getGanhoProd() const
{
	int soma = 0;

	for (unsigned int i = 0; i < conquistas.size(); i++)
	{
		soma += conquistas[i]->getProd();
	}

	return soma;
}

bool Jogador::getConq()
{
	return conq_inicial;
}

void Jogador::aumentaPont(int aumento)
{
	pontuacao += aumento;
}

void Jogador::setOuro(int o)
{
	if (o >= 0 && o <= max_ouro)
	{
		ouro = o;
	}
	if (o > max_ouro)
		ouro = max_ouro;
}

void Jogador::setProd(int p)
{
	if (p >= 0 && p <= max_prod)
	{
		prod = p;
	}
	if (p > max_prod)
		prod = max_prod;
}

void Jogador::contaPont()
{
	pontuacao = 0;
	auto it = conquistas.begin();
	while (it != conquistas.end())
	{
		pontuacao += (*it)->getPont();
		it++;
	}
}

string Jogador::compraOuro()
{
	if (prod >= 2) {
		if (ouro == max_ouro) {
			return "Nao e posivel adquirir mais ouro\n";
		}
		prod -= 2;
		ouro += 1;
		return "Adquiriu 1 de ouro\n";
	}
	else
		return "Nao tem produtos suficiente\n";
}

string Jogador::compraProd()
{
	if (ouro >= 2) {
		if (prod == max_prod) {
			return "Nao e posivel adquirir mais produtos\n";
		}
		ouro -= 2;
		prod += 1;
		return "Adquiriu 1 produto\n";
	}
	else
		return "Nao tem ouro suficiente\n";
}

string Jogador::compraMilitar()
{
	if (prod >=1 && ouro>=1) {
		if (forca_militar == max_forcaM) {
			return "Nao pode obter mais forca militar\n";
		}
		prod -= 1;
		ouro -= 1;
		forca_militar += 1;
		return "Adquiriu 1 de forca militar\n";
	}
	else
		return "Nao tem ouro nem produtos suficientes\n";
}

void Jogador::setForcaM(int fm)
{
	if (fm >= 0 && fm <= max_forcaM)
	{
		forca_militar = fm;
	}
	if (fm > max_forcaM)
		forca_militar = max_forcaM;
}

int Jogador::calculaForcaDado()
{
	sorte = (rand() % 6 + 1);
	return forca_militar + sorte;
}

void Jogador::addTerritorio(Territorio *t)
{
	conquistas.push_back(t);
}

void Jogador::recolheRecursos()
{
	setOuro(ouro + getGanhoOuro());
	setProd(prod + getGanhoProd());
}

string Jogador::adquireTec(Tecnologias* tec)
{
	if (tec_adquiridas.empty())
	{
		tec_adquiridas.push_back(tec);
		ouro -= tec->getCusto();
		tec->setObtida();
		return "Tecnologia adquirida com sucesso\n";
	}
	auto it = tec_adquiridas.begin();
	while (it != tec_adquiridas.end())
	{
		if (tec->getNome() == (*it)->getNome())
		{
			return "ja possui esta tecnologia\n";
		}
		it++;
	}
	tec_adquiridas.push_back(tec);
	tec->setObtida();
	if (tec->getNome() == "dronesmilitares")
	{
		max_forcaM = 5;
	}
	if (tec->getNome() == "bancocentral")
	{
		max_ouro = 5;
		max_prod = 5;
	}
	ouro -= tec->getCusto();
	return "Tecnologia adquirida com sucesso\n";
}


bool Jogador::verificaTec(string nome)const
{
	if (tec_adquiridas.empty())
	{
		return false;
	}
	auto it = tec_adquiridas.begin();
	while (it != tec_adquiridas.end()) {
		if ((*it)->getNome() == nome)
		{
			return true;
		}
		it++;
	}
	return false;
}

string Jogador::trataInvasao(int forca)
{
	ostringstream os;
	string n=(conquistas.back())->getNome();
	if (verificaTec("defesasterritoriais"))
	{
		if (forca >= (conquistas.back())->getResistencia()+1)
		{
			conquistas.back()->setConquistado();
			conquistas.pop_back();
			os << "------------> Perdeste o territorio: " << n << endl<<endl;
			return os.str();
		}
		return "------------> Invasao falhada\n";
	}
	else
	{
		if (forca >= (conquistas.back())->getResistencia())
		{
			if (n == "inicial")
			{
				conq_inicial = true;
				return "Perdeste o jogo!!!!!!!\n";
			}
			conquistas.back()->setConquistado();
			conquistas.pop_back();
			os << "------------> Perdeste o territorio: " << n << endl<<endl;
			return os.str();
		}
		return "------------> Invasao falhada\n";
	}
}

int Jogador::getPontFinal()
{
	if (tec_adquiridas.size() == 5)
	{
		pontuacao += 1;
	}
	pontuacao += tec_adquiridas.size();
	return pontuacao;
}

int Jogador::getSize()
{
	return conquistas.size();
}

void Jogador::setPont(int p)
{
	pontuacao = p;
}

void Jogador::copiaTec(Tecnologias* tec)
{
	tec_adquiridas.push_back(tec);
	tec->setObtida();
	if (tec->getNome() == "dronesmilitares")
	{
		max_forcaM = 5;
	}
	if (tec->getNome() == "bancocentral")
	{
		max_ouro = 5;
		max_prod = 5;
	}
}





