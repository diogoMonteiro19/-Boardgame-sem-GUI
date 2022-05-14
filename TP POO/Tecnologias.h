#ifndef TECNOLOGIAS_H
#define TECNOLOGIAS_H
#include<iostream>
class Tecnologias
{
public:
	Tecnologias(std::string nome,int custo);
	std::string getNome();
	int getCusto();
	bool getObtida();
	void setObtida();
	std::string getAsString();
private:
	int custo;
	std::string nome;
	bool obtida;
};
#endif
