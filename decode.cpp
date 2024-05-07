/*
    Nombre: Diego Sánchez Luna
    Matrícula: A00227831
*/

// Libs
#include <iostream>
#include <string>
using namespace std;

// Funciones

// Variables
int main()
{
    string patata = "LQIRUPDWLRQ VHFXULWB";
    string tomato = "WAIT IT WAS SUN";
    char x = 'm';

    if(x=='c'){
        for (int i = 0; i < patata.length(); i++)
        {
            if (patata[i] != ' ')
            {
                patata[i] = (patata[i] - 3 - 'A' + 26) % 26 + 'A';
            }
        }
        cout<<patata;
    }
    else if(x=='m'){
        // Solve monoalphabetic cipher
        for (int i = 0; i < tomato.length(); i++)
        {
            if (tomato[i] != ' ')
            {
                tomato[i] = (tomato[i] - 3 - 'A' + 26) % 26 + 'A';
            }
        }
    }
    
    return 0;
}