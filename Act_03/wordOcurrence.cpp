/*
    Nombre: Diego Sánchez Luna
    Matrícula: A00227831
*/

// Libs
#include <iostream>
#include <vector>
#include <fstream>
#include <array>
#include <chrono>
#include <string>

using namespace std;

// Funciones
string getData(string file){
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

// ==============================================================================================================
// Z function

vector<long long int> zFunction(string s){
    int n = s.size();
    vector<long long int> z(n);
    long long int l = 0, r = 0;

    // Recorrer el string desde el segundo caracter para que no reviente el programa
    for(int i = 1; i < n; i++){
        // Si i no está en el intervalo [l, r] se calcula z[i] de forma normal
        if(i <= r) z[i] = min(r - i + 1, z[i - l]);

        // Actualizar z[i] comparando el string desde s[z[i]] con s[i]
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;

        // Actualizar el intervalo [l, r] si se encuentra un z[i] mayor
        if(i + z[i] - 1 > r){
            l = i;
            r = i + z[i] - 1;
        }
    }
    for(int i = 0; i < z.size(); i++){
        cout<<z[i]<<" ";
    }
    cout<<'\n';
    // Regresar el vector con los valores de z
    return z;
}

void searchZ(string texto, string palabra) {
    string patron = palabra + "$" + texto;
    vector<long long int> z = zFunction(patron);

    int counter = 0;

    int n = z.size();
    for (int i = 0; i <= n; i++) {
        if (z[i] == palabra.size()) {
            cout << "Palabra encontrada en posición " << i - palabra.size() - 1 << ": ";
            cout << texto.substr(i - palabra.size() - 1, 50) << '\n';
            counter++;
        }
    }
    cout<<"La palabra "<<palabra<<" se encontró "<<counter<<" veces"<<'\n';

}
// ==============================================================================================================
// LPS 
vector<int> computeLPS(string pattern) {
    int n = pattern.length();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// KMP

void searchKMP(string text, string pattern) {
    vector<int> lps = computeLPS(pattern);
    int n = text.length();
    int m = pattern.length();
    long long int i = 0;  // index for text
    int j = 0;  // index for pattern
    int counter = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            // Pattern found
            cout << "Palabra encontrada en posición " << i - j << ": " << text.substr(i - j, 50) << '\n'    ;
            j = lps[j - 1];
            counter++;
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    cout << "La palabra " << pattern << " se encontró " << counter << " veces" << '\n';
    
}




// Variables
int main()
{
    string plainText = getData("misticas.txt");
    array <string, 5> patterns = {"Dios", "amor", "alma", "vida", "muerte"};

    string s1 = "maabcxbabca", s2 = "abc";
    cout << "Z function: \n";
    for(int i = 0; i < patterns.size(); i++){
        auto start = std::chrono::high_resolution_clock::now();
        searchZ(plainText, patterns[i]);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << "Tiempo de ejecución para " << patterns[i] << ": " << duration.count() << " microsegundos" << endl;
        cout << '\n';
        cout<<'\n';
    }

    cout << "KMP function: \n";
    for(int i = 0; i < patterns.size(); i++){
        auto start = std::chrono::high_resolution_clock::now();
        searchKMP(plainText, patterns[i]);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << "Tiempo de ejecución para " << patterns[i] << ": " << duration.count() << " microsegundos" << endl;
        cout << '\n';
    }
    
    searchZ(s1, s2);
    return 0;
}