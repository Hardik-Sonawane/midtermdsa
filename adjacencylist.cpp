#include <iostream>
using namespace std;

struct Node {
    string city;
    int time;
    Node* next;
};

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    Node* cityList[20] = {nullptr};
    string cityNames[20];

    for(int i = 0; i < n; i++) {
        cout << "Enter city " << i+1 << ": ";
        cin >> cityNames[i];
    }

    char choice;
    do {
        string from, to;
        int time, fromIdx = -1;

        cout << "From city: ";
        cin >> from;
        cout << "To city: ";
        cin >> to;
        cout << "Time: ";
        cin >> time;

        for(int i = 0; i < n; i++) {
            if(cityNames[i] == from) {
                fromIdx = i;
                break;
            }
        }

        if(fromIdx != -1) {
            Node* newNode = new Node{to, time, nullptr};
            
            if(cityList[fromIdx] == nullptr) {
                cityList[fromIdx] = newNode;
            } else {
                Node* temp = cityList[fromIdx];
                while(temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
            cout << "Added!\n";
        } else {
            cout << "City not found!\n";
        }

        cout << "Add more? (y/n): ";
        cin >> choice;
    } while(choice == 'y' || choice == 'Y');

    cout << "\nAdjacency List:\n";
    for(int i = 0; i < n; i++) {
        cout << cityNames[i] << " -> ";
        Node* temp = cityList[i];
        while(temp != nullptr) {
            cout << temp->city << "(" << temp->time << ") ";
            temp = temp->next;
        }
        cout << endl;
    }

    return 0;
}
