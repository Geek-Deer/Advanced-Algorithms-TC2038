/*
    Nombre: Diego Sánchez Luna
    Matrícula: A00227831
*/

// Libs
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
 
using namespace std;

// Funciones
string lcSub(string s1, string s2) {
    // Tamaños pa la tabla
    int n = s1.length(), m = s2.length();
    
    // Creamos la tabla
    vector<vector<int>> lcst(n + 1, vector<int>(m + 1, 0));
    int maxLength = 0, byebye;

    // Llenamos la tabla y buscamos el substring más largo
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i - 1] != s2[j - 1]) lcst[i][j] = 0;
            else{
                // Si los caracteres son iguales, sumamos 1 al substring
                lcst[i][j] = lcst[i-1][j-1] + 1;  

                // Si el substring es más largo que el que ya teníamos
                if(maxLength < lcst[i][j]){

                    // Obtenemos el tamaño del substring largote
                    maxLength = lcst[i][j];
                    // Guardamos el índice del substring más largo
                    byebye = i;

                }
            }
        }
    }

    /*

    Ta muy grande el txt para imprimir la tabla, lo aprendí a la mala 😅

    
    cout<< "Tabla: \n";
    for(int i = 0; i < abs(n - m); i++) cout<<'\t';
    for(int i = 0; i < m; i++) cout<<s2[i]<<'\t';
    cout << '\n';
    for(int i = 0; i < n; i++){
        cout<<s1[i]<<'\t';
        for(int j = 0; j <= m; j++){
            cout<<lcst[i][j]<<'\t';
        }
        cout << '\n';
    }

    */

    // Regresamos el substring en base al primer string
    // byebye es el índice donde termina la subcadena, le quitamos el largo de la subcadena y tomamos caracteres iguales al largo de la misma
    return s1.substr(byebye - maxLength, maxLength);
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

int main()
{
    vector<string> sentences = {
        "El sol brilla en un cielo despejado.",
        "Estoy deseando comer una pizza esta noche.",
        "¿Has visto la pelicula que te recomendé?",
        "Tengo que hacer la compra antes de cenar.",
        "La música suave me ayuda a relajarme.",
        "El cielo está despejado y la luna es brillante.",
        "Mi perro siempre me alegra el día.",
        "Vamos a celebrar tu cumpleaños en el parque.",
        "Estoy pensando en cambiar mi celular.",
        "Necesito encontrar un buen restaurante para cenar."
        };

    string fileText = getFile("misticas.txt");
    
    for (string sentence : sentences){
        cout << "Oración: " << sentence << '\n';
        cout << "La subcadena más larga con el texto es: " << lcSub(sentence, fileText) << "\n\n";
    }
    return 0;
}
