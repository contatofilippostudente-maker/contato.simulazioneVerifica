#include <iostream>
#include <fstream>
using namespace std;

struct Processo
{
    int pid;
    int durata;
    int priorita;
    bool completato;
    int tempo_rimanente;
};

void schedulingPriorità(Processo p[], int n)
{
    int completati = 0;
    int tempo = 0;

    while (completati < n)
    {
        int scelto = -1;

        for (int i = 0; i < n; i++)
        {
            if (p[i].tempo_rimanente > 0)
            {
                if (scelto == -1 || p[i].priorita < p[scelto].priorita)
                {
                    scelto = i;
                }
            }
        }

        if (scelto != -1)
        {
            p[scelto].tempo_rimanente--;
            tempo++;
            if(p[scelto].tempo_rimanente == 0)
            {
                cout<< p[scelto].pid;
                p[scelto].completato = true;
                completati++;
            }
        }
        else
        {
            tempo++;
        }
    }
}

int main()
{
    ifstream file("input.txt");
    int n;
    file >> n;

    Processo p[n];

    for (int i = 0; i < n; i++)
    {
        file>> p[i].pid;
        cout<<"processo "<<p[i].pid<<"durata, priorità: ";
        file>> p[i].durata;
        p[i].tempo_rimanente = p[i].durata;
        file>> p[i].priorita;
        
        p[i].completato = false;
    }

    schedulingPriorità(p, n);

    file.close();

    return 0;
}