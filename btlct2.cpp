#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string eng;
    string vn;
    Node* left;
    Node* right;
    Node(string eng, string vn) : eng(eng), vn(vn), left(NULL), right(NULL) {
    }
};

class Tudien {
private:
    Node* root;

public:
    Tudien() : root(NULL) {
    }

    void insert(Node*& node, string eng, string vn) {
        if (node == NULL) {
            node = new Node(eng, vn);
        } else if (eng < node->eng) {
            insert(node->left, eng, vn);
        } else if (eng > node->eng) {
            insert(node->right, eng, vn);
        }
    }
	void openfile(string name){
		ifstream file(name);
		if(file.is_open()){
			cout << "mo file thanh cong.\n";
			string line;
			while(getline(file, line)){
				size_t pos = line.find(":");
				string eng = line.substr(0,pos);
				string vn = line.substr(pos + 1);
				addWord(eng,vn); 
			}
			file.close(); 
		}
		else {
			cout<<"khong mo duoc file"<<endl; 
		} 
		 
	}
    void infile(Node* node, ofstream& file) {
        if (!node) return; 
        infile(node->left, file);
        file << node->eng << ":" << node->vn << endl;
    	infile(node->right, file);
        
    }
    void printTree(Node* node) {
	    if (!node) return;
	    printTree(node->left);
	    cout << node->eng << ":" << node->vn << endl;
	    printTree(node->right);
	}
	void printTree(){
		printTree(root);
	}

    Node* search(Node* node, string eng) {
        if (node == NULL || node->eng == eng) {
            return node;
        } else if (eng < node->eng) {
            return search(node->left, eng);
        } else {
            return search(node->right, eng);
        }
    }

    Node* deletenode(Node* node, string eng) {
        if (node == NULL) return node;
        else if (eng < node->eng) {
            node->left = deletenode(node->left, eng);
        } else if (eng > node->eng) {
            node->right = deletenode(node->right, eng);
        } else {
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = minValueNode(node->right);
            node->eng = temp->eng;
            node->vn = temp->vn;
            node->right = deletenode(node->right, temp->eng);
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }

    void updateMeaning(Node* node,  string eng,  string newMeaning) {
        if (node) {
            if (node->eng == eng) {
                node->vn = newMeaning;
            } else if (eng < node->eng) {
                updateMeaning(node->left, eng, newMeaning);
            } else {
                updateMeaning(node->right, eng, newMeaning);
            }
        } else {
            cout << "Word '" << eng << "' not found for update." << endl;
        }
    }

    void saveToFile(string name) {
        ofstream file(name);
        if (file.is_open()) {
        	cout<<"mo file thanh cong"; 
            infile(root, file);
            file.close();
        } else {
            cout << "no" << endl;
        }
    }    

    void addWord( string eng, const string vn) {
        insert(root, eng, vn);
    }

    void remove(string eng) {
        root = deletenode(root, eng );
    }

    void updateWordMeaning( string eng,  string newMeaning) {
        updateMeaning(root, eng, newMeaning);
    }

    string searchWord(string eng) {
        Node* result = search(root, eng);
        return result ? result->vn : "Not found";
    }
};

int main() {
    Tudien a;
	a.openfile("vvt.txt"); 
    a.addWord("apple", "tao");
    a.addWord("banana", "chuoi");
    a.addWord("orange", "cam");
    a.addWord("mango", "xoai");
    a.updateWordMeaning("banana", "qua oi");
    string meaning = a.searchWord("apple");
    cout << "Meaning of 'apple': " << meaning << endl;
    a.remove("apple");
    a.printTree();
	a.saveToFile("vvt.txt");
    return 0;
}

