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


// Functions
void merge(vector<int>& arr, int l, int m, int r) {
    int ls = m - l + 1;
    int rs = r - m;

    vector<int> leftie(ls);
    vector<int> rightie(rs);

    for (int i = 0; i < ls; ++i) leftie[i] = arr[l + i];
    for (int i = 0; i < rs; ++i) rightie[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < ls && j < rs) {
        if (leftie[i] <= rightie[j]) {
            arr[k++] = leftie[i++];
        } else {
            arr[k++] = rightie[j++];
        }
    }

    while (i < ls) {
        arr[k++] = leftie[i++];
    }

    while (j < rs) {
        arr[k++] = rightie[j++];
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
    
}

void printArray(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<' ';
    }
}

// Variables

int main() {
    
    // Transforming scientific to decimal
    cout << fixed;
    
    vector<int> test0 = {12, 11, 13, 5, 6, 7};
    vector<int> test1 = {11, 13, 15, 9, 2, 8, 6, 20, 21, 23 ,11};
    vector<int> test2 = {2, 3, 1, 4, 5, 6, 1, 2, 8, 9, 10, 10};
    
    vector<int> test3;
    vector<int> test4;
    vector<int> test5;
    
    // Vector filling
    for(int i = 0; i < 5*pow(10, 7);i++){
        test3.push_back(rand());
    }
    for(int i = 0; i< 8*pow(10, 7);i++){
        test4.push_back(rand());
    }
    for(int i = 0; i<pow(10, 7);i++){
        test5.push_back(rand());
    }


    // Timed Sorting
    auto start = std::chrono::system_clock::now();
    mergeSort(test0, 0, test0.size() - 1);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> t1 = end - start;

    start = std::chrono::system_clock::now();
    mergeSort(test1, 0, test1.size() - 1);
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> t2 = end - start;
    
    start = std::chrono::system_clock::now();
    mergeSort(test2, 0, test2.size() - 1);
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> t3 = end - start;
    
    start = std::chrono::system_clock::now();
    mergeSort(test3, 0, test3.size() - 1);
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> t4 = end - start;
    
    start = std::chrono::system_clock::now();
    mergeSort(test4, 0, test4.size() - 1);
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> t5 = end - start;
    
    start = std::chrono::system_clock::now();
    mergeSort(test5, 0, test5.size() - 1);
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> t6 = end - start;

    // Printing
    cout << "Arreglo 1: " << test0.size();
    cout<<'\n'<<"Time: "<< t1.count()<<" Seconds"<<'\n';
    
    cout << "Arreglo 2: "<< test1.size();
    cout<<'\n'<<"Time: "<< t2.count()<<" Seconds"<<'\n';
    
    cout << "Arreglo 3: "<< test2.size();
    cout<<'\n'<<"Time: "<< t3.count()<<" Seconds"<<'\n';
    
    cout << "Arreglo 4: "<< test3.size();
    cout<<'\n'<<"Time: "<< t4.count()<<" Seconds"<<'\n';
    
    cout << "Arreglo 5: "<< test4.size();
    cout<<'\n'<<"Time: "<< t5.count()<<" Seconds"<<'\n';
    
    cout << "Arreglo 6: "<< test5.size();
    cout<<'\n'<<"Time: "<< t6.count()<<" Seconds"<<'\n';

    // What can I say, it's a mergeSort ¯\('u')/¯

    return 0;
}
