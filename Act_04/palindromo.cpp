/*
    Nombre: Diego Sánchez Luna
    Matrícula: A00227831
*/

// Libs
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Funciones
string busquedaDePalindromo(string& s) {
    // Agregar separadores
    string modifiedString = "|";
    for (char c : s) {
        modifiedString += c;
        modifiedString += "|";
    }

    int n = modifiedString.length();
    // lengthyPal[i] = longitud del palindromo mas largo con centro en i
    vector<int> lengthyPal(n, 0);
    // center = centro del palindromo mas largo hasta el momento
    int center = 0, right = 0;

    // Manacher
    for (int i = 1; i < n - 1; i++) {
        int vuelta = 2 * center - i;

        if (i < right) lengthyPal[i] = min(right - i, lengthyPal[vuelta]);

        // Expandir palindromo
        while (modifiedString[i + 1 + lengthyPal[i]] == modifiedString[i - 1 - lengthyPal[i]]) lengthyPal[i]++;


        // Actualizar centro y right
        if (i + lengthyPal[i] > right) {
            center = i;
            right = i + lengthyPal[i];
        }
    }

    // En esta parte buscamos el palíndromo más largo
    int maxLength = 0, maxCenter = 0;
    for (int i = 1; i < n - 1; i++) {
        if (lengthyPal[i] > maxLength) {
            maxLength = lengthyPal[i];
            maxCenter = i;
        }
    }

    int startIndex = (maxCenter - maxLength) / 2;
    return s.substr(startIndex, maxLength);
}


string getFile(string file){
    string text, line;
    ifstream myfile (file);
    if (myfile.is_open())
    {
        while ( getline (myfile, line) )
        {
            text += line;
        }
        myfile.close();
        return text;
    }
    else cout << "Unable to open file";
    return "";
}

int main() {
    string text = getFile("misticas.txt");
    string palpal = busquedaDePalindromo(text);
    cout << "Palindromo más largo: " << palpal << endl;
    return 0;
}
