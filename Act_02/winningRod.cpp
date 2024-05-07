/*
    Nombre: Diego Sánchez Luna
    Matrícula: A00227831
*/

// Libs
#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <cmath>


using namespace std;

// Funciones

int smartSnipSnip(vector<int>& _prices, int _length) {
    // Base case - return 0 if length is 0
    if (_length == 0 || _length > 10) return 0;

    // Create a dynamic programming array
    vector<int> dp(_length + 1, 0);

    for (int i = 1; i <= _length; i++) {
        int max_val = -100;
        for (int j = 0; j < i; j++)  max_val = max(max_val, _prices[j] + dp[i - j - 1]);
        dp[i] = max_val;
    }

    return dp[_length];
}


int snipSnip(vector<int>& _prices, int _length){
    // Base case so... Bye-bye :)
    if(_length == 0 || _length > 10) return 0;

    // We can't compare to nothing so we set a negative number as placeholder
    int last_max = -100;

    // We check for the max value summed with the residue of the rod using the same function
    for(int i = 0; i < _length; i++){
        if(last_max < _prices[i] + snipSnip(_prices, _length - i - 1)) last_max = _prices[i] + snipSnip(_prices, _length - i - 1);        
    }

    return last_max;

}



// Variables
int main()
{

    cout<<fixed;

    vector<int> prices = {1,5,8,9,10,17,17,20,24,30};

    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> t;

    for(int i = 1; i < 10; i++){
        start = std::chrono::system_clock::now();
        cout<<"Max Ka-Ching for "<<i<<" meters of rod: "<< snipSnip(prices, i) <<'\n';
        end = std::chrono::system_clock::now();
        t = end - start;
        cout<<"Time: "<< t.count() * 1000 <<" ms\n";
    }
    cout<<"\nNow its time for the DP approach:\n";
    for(int i = 1; i < 10; i++){
        start = std::chrono::system_clock::now();
        cout<<"Max Ka-Ching for "<<i<<" meters of rod: "<< smartSnipSnip(prices, i) <<'\n';
        end = std::chrono::system_clock::now();
        t = end - start;
        cout<<"Time: "<< t.count() * 1000 <<" ms\n";
    }
    return 0;
}