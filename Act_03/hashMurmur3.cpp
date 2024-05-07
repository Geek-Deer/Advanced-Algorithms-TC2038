/*
    Nombre: Diego Sánchez Luna
    Matrícula: A00227831
*/

// Libs
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include "MurmurHash3.cpp" // Asegúrate de incluir la implementación de MurMurHash3 en tu proyecto
#include <algorithm>
#include <fstream>

using namespace std;

// Funciones
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

void calcularHashes(string texto, map<uint32_t, pair<string, int>>& hashPalabras) {
    stringstream ss(texto);
    string palabra;

    while (ss >> palabra) {
        uint32_t hashValue;
        MurmurHash3_x86_32(palabra.c_str(), palabra.length(), 0, &hashValue);

        if (hashPalabras.find(hashValue) == hashPalabras.end()) {
            hashPalabras[hashValue] = make_pair(palabra, 1);
        } else {
            hashPalabras[hashValue].second++;
        }
    }
}

int main() {
    cout << "Top 20 palabras más frecuentes en el archivo 'misticas.txt' [Murmur3]" << "\n\n";

    // Obtener el texto del archivo
    string texto = getFile("misticas.txt");

    // Crear un mapa para almacenar los hashes de las palabras + el número de veces que aparece
    map<uint32_t, pair<string, int>> hashPalabras;

    // Calcular los hashes de las palabras y almacenarlos en el mapa
    calcularHashes(texto, hashPalabras);

    // Crear un vector para almacenar las palabras y sus frecuencias
    vector<pair<string, int>> frecuencias;

    // Almacenar las palabras y sus frecuencias en el vector
    for (const auto& pair : hashPalabras) {
        frecuencias.push_back(pair.second);
    }

    // Ordenar las palabras por frecuencia de aparición de mayor a menor
    sort(frecuencias.begin(), frecuencias.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });

    // Imprimir las 20 palabras más frecuentes
    for (int i = 0; i < 20 && i < frecuencias.size(); i++) {
        cout << frecuencias[i].first << " " << frecuencias[i].second << endl;
    }

    return 0;
}
