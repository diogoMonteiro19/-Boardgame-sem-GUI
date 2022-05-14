#ifndef MUNDO_H
#define MUNDO_H

#include <iostream>
#include <vector>
#include "Territorio.h"
#include"Jogador.h"
using namespace std;

class Mundo
{
public:
	Mundo();
	Mundo(Mundo& novo);
	string leComando(string c);
	string listaInformacao() const;
	string listaTerritorio(string nome) const;
	string listaTerritorios() const;
	string carrega(string nome);
	void aumentaTurno();
	void acrescentaTerritorio(Territorio *t);
	string conquistaTerritorio(string nome);
	int getTurno() const;
	int getAno() const;
	int getFase();
	void setFase(int f);
	string avancaFase();
	string compraTec(string nome);
	string ocorreEvento();
	string invasao();
	void ativaSkills();
	void contaPont();
	int getPont();
	int pontFinal();
	void operator=(Mundo& copia);
	~Mundo();
private:
	int ano, turno,fase;
	bool entrou_fase, comprouM, comprouTec, comprouOP;
	Jogador jogador;
	string comando;
	vector<Territorio*> territorios;
	vector<Tecnologias> tecnologias;
	const string nomes[8] = { "planicie","mina","castelo","fortaleza","duna","montanha","refugiodospiratas","pescaria" };
};
#endif