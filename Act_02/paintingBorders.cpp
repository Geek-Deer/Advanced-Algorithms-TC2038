/*

    Nombre: Diego Sánchez Luna
    Matrícula: A00227831

*/

#include <iostream>
#include <vector>

using namespace std;


// We check if the vector that we are checking is safe to color with X color using the graph and a result vector
bool isSafe(vector<vector<int>>& graph, int v, int color, vector<int>& result) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[v][i] == 1 && result[i] == color) {
            return false;
        }
    }
    return true;
}

// Here we are using backtracking to check all the solutions using the isSafe function to check if the vector is safe to color
void graphColoringUtil(vector<vector<int>>& graph, int m, int v, vector<int>& result, vector<vector<int>>& solutions) {
    // As always we have our base case to return the solution
    if (v == graph.size()) {
        solutions.push_back(result);
        return;
    }

    // We check all the colors to see if they are safe to use
    for (int color = 1; color <= m; color++) {
        if (isSafe(graph, v, color, result)) {
            result[v] = color;
            // Then we recall the function to check the next vector
            graphColoringUtil(graph, m, v + 1, result, solutions);
            result[v] = 0;
        }
    }
}

// We join all our previous functions to get an answer
void graphColoring(vector<vector<int>>& graph, int m) {
    // Initializing the variables for further use
    vector<int> result(graph.size(), 0);
    vector<vector<int>> solutions;
    graphColoringUtil(graph, m, 0, result, solutions);

    // After all the process we check the results and print a message respectively to the number of options that we have
    if (solutions.empty()) {
        // None found :P
        cout << "No hay solución\n";
    } else {
        // We print the solutions
        cout << "Soluciones: \n";
        for (int i = 0; i < solutions.size(); i++) {
            cout << "Solución número " << i + 1 << ": ";
            for (int j = 0; j < solutions[i].size(); j++) {
                cout << solutions[i][j] << " ";
            }
            cout << '\n';
        }
    }
}

int main() {
    // Example usage
    vector<vector<int>> graph = {
        // Mark
            {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        // Julia
            {1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
        // Brian
            {0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0},
        // Steve
            {1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0},
        // Amanda 
            {0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0},
        // Derek
            {0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1},
        // Kelly
            {0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1},
        // Allan
            {0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
        // Michelle
            {0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0},
        // Joanne
            {0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1},
        // Chris
            {0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0}
    };
    int m = 4; // Number of colors

    graphColoring(graph, m);
    cout << "[1] Rojo \t[2] Verde\t[3] Azul\t[4] Gris\n";

    return 0;
}
