#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node() {}
    Node(int value):data(value), left(nullptr), right(nullptr) {}
    ~Node(){}
};

class Tree {
public:
    Tree() {}
    Node* root = nullptr;
    void insert(int value) {
        if(root == nullptr) {
            root = new Node(value);
            return;
        }

        Node* current = root;

        while(true) {
            if(current->data > value) {
                if(current->left == nullptr) {
                    current->left = new Node(value);
                    return;
                }
                else {
                    current = current->left;
                    continue;
                }
            }

            if(current->data <= value) {
                if(current->right == nullptr) {
                    current->right = new Node(value);
                    return;
                }
                else {
                    current = current->right;
                    continue;
                }
            }
        }


    }

    void printPreOrder(Node* current) {
        if(current != nullptr) {
            cout << current->data << endl;
            printPreOrder(current->left);
            printPreOrder(current->right);
        }
        return;

    }

    void printBFS() {
        queue<Node*> processingQ;

        if(this->root == nullptr)
            return;

        Node* current = this->root;

        processingQ.push(current);
        while( ! processingQ.empty() ) {
            current = processingQ.front();
            cout << current->data << endl;
            if(current->left != nullptr) processingQ.push(current->left);
            if(current->right != nullptr) processingQ.push(current->right);
            processingQ.pop();
        }
    }

    void printDFS() {

    }


};
int main() {

    Tree t;

    //populate with some numbers

    t.insert(2);
    t.insert(4);
    t.insert(14);
    t.insert(8);
    t.insert(12);
    t.insert(7);
    t.insert(6);
    t.insert(9);
    t.insert(15);
    t.insert(11);
    t.insert(1);
    t.insert(13);
    t.insert(3);
    t.insert(10);
    t.insert(5);

//    t.printPreOrder(t.root);
    t.printBFS();
    return 0;
}