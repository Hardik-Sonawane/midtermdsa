#include <iostream>
using namespace std;

class BST {
public:
    int salary;
    string name;
    BST *left;
    BST *right;

    BST(int s, string n) {
        salary = s;
        name = n;
        left = NULL;
        right = NULL;
    }

    BST* insert(BST* root, int s, string n) {
        if (root == NULL) 
            return new BST(s, n);
        if (s < root->salary)
            root->left = insert(root->left, s, n);
        else 
            root->right = insert(root->right, s, n);
        return root;
    }

    void search(BST* root, int s) {
        if (root == NULL) {
            cout << "Employee not found!\n";
            return;
        }
        if (root->salary == s) {
            cout << "Employee found: " << root->name << " - " << root->salary << endl;
            return;
        }
        if (s < root->salary) 
            search(root->left, s);
        else 
            search(root->right, s);
    }

    void display(BST* root) {
        if (root) {
            display(root->left);
            cout << "Name: " << root->name << "\tSalary: " << root->salary << endl;
            display(root->right);
        }
    }
    
    // Destructor helper function
    void clearTree(BST* root) {
        if (root) {
            clearTree(root->left);
            clearTree(root->right);
            delete root;
        }
    }
};

int main() {
    BST bst(0, "");
    BST* root = NULL;
    
    int ch, salary;
    string name;

    do {
        cout << "\nEmployee Management System\n";
        cout << "1. Insert Employee\n";
        cout << "2. Search Employee\n";
        cout << "3. Display Employees\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter salary: ";
                cin >> salary;
                root = bst.insert(root, salary, name);
                break;
            case 2:
                cout << "Enter salary to search: ";
                cin >> salary;
                bst.search(root, salary);
                break;
            case 3:
                cout << "\nEmployee List (sorted by salary):\n";
                bst.display(root);
                break;
            case 4:
                bst.clearTree(root);
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (ch != 4);

    return 0;
}
