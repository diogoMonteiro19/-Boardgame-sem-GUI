#ifndef TERRITORIO_H
#define TERRITORIO_H

#include <iostream>

using namespace std;

class Territorio
{
public:
	Territorio(string nome);
	Territorio(string nome, int ouro, int prod, int pontos, int res);
	Territorio(string nome, int ouro, int prod, int pontos, int res,bool conq);
	string getNome() const;
	int getResistencia() const;
	int getOuro() const;
	int getProd() const;
	bool getConquistado() const;
	void setConquistado();
	string toString() const;
	virtual void skill(int ano, int turno);
	int getPont()const;
protected:
	string nome;
	int ouro, prod, pontos, resistencia;
	bool conquistado;
	static int minas;
	static int planicies;
	static int fortalezas;
	static int montanhas;
	static int dunas;
	static int castelos;
	static int refugio;
	static int pescaria;
};
#endif