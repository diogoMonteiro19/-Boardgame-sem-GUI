#include "Mundo.h"
#include"Montanha.h"
#include"Castelo.h"
#include"Duna.h"
#include"Fortaleza.h"
#include"Planicie.h"
#include"Mina.h"
#include"Pescaria.h"
#include"RefugioDosPiratas.h"
#include"Tecnologias.h"
#include <sstream>
#include <string>
#include <fstream>

Mundo::Mundo() : ano(1), turno(1), jogador(),fase(0),entrou_fase(false), comprouM(false), comprouTec(false), comprouOP(false)
{
	Territorio* inicial = new Territorio("inicial");
	acrescentaTerritorio(inicial);
	Tecnologias DroneM("dronesmilitares", 3);
	tecnologias.push_back(DroneM);
	Tecnologias Misseis("misseisteleguiados",4);
	tecnologias.push_back(Misseis);
	Tecnologias Defesas("defesasterritoriais",4);
	tecnologias.push_back(Defesas);
	Tecnologias Bolsa("bolsadevalores",2);
	tecnologias.push_back(Bolsa);
	Tecnologias Banco("bancocentral",3);
	tecnologias.push_back(Banco);
}

Mundo::Mundo(Mundo& novo)
{
	Territorio* inicial = new Territorio("inicial");
	acrescentaTerritorio(inicial);
	Tecnologias DroneM("dronesmilitares", 3);
	tecnologias.push_back(DroneM);
	Tecnologias Misseis("misseisteleguiados", 4);
	tecnologias.push_back(Misseis);
	Tecnologias Defesas("defesasterritoriais", 4);
	tecnologias.push_back(Defesas);
	Tecnologias Bolsa("bolsadevalores", 2);
	tecnologias.push_back(Bolsa);
	Tecnologias Banco("bancocentral", 3);
	tecnologias.push_back(Banco);
	*this = novo;
}

string Mundo::leComando(string c)
{
	istringstream iss(c);
	string com;
	string nome;
	int n, flag=0;
	if (jogador.getConq())
	{
		return "Perdeste o jogo!!!!!!!\n";
	}
	if (fase == 2 && !entrou_fase) {
		entrou_fase = true;
		jogador.recolheRecursos();
	}
	iss >> com;
	if (com == "cria" && fase == 0)
	{
		iss >> nome;
		if (!iss.fail())
		{
			for (int i = 0; i < 8; i++)
			{
				if (nome == nomes[i])
					flag = 1;
			}
			if (flag == 0)
			{
				return "Nao pode criar esse tipo de territorios\n";
			}
			iss >> n;
			if (!iss.fail() && n > 0)
			{
				for (int i = 0; i < n; i++)
				{
					Territorio* p;
					if (nome == "planicie") 
					{
						 p = new Planicie();
					}
					else if (nome == "montanha") {
						p = new Montanha();
					}
					else if (nome == "fortaleza") {
						p = new Fortaleza();
					}
					else if (nome == "mina") {
						p = new Mina();
					}
					else if (nome == "duna") {
						p = new Duna();
					}
					else if (nome == "castelo") {
						p = new Castelo();
					}
					else if (nome == "refugiodospiratas" ) {
						p = new RefugioDosPiratas();
					}
					else {
						p = new Pescaria();
					}
						acrescentaTerritorio(p);
				}
				return listaTerritorios();
			}
			else
			{
				Territorio* p;
				if (nome == "planicie")
				{
					p = new Planicie();
				}
				else if (nome == "montanha") {
					p = new Montanha();
				}
				else if (nome == "fortaleza") {
					p = new Fortaleza();
				}
				else if (nome == "mina") {
					p = new Mina();
				}
				else if (nome == "duna") {
					p = new Duna();
				}
				else if (nome == "castelo") {
					p = new Castelo();
				}
				else if (nome == "refugiodospiratas") {
					
					p = new RefugioDosPiratas();
				}
				else {
					p = new Pescaria();
				}
				acrescentaTerritorio(p);
				return listaTerritorios();
			}
		}
	}
	if (com == "carrega" && fase == 0)
	{
		iss >> nome;
		if (!iss.fail())
		{
			return carrega(nome);
		}
		else
			return "Erro no comando\n";
	}
	if (com == "lista")
	{
		iss >> nome;
		if (!iss.fail())
			return listaTerritorio(nome);
		else
			return listaInformacao();
	}
	if (com == "conquista" && fase==1)
	{
		iss >> nome;
		string res = conquistaTerritorio(nome);
		if (res != "Territorio nao existe!\n" && res !="Territorio ja conquistado!\n" && res != "Nao possui misseis teleguiados para conquistar ilhas\n")
		{
			string res=avancaFase();
		}
		return res;
	}
	if (com == "passa" && fase==1)
	{
		string res=avancaFase();
		return "Passou a conquista\n";
	}
	if (com == "avanca")
	{
		return avancaFase();
	}
		
	if (com == "maisouro" && fase == 2)
	{
		if (!jogador.verificaTec("bolsadevalores"))
		{
			return "Nao possui Bolsa de Valores\n";
		}
		if (!comprouOP)
		{
			comprouOP = true;
			return jogador.compraOuro();
		}
		return "Ja trocou ouro ou produtos este turno!\n";
	}
	if (com == "maisprod" && fase == 2)
	{
		if (!jogador.verificaTec("bolsadevalores"))
		{
			return "Nao possui Bolsa de Valores\n";
		}
		if (!comprouOP)
		{
			comprouOP = true;
			return jogador.compraProd();
		}
		return "Ja trocou ouro ou produtos este turno!\n";
	}
	if (com == "maismilitar" && fase == 3)
	{
		if (!comprouM)
		{
			comprouM = true;
			return jogador.compraMilitar();
		}
		return "Ja comprou forca militar este turno!\n";
	}
	if (com == "adquire" && fase == 3)
	{
		if (!comprouTec)
		{
			iss >> nome;
			return compraTec(nome);
		}
		return "Ja adquiriu uma tecnologia este turno!\n";
	}
	if (com == "fevento")
	{
		iss >> nome;
		if (nome == "invasao")
		{
			return invasao();
		}
		if (nome == "aliancadiplomatica")
		{
			jogador.setForcaM(jogador.getForcaM() + 1);
			return "-------> Assinaste uma alianca diplomatica\n\n";
		}
		if (nome == "recursoabandonado")
		{
			if (ano == 1) {
				jogador.setProd(jogador.getProd() + 1);
				return "-------> Encontraste um recurso abandonado\n\n";
			}
			else
			{
				jogador.setOuro(jogador.getOuro() + 1);
				return "-------> Encontraste um recurso abandonado\n\n";
			}
		}
		if (nome == "semevento")
		{
			return "-------> Nada ocorre e todos podem dormir descansados\n\n";
		}
	}
	if (com == "grava")
	{
		iss >> nome;
		return "grava "+nome;
	}
	if (com == "ativa")
	{
		iss >> nome;
		return "ativa " + nome;
	}
	if (com == "apaga")
	{
		iss >> nome;
		return "apaga " + nome;
	}
	if (com == "toma")
	{
		string tipo;
		iss >> tipo;
		if (tipo == "terr")
		{
			iss >> nome;
			auto it = territorios.begin();
			while (it != territorios.end())
			{
				if ((*it)->getNome() == nome)
				{
					if ((*it)->getConquistado())
					{
						return "Nao pode tomar um territorio ja conquistado!\n";
					}
					else
					{
						(*it)->setConquistado();
						jogador.addTerritorio((*it));
						return "Tomou o territorio com sucesso!\n";
					}
				}
				it++;
			}

			return "Territorio nao existe!\n";
		}
		if (tipo == "tec")
		{
			iss >> nome;
			for(unsigned int i=0;i<tecnologias.size();i++)
			{
				if (tecnologias[i].getNome() == nome)
				{
					if (tecnologias[i].getObtida())
					{
						return "Nao pode tomar uma tecnologia ja obtida!\n";
					}
					else
					{
						tecnologias[i].setObtida();
						jogador.copiaTec(&tecnologias[i]);
						return "Tecnologia tomada com sucesso!\n";
					}
				}
			}
			return "Tecnologia nao existe!\n";
		}

		return "Uso do comando toma errado (toma <qual> <nome>)\n";
	}
	if (com == "modifica")
	{
		iss >> nome;
		if (nome == "ouro")
		{
			iss >> n;
			if (!iss.fail())
			{
				jogador.setOuro(n);
				return "Ouro alterado com sucesso!\n";
			}
			return "Uso do comando modifica errado (modifica <ouro/prod> N)\n";
		}
		if(nome=="prod")
		{
			iss >> n;
			if (!iss.fail())
			{
				jogador.setProd(n);
				return "Produtos alterados com sucesso!\n";
			}
			return "Uso do comando modifica errado (modifica <ouro/prod> N)\n";
		}
		return "Uso do comando modifica errado (modifica <ouro/prod> N)\n";
	}
	else
		return "Nao e um comando valido!\n";
}

string Mundo::listaInformacao() const
{
	ostringstream oss;
	oss << "Fase: " << fase << ", Turno: " << turno << ", Ano: " << ano << " || Pontuacao: " << jogador.getPont() << "\n";
	if (jogador.getSorte() != 0)
		oss << "Ultimo fator sorte: " << jogador.getSorte() << "\n";
	oss << "Comandos disponiveis: lista <nome> || avanca || grava <nome_save> || ativa <nome_save> || apaga <nome_save>\n\n";
	if (fase == 1 || fase == 0)
	{
		oss << listaTerritorios();
		if(fase==1)
			oss << "\nComandos disponiveis nesta fase: conquista <nome> || passa\n";
		if (fase == 0)
			oss << "\nComandos disponiveis nesta fase: cria <nome> N || carrega <nome_fich>\n";
	}
	if (fase == 2)
	{
		if (jogador.verificaTec("bolsadevalores")) 
		{
			oss << "Comandos disponiveis nesta fase: maisouro||maisprod\n";
		}
		else
		{
			oss << "Nao possui bolsa de valores, compre para poder trocar ouro ou produtos\n";
		}
		
	}
	if (fase == 3)
	{
		for (auto t : tecnologias)
		{
			oss << t.getAsString();
		}
		oss << "\nComandos disponiveis nesta fase: adquire <tec> || maismilitar\n";
	}
	oss << "Ouro: " << jogador.getOuro() << "/" << jogador.getMaxOuro() << " + " << jogador.getGanhoOuro() << ", Prod: " << jogador.getProd() << "/" << jogador.getMaxProd() << " + " << jogador.getGanhoProd() << ", Forca militar: " << jogador.getForcaM() << "/" << jogador.getMaxForcaM() << "\n";

	return oss.str();
}

string Mundo::listaTerritorio(string nome) const
{
	auto it = territorios.begin();
	while (it != territorios.end()) {
		if ((*it)->getNome() == nome) {
			return (*it)->toString() + "\n";
		}
		else
			it++;
	}
	return "Territorio nao existe!\n";
}

string Mundo::listaTerritorios() const
{
	ostringstream oss;

	if (!territorios.empty())
	{
		auto it = territorios.begin();
		while(it != territorios.end())
		{
			oss << (*it)->toString() << "\n";
			it++;
		}
		return oss.str();
	}
	else
		return "Sem territorios!\n";
}

string Mundo::carrega(string nome)
{
	ifstream f;
	ostringstream oss;
	f.open(nome);
	if (!f)
	{
		return "Erro a abrir o ficheiro.\n";
	}
	if (f.is_open())
	{
		string com;
		while (getline(f, com))
		{
			oss << "> " << com << "\n";
			oss << leComando(com);
		}
	}
	f.close();

	return oss.str();
}

void Mundo::aumentaTurno()
{
	if (turno == 6)
	{
		ano++;
		turno = 1;
		entrou_fase = false;
		comprouM = false;
		comprouTec = false;
		comprouOP = false;
	}
	else
	{
		turno++;
		entrou_fase = false;
		comprouM = false;
		comprouTec = false;
		comprouOP = false;
	}
}

void Mundo::acrescentaTerritorio(Territorio *t)
{
	territorios.push_back(t);
	if (t->getNome() == "inicial")
		jogador.addTerritorio(t);
}

string Mundo::conquistaTerritorio(string nome)
{
	auto it = territorios.begin();

	while (it != territorios.end())
	{
		if ((*it)->getNome() == nome)
		{
			if ((nome.find("refugiodospiratas") != string::npos)|| (nome.find("pescaria") != string::npos))
			{
				if (!jogador.verificaTec("misseisteleguiados"))
				{
					return "Nao possui misseis teleguiados para conquistar ilhas\n";
				}
			}
			if ((*it)->getConquistado())
				return "Territorio ja conquistado!\n";
			if ((*it)->getResistencia() < jogador.calculaForcaDado())
			{
				(*it)->setConquistado();
				jogador.addTerritorio(*it);
				return "Territorio conquistado!!!\n";
			}
			else
			{
				jogador.setForcaM(jogador.getForcaM() - 1);
				return "Conquista falhada!\n";
			}
		}
		else
		{
			it++;
		}
	}

	return "Territorio nao existe!\n";
}

int Mundo::getAno() const
{
	return ano;
}

int Mundo::getFase()
{
	return fase;
}

void Mundo::setFase(int f)
{
	fase = f;
}

string Mundo::avancaFase()
{
	if (fase == 4) {
		string res=ocorreEvento();
		fase = 1;
	}
	else{
		fase++;
	}
	return listaInformacao();
}

string Mundo::compraTec(string nome)
{
	
	for (unsigned int i = 0; i < tecnologias.size(); i++) {
		if (nome == tecnologias[i].getNome())
		{
			if (jogador.getOuro() >= tecnologias[i].getCusto())
			{
				comprouTec = true;
				return jogador.adquireTec(&tecnologias[i]);
			}
		}
	}
	return "Nao conseguiu adquirir tecnologia\n";
}

string Mundo::ocorreEvento()
{
	int randn=(rand() % 4 + 1);
	switch (randn) {
	case 1:
		if (ano == 1) {
			jogador.setProd(jogador.getProd() + 1);
			return "-------> Encontraste um recurso abandonado\n\n";
		}
		else
		{
			jogador.setOuro(jogador.getOuro() + 1);
			return "-------> Encontraste um recurso abandonado\n\n";
		}
		break;
	case 2:
		return invasao();
		break;
	case 3:
		jogador.setForcaM(jogador.getForcaM() + 1);
		return "-------> Assinaste uma alianca diplomatica\n\n";
	case 4:
		return "-------> Nada ocorre e todos podem dormir descansados\n\n";
	}
	

	return "";
}

string Mundo::invasao()
{
	int sorte= (rand() % 6 + 1);
	string s = jogador.trataInvasao(sorte + (ano + 1));
	if (s == "Perdeste o jogo!!!!!!!\n")
	{
		return s;
	}
	return s;
}

void Mundo::ativaSkills()
{
	auto it = territorios.begin();
	while (it != territorios.end())
	{
		(*it)->skill(ano, turno);
		it++;
	}
}

void Mundo::contaPont()
{
	jogador.contaPont();
}

int Mundo::getPont()
{
	return jogador.getPont();
}

int Mundo::pontFinal()
{
	if (jogador.getSize() == territorios.size())
	{
		return jogador.getPontFinal() + 3;
	}
	return jogador.getPontFinal();
}

void Mundo::operator=(Mundo& copia)
{
	auto it = copia.territorios.begin();
	it++;
	while (it != copia.territorios.end())
	{
		Territorio* p;
		if ((*it)->getNome().find("planicie") != string::npos)
		{
			p = new Planicie((*it)->getNome(),(*it)->getConquistado());
		}
		else if ((*it)->getNome().find("montanha") != string::npos) {
			p = new Montanha((*it)->getNome(), (*it)->getConquistado());
		}
		else if ((*it)->getNome().find("fortaleza") != string::npos) {
			p = new Fortaleza((*it)->getNome(), (*it)->getConquistado());
		}
		else if ((*it)->getNome().find("mina") != string::npos) {
			p = new Mina((*it)->getNome(), (*it)->getConquistado());
		}
		else if ((*it)->getNome().find("duna") != string::npos) {
			p = new Duna((*it)->getNome(), (*it)->getConquistado());
		}
		else if ((*it)->getNome().find("castelo") != string::npos) {
			p = new Castelo((*it)->getNome(), (*it)->getConquistado());
		}
		else if ((*it)->getNome().find("refugiodospiratas") != string::npos) {
			p = new RefugioDosPiratas((*it)->getNome(), (*it)->getConquistado());
		}
		else {
			p = new Pescaria((*it)->getNome(), (*it)->getConquistado());
		}
		territorios.push_back(p);
		it++;
	}
	ano= copia.ano;
	turno=copia.turno;
	entrou_fase=copia.entrou_fase;
	comprouM = copia.comprouM;
	comprouTec = copia.comprouTec;
	comprouOP = copia.comprouOP;
	fase= copia.fase;
	tecnologias = copia.tecnologias;
	auto it2 = copia.territorios.begin();
	it2++;
	while (it2 != copia.territorios.end())
	{
		if ((*it2)->getConquistado())
		{
			auto it3 = territorios.begin();
			it3++;
			while (it3 != territorios.end())
			{
				if ((*it3)->getNome() == (*it2)->getNome())
				{
					jogador.addTerritorio(*it3);
					break;
				}
				it3++;
			}
		}
		it2++;
	}
	for (unsigned int i = 0;i < tecnologias.size();i++)
	{
		if (tecnologias[i].getObtida())
		{
			jogador.copiaTec(&tecnologias[i]);
		}
	}
	jogador.setForcaM(copia.jogador.getForcaM());
	jogador.setOuro(copia.jogador.getOuro());
	jogador.setProd(copia.jogador.getProd());
	jogador.setPont(copia.jogador.getPont());
}



int Mundo::getTurno() const
{
	return turno;
}

Mundo::~Mundo()
{

}