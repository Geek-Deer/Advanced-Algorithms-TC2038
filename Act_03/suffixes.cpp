/*
    Nombre: Diego Sánchez Luna
    Matrícula: A00227831
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <array>
using namespace std;

// Funciones
struct Suffix {
    int index;
    const char* suffix;
};

vector<int> construirArreglo(string& str, int n) {
    vector<int> suffixes(n);

    // Llena el vector de sufijos con los índices
    for (int i = 0; i < n; i++) {
        suffixes[i] = i;
    }

    // Ordena los sufijos lexicográficamente utilizando sort()
    sort(suffixes.begin(), suffixes.end(), [&str](int a, int b) {
        return strcmp(&str[a], &str[b]) < 0;
    });

    return suffixes;
}

int main() {
    vector<string> str = {  "DEJAD que recorra los mundos ¡Abrid a mi paso horizonte!¡Dejad mi bajel que navegue Sin popa ni proa mezquinas.",
                            "Las manos de granito y el corazón de fuego Que amasen, consoliden, supremos monumentos! Blindad así la vida y de un constante riego Fecundad sus entrañas, huérfana de sustentos.",
                            "¡Abrid a mi paso horizonte!¡Dejad mi bajel que navegue Sin popa ni proa mezquinas.",
                            "Pisemos en la zarza aún dejando en ella Girones de la carne al triscar en la espina ... Cada gota de sangre lucirá como estrella Y arderá en los zarzales el fuego que ilumina.",
                            "Porque el Señor dispuso que en la vida el humano Conciliar pueda un día con toda majestad El ideal supremo. Más, si esto fuera en vano, Sepultaría el mundo en honda eternidad."};
    // Construye el arreglo de sufijos    
    for(int i = 0; i < 5; i++){
        cout<< "Cadena: " << str[i] << "\n";
        int n = str[i].length();
        vector<int> suffixArray = construirArreglo(str[i], n);
        cout << "Arreglo de sufijos: \n" ;
        for(int j = 0; j < n; j++){
            cout << "Indice: " << suffixArray[j] << "| Sufijo: " << str[i].substr(suffixArray[j]) << "$" << '\n';
        }
        cout << "[ ";
        for (int j = 0; j < n; j++) {
            cout <<suffixArray[j] << ", ";
        }
        cout<< "]\n\n";
    }
    return 0;
}
