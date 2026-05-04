#include <iostream>
#include <fstream>
using namespace std;

struct Processo
{
    int pid;
    int durata;
    int priorita;
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
            if (!p[i].completato)
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
            cout<< p[scelto].pid;
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
    ifstream file("input.txt");
    int n;
    file >> n;

    Processo p[n];

    for (int i = 0; i < n; i++)
    {
        getline(file, p[i].pid, " ");
        cout<<"processo "<<p[i].pid<<"durata, priorità: ";
        getline(file, p[i].durata, " ");
        getline(file, p[i].priorità, " ");
        
        p[i].completato = false;
    }

    schedulingPriorità(p, n);

    file.close();

    return 0;
}