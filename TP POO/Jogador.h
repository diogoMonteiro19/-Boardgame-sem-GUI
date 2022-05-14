#ifndef JOGADOR_H
#define JOGADOR_H
#include"Territorio.h"
#include"Tecnologias.h"
#include<vector>

using namespace std;

class Jogador
{
	int pontuacao, ouro, prod, forca_militar, sorte;
	int max_ouro, max_prod, max_forcaM;
	bool conq_inicial;
	vector<Territorio *> conquistas;
	vector<Tecnologias*> tec_adquiridas;
public:
	Jogador();
	int getPont() const;
	int getOuro() const;
	int getProd() const;
	int getForcaM() const;
	int getSorte() const;
	int getMaxOuro() const;
	int getMaxProd() const;
	int getMaxForcaM() const;
	int getGanhoOuro() const;
	int getGanhoProd() const;
	bool getConq();
	void aumentaPont(int aumento);
	void setOuro(int o);
	void setProd(int p);
	void contaPont();
	string compraOuro();
	string compraProd();
	string compraMilitar();
	void setForcaM(int fm);
	int calculaForcaDado();
	void addTerritorio(Territorio *t);
	void recolheRecursos();
	string adquireTec(Tecnologias* tec);
	bool verificaTec(string nome)const;
	string trataInvasao(int forca);
	int getPontFinal();
	int getSize();
	void setPont(int p);
	void copiaTec(Tecnologias* tec);
};
#endif