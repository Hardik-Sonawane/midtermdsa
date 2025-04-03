#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    string cities[20];
    for(int i = 0; i < n; i++) {
        cout << "Enter city " << i+1 << ": ";
        cin >> cities[i];
    }

    int matrix[20][20] = {0};

    char choice;
    do {
        string from, to;
        int time, fromIdx = -1, toIdx = -1;

        cout << "From city: ";
        cin >> from;
        cout << "To city: ";
        cin >> to;
        cout << "Time: ";
        cin >> time;

        for(int i = 0; i < n; i++) {
            if(cities[i] == from) fromIdx = i;
            if(cities[i] == to) toIdx = i;
        }

        if(fromIdx != -1 && toIdx != -1) {
            matrix[fromIdx][toIdx] = time;
            matrix[toIdx][fromIdx] = time;
            cout << "Added!\n";
        } else {
            cout << "City not found!\n";
        }

        cout << "Add more? (y/n): ";
        cin >> choice;
    } while(choice == 'y' || choice == 'Y');

    cout << "\nAdjacency Matrix:\n\t";
    for(int i = 0; i < n; i++) 
        cout << cities[i] << "\t";
    cout << endl;

    for(int i = 0; i < n; i++) {
        cout << cities[i] << "\t";
        for(int j = 0; j < n; j++) 
            cout << matrix[i][j] << "\t";
        cout << endl;
    }

    return 0;
}
