/*
    Nombre: Diego Sánchez Luna
    Matrícula: A00227831
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

// Funciones
long long polynomialRollingHash(const string& word) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hashValue = 0;
    long long p_pow = 1;
    for (char c : word) {
        hashValue = (hashValue + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hashValue;
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

void calcularHashes(string texto, map<long long, pair<string, int>> &hashPalabras) {
    vector<string> palabras;
    string palabra;
    stringstream ss(texto);

    while (ss >> palabra) {
        palabras.push_back(palabra);
    }

    // Hacemos la parte del hash
    for (int i = 0; i < palabras.size(); i++) {
        long long hash = polynomialRollingHash(palabras[i]); // fix typo: use palabras[i] instead of palabra
        if (hashPalabras.find(hash) == hashPalabras.end()) {
            hashPalabras[hash] = make_pair(palabras[i], 1);
        } else {
            hashPalabras[hash].second++;
        }   
    }

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
    for (int i = 0; i < 20; i++) {
        cout << frecuencias[i].first << " " << frecuencias[i].second << endl;
    }
}

int main() {
    cout<<"Top 20 palabras más frecuentes en el archivo "<< "misticas.txt [PRH]\n\n";

    // Obtener el texto del archivo
    string texto = getFile("misticas.txt");
    // Crear un mapa para almacenar los hashes de las palabras + el número de veces que aparece
    map<long long, pair<string, int>> hashPalabras;
    // Calcular los hashes de las palabras y almacenarlos en el mapa
    calcularHashes(texto, hashPalabras);

    return 0;
}

