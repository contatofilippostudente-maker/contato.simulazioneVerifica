#include <iostream>

using namespace std;

struct Processo
{
    int pid;
    int durata;
    int priorita;
    int arrivo;
    bool completato;
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
            if (p[i].arrivo <= tempo && !p[i].completato)
            {
                if (scelto == -1 || p[i].priorita < p[scelto].priorita)
                {
                    scelto = i;
                }
            }
        }

        if (scelto != -1)
        {
            tempo += p[scelto].durata;
            cout<< p[i].pid;
            p[scelto].completato = true;
            completati++;
        }
        else
        {
            tempo++;
        }
    }
}

int main()
{
    int n;
    cout << "Quanti processi? ";
    cin >> n;

    Processo p[n];

    for (int i = 0; i < n; i++)
        {
        p[i].id = i + 1;
        cout<<"processo "<<p[i].id<<"arrivo, durata, priorità: ";
        cin>> p[i].pid;
        cin>> p[i].durata;
        cin>> p[i].priorita;
        
        p[i].completato = false;
    }

    schedulingPriorità(p, n);

    return 0;
}