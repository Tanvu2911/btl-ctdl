#include <bits/stdc++.h>
using namespace std; 
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(NULL), right(NULL) {}
};

class BStree {
private:
    Node* root;
public: 
 	BStree() : root() {}
    void insert(Node*& node, int value) {
        if (node == NULL) {
            node = new Node(value);
        } else if (value < node->data) {
            insert(node->left, value);
        } else {
            insert(node->right, value);
        }
    }

    void xapxep(Node* node) {
        if (node != NULL) {
            xapxep(node->left);
            cout << node->data << " ";
            xapxep(node->right);
        }
    }

    Node* search(Node* node, int value) {
        if (node == NULL || node->data == value) {
            return node;
        }
        if (value < node->data) {
            return search(node->left, value);
        }
        return search(node->right, value);
    }
    void insert(int value) {
        insert(root, value);
    }

    void xapxep() {
        xapxep(root);
        cout << endl;
    }

    Node* search(int value) {
        return search(root, value);
    }
};

int main() {
    BStree a;
    a.insert(5);
    a.insert(3);
    a.insert(7);
    a.insert(2);
    a.insert(4);
    a.insert(6);
    a.insert(8);
    a.insert(10);
	a.insert(9); 
    a.xapxep();

    int b = 4;
    Node* result = a.search(b);
    if (result) {
        cout << "yes: " << result->data << endl;
    } else {
        cout << "khong tim thay: " << b << endl;
    }

}
