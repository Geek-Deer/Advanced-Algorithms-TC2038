/*
    Nombre: Diego Sánchez Luna
    Matrícula: A00227831
*/

// Libs
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// Funciones

// String polynomial
long long prhf (const string& s){    
    int p = 53;
    int m = 1000;
    int hnj = 0;
    
    for(int i = 0; i < s.length(); i++){
        hnj = (hnj * p + s[i]) % m;
    }
    return hnj;

}





// Create n random strings of length m
vector<string> createRandomStrings(int n, int m){
    vector<string> randomStrings(n);
    for(int i = 0; i < n; i++){
        string s = "";
        for(int j = 0; j < m; j++){
            s += (char)(rand() % 26 + 97);
        }
        randomStrings[i] = s;
    }
    return randomStrings;
}




// Variables
int main()
{
    vector<string> test0 = createRandomStrings(10000, 10);
    cout<< "We start here: \n";
    
    for(int i = 0; i < test0.size(); i++)  cout << prhf(test0[i]) << '\n';

    return 0;
}