#include <iostream>
#include "Mundo.h"
#include"Save.h"
#include <string>

using namespace std;

int main()
{
    Mundo mundo;
    string comando;
    Save save1(&mundo, "inicial");
    vector <Save> saves;
    saves.push_back(save1);
    int i = 0;
    while (saves[i].getMundo()->getAno() < 3)
    {
        saves[i].getMundo()->ativaSkills();
        cout << saves[i].getMundo()->listaInformacao();
        while (saves[i].getMundo()->getFase() < 4)
        {
            cout << "> ";
            getline(cin,comando);
            string c=saves[i].getMundo()->leComando(comando);
            if ((c.find("grava") == 0))
            {
                string n = c.substr(6, string::npos);
                Mundo* novo=new Mundo(*saves[i].getMundo());
                Save* novoSave = new Save(novo,n);
                saves.push_back(*novoSave);
                c = "Gravado com sucesso\n";
            }
            if ((c.find("ativa") == 0))
            {
                string n = c.substr(6, string::npos);
                c = "Nao existe save com esse nome\n";
                for (unsigned int it = 0; it < saves.size(); it++)
                {
                    if (saves[it].getNome() == n)
                    {
                        i = it;
                        c = "Ativado com sucesso\n";
                        break;
                    }
                }
            }
            if ((c.find("apaga") == 0))
            {
                string n = c.substr(6, string::npos);
                if (saves[i].getNome() == n) 
                {
                    c = "Nao pode apagar o save que esta a ser usado\n";
                }
                else
                {
                    c = "Nao existe save com esse nome\n";
                    auto it = saves.begin();
                    int cont = 0;
                    while (it != saves.end())
                    {
                        if ((*it).getNome() == n)
                        {
                            it = saves.erase(it);
                            c = "Destruido com sucesso\n";
                            if (cont < i)
                                i--;
                            break;
                        }
                        cont++;
                        it++;
                    }
                }
            }
            cout << c;
            if (c == "Perdeste o jogo!!!!!!!\n") {
                exit(3);
            }
            
            
        }
        cout<<saves[i].getMundo()->ocorreEvento();
        saves[i].getMundo()->setFase(1);
        comando.clear();
        saves[i].getMundo()->contaPont();
        saves[i].getMundo()->aumentaTurno();
    }
    cout << "Pontuacao Final: "<< saves[i].getMundo()->pontFinal()<<endl;
}