/*
    Nombre: Diego Sánchez Luna
    Matrícula: A00227831
*/

// Libs
#include <iostream>
#include <vector>
using namespace std;

// Funciones

void checkSequence(vector<int> data){
    int maxLength = 0, currentLength = 1;

    for(int i = 1; i < data.size(); i++){
        if(data[i] > data[i-1]){
            currentLength++;
            maxLength = max(maxLength, currentLength);
        }
            
        else currentLength = 1;

    }

    cout << "Tamaño de secuencia máxima: " << maxLength;
}

// Variables
int main()
{
    
    vector <int> numeritos = {1, 7, 2 ,11, 15};

    checkSequence(numeritos);

    return 0;
}