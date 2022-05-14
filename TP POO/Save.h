#ifndef SAVE_H
#define SAVE_H
#include"Mundo.h"

class Save
{
public:
	Save();
	Save(Mundo* novo,string nome);
	Mundo* getMundo();
	string getNome();
	void setMundo(Mundo* novo);
	void setNome(string nome);
private:
	Mundo* mundo;
	string nome;
};
#endif
