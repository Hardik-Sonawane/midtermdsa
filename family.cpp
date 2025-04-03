#include <iostream>
using namespace std;

class BT {
public:
    string data;
    BT *left; 
    BT *right;
    
    BT(string x) {
        data = x;
        left = NULL;
        right = NULL;
    }

    void insert(BT *parent, BT *child) {
        if (parent->left == NULL) {
            parent->left = child;
        } else {
            BT *temp = parent->left;
            while (temp->right != NULL) {
                temp = temp->right;
            }
            temp->right = child;
        }
    }

    BT* search(BT *parent, string member) {
        if (parent == NULL) 
            return NULL;
        if (parent->data == member) 
            return parent;

        BT *found = search(parent->left, member);
        if (found) 
            return found;

        return search(parent->right, member);
    }
    
    void display(BT *node, int level = 0) {
        if (node == NULL)
            return;
        
        // Print indentation based on level
        for (int i = 0; i < level; i++)
            cout << "    ";
        
        // Print current node
        cout << "└── " << node->data << endl;
        
        // Display children (left is first child, right is siblings)
        if (node->left != NULL) {
            display(node->left, level + 1);
        }
        if (node->right != NULL) {
            display(node->right, level);
        }
    }
};

int main() {
    int ch;
    string name;
    BT *root = NULL, *newnode;

    do {
        cout << "\nFamily Tree Management System\n";
        cout << "1. Insert new member\n";
        cout << "2. Search a member\n";
        cout << "3. Display family tree\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1: {
                cout << "Enter member name: ";
                cin >> name;
                newnode = new BT(name);
                if (root == NULL) {
                    root = newnode;
                    cout << "Added as root member.\n";
                }
                else {
                    cout << "Enter parent member: ";
                    string parent;
                    cin >> parent;
                    BT* parentNode = root->search(root, parent);
                    if (parentNode) {
                        root->insert(parentNode, newnode);
                        cout << "Member added successfully.\n";
                    }
                    else {
                        cout << "Parent not found!\n";
                        delete newnode; // Clean up if parent not found
                    }
                }
                break;
            }

            case 2: {
                cout << "Enter member to search: ";
                cin >> name;
                if (root && root->search(root, name))
                    cout << "Member found!\n";
                else
                    cout << "Member not found!\n";
                break;
            }
            
            case 3: {
                if (root == NULL) {
                    cout << "Family tree is empty.\n";
                } else {
                    cout << "\nFamily Tree Structure:\n";
                    root->display(root);
                }
                break;
            }
            
            case 9: {
                cout << "Exiting...\n";
                break;
            }
            
            default: {
                cout << "Invalid choice! Please try again.\n";
            }
        }
    } while (ch != 9);

    // TODO: Add memory cleanup here (delete all nodes)
    return 0;
}
