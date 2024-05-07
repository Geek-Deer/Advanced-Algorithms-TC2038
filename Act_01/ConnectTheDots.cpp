/*
    Nombre: Diego Sánchez Luna
    Matrícula: A00227831
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// We make a struct for the dots
struct dot {
    int x;
    int y;
    dot(int _x, int _y) : x(_x), y(_y) {}
};

// We get the distance between a pair of dots
int getDistance(const dot& a, const dot& b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// We get the distance between all the dots
int getDistance(const vector<dot>& dots) {
    int sum = 0;
    for (int i = 0; i < dots.size() - 1; i++) {
        sum += getDistance(dots[i], dots[i + 1]);
    }
    return sum;
}

// We randomly arrange the dots of the vector in a greedy way
void mixaroo(vector<dot>& dots) {
    // We make a new vector to store the new dot set
    vector<dot> newDots;
    newDots.push_back(dots[0]);

    // For better performance we store the used ones in a vector starting with the first one
    vector<bool> used(dots.size(), false);
    used[0] = true;

    for (int i = 1; i < dots.size(); i++) {
        // Minimum default distance (Any number will work) and the closest dot index
        int min = pow(10,6);
        int closePal = -1;

        // We iterate through the whole vector checking the closest, storing its index and distance, and also triggering it as used
        for (int j = 0; j < dots.size(); j++) {
            if (!used[j]) {
                int dist = getDistance(newDots.back(), dots[j]);
                if (dist < min) {
                    min = dist;
                    closePal = j;
                }
            }
        }

        newDots.push_back(dots[closePal]);
        used[closePal] = true;
    }
    // We finally replace the granny for the new one
    dots = newDots;
}

void printDots(const vector<dot>& dots) {
    cout << "{ ";
    for (int i = 0; i < dots.size(); i++) {
        cout << "( " << dots[i].x << ", " << dots[i].y << " )";
    }
    cout << "}\n";
}

int main() {
    // Initializing dots
    vector<int> x = {20, 20, 20, 30, 40, 40, 50, 60, 60, 60, 70, 80, 90, 90, 100, 100, 100, 100, 110, 110, 120, 130, 130, 140, 140, 150, 160, 170, 180, 180, 200, 200, 200};
    vector<int> y = {20, 40, 160, 120, 140, 150, 20, 40, 80, 200, 200, 150, 170, 170, 50, 40, 130, 150, 10, 70, 80, 70, 170, 140, 180, 50, 20, 100, 70, 200, 30, 70, 100};

    int n = x.size();
    vector<dot> dots;
    for (int i = 0; i < n; i++) {
        dots.push_back(dot(x[i], y[i]));
    }

    // We print the original distance and the new one
    printDots(dots);
    cout << "Original distance: " << getDistance(dots) << '\n';
    mixaroo(dots);
    cout << "Rearranged distance: " << getDistance(dots) << '\n';
    printDots(dots);
    return 0;
}
