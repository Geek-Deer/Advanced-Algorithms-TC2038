/*
    Nombre: Diego Sánchez Luna
    Matrícula: A00227831
*/

// Libs
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <Windows.h>

using namespace std;

// Enable this to see progress, preferably to be turned on tbh
bool loader = true;

// Struct with Queen coords
struct Queen {
    int x;
    int y;
    Queen(int _x, int _y) : x(_x), y(_y) {}
};

// Functions

// Counting baddies (conflicts)
int countyCounter(const vector<Queen>& maLadies, int row, int col){
    int baddies = 0;

    // Check for conflicts in the same column and diagonals
    for(int i = 0; i < maLadies.size(); i++){
        if (i != row && (maLadies[i].y == col || abs(maLadies[i].y - col) == abs(i - row))) {
            baddies++;
        }
    }
    return baddies;
}

// Checking for the least amount of baddies
int minBaddiesRow(const vector<Queen>& maLadies, int row){
    int minBaddies = maLadies.size() + 1;
    vector<int> minBaddiesCols;

    for(int col = 0; col < maLadies.size(); col++){
        // Kind of brute forcing the min baddies but it works
        int baddies = countyCounter(maLadies, row, col);
        if(baddies < minBaddies){
            minBaddies = baddies;
            // We replace it
            minBaddiesCols.clear();
            minBaddiesCols.push_back(col);
        } else if(baddies == minBaddies){
            // We add it to a vector for later
            minBaddiesCols.push_back(col);
        }
    }

    // We get a random from before
    return minBaddiesCols[rand() % minBaddiesCols.size()];
}

// Getting everything together :>
void processEverything(vector<Queen>& maLadies, int maxStepies){
    srand(time(NULL));
    int stepies = 0;
    int baddies = 0;

    while(stepies < maxStepies){
        bool foundConflict = false;
        for(int i = 0; i < maLadies.size(); i++){
            baddies = countyCounter(maLadies, i, maLadies[i].y);
            if(baddies > 0) {
                maLadies[i].y = minBaddiesRow(maLadies, i);
                foundConflict = true;
                break;
            }
        }
        if(!foundConflict){
            // If we go through a whole iteration without finding a conflict,
            // we have a solution and can break the loop
            break;
        }
        stepies++;
    }

    if (stepies >= maxStepies && baddies > 0){
        cout << "No solution found in "<< stepies << " iterations." << '\n';        
    } else {
        cout << "Solution found after " << stepies << " iterations." << '\n';
    }
}

void printBoards(vector<Queen>& maLadies, vector<Queen>& maGrannies){
    // We print the board, checking where the queens really are
    for(int i = 0; i < maLadies.size(); i++){
        cout << i+1 << '\t';
        for(int j = 0; j < maLadies.size(); j++){
            if(maLadies[i].y == j){
                cout << "Q\t";
            } else {
                cout << ".\t";
            }
        }
        cout << '\n';
    }
    cout<<'\t';

    for(int i = 0; i < maLadies.size(); i++) cout << i+1 << '\t';

    // We print both the coords to compare them
    cout << "\n\nOriginal Coordinates: ";
    for(int i = 0; i < maGrannies.size(); i++) cout << "(" << maGrannies[i].x+1 << ", " << maGrannies[i].y +1<< ") ";
    cout << "\n";

    cout << "Processed Coordinates: "; 
    for(int i = 0; i < maLadies.size(); i++) for(int j = 0; j < maLadies.size(); j++) if(maLadies[i].y == j) cout << "(" << i+1 << ", " << j+1 << ") ";
    cout << "\n\n";
}


int main()
{
    // Creating "boards" with Queen objects
    vector<Queen> Board1, Board2, Board3, Board4, Board5;
    vector<Queen> Original1, Original2, Original3, Original4, Original5;

    srand(time(NULL));
    
    // We fill the boards with random queens nad get original coords for the laughs
    for (int i = 0; i < 8; i++) Board1.push_back(Queen(rand() % 8, rand() % 8));
    Original1 = Board1;
    Sleep(500);
    for (int i = 0; i < 8; i++) Board2.push_back(Queen(rand() % 8, rand() % 8));
    Original2 = Board2;
    Sleep(500);
    for (int i = 0; i < 8; i++) Board3.push_back(Queen(rand() % 8, rand() % 8));
    Original3 = Board3;
    Sleep(500);
    for (int i = 0; i < 8; i++) Board4.push_back(Queen(rand() % 8, rand() % 8));
    Original4 = Board4;
    Sleep(500);
    for (int i = 0; i < 8; i++) Board5.push_back(Queen(rand() % 8, rand() % 8));
    Original5 = Board5;


    // Show
    cout<<"Board 1: "<<'\n';
    printBoards(Board1, Original1);
    cout<<"Board 2: "<<'\n';
    printBoards(Board2, Original2);
    cout<<"Board 3: "<<'\n';
    printBoards(Board3, Original3);
    cout<<"Board 4: "<<'\n';
    printBoards(Board4, Original4);
    cout<<"Board 5: "<<'\n';
    printBoards(Board5, Original5);


    // We process the boards one by one
    processEverything(Board1, pow(10,7));
    processEverything(Board2, pow(10,7));
    processEverything(Board3, pow(10,7));
    processEverything(Board4, pow(10,7));
    processEverything(Board5, pow(10,7));

    // And finally print it out with coords and all
    cout<<"Board 1: "<<'\n';
    printBoards(Board1, Original1);
    cout<<"Board 2: "<<'\n';
    printBoards(Board2, Original2);
    cout<<"Board 3: "<<'\n';
    printBoards(Board3, Original3);
    cout<<"Board 4: "<<'\n';
    printBoards(Board4, Original4);
    cout<<"Board 5: "<<'\n';
    printBoards(Board5, Original5);

    return 0;
}
