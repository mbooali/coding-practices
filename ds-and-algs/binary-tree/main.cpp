#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* right = NULL;
    Node* left = NULL;
public:
    Node(int value): data(value) {}
    int getData() {return this->data;}
    void setData(int value) {this->data = value;}
    Node* getRight() {return this->right;}
    Node* getLeft() {return this->left;}
    void setRight(Node* rightPtr) {this->right = rightPtr;}
    void setLeft(Node* leftPtr) {this->left= leftPtr;}
};

class Tree {
private:
    Node* root = NULL;

public:
    void setRoot(Node* rootPtr) {this->root == rootPtr;}
    Node* getRoot() {return this->root;}

    void insertAsBST(int data) {
        Node *toAdd = new Node(data);

        if (this->root == NULL)
            this->root = toAdd; //first node of tree
        else {
            Node *parent = this->root;
            while( true ) {
                if(parent->getData() >= data) {

                    if(parent->getLeft() != NULL) {
                        parent = parent->getLeft();
                    }
                    else {
                        parent->setLeft(toAdd);
                        break;
                    }
                }
                else {
                    if(parent->getRight() != NULL) {
                        parent = parent->getRight();
                    }
                    else {
                        parent->setRight(toAdd);
                        break;
                    }
                }
            }
        }
    }

    void printPreOrder(Node* current) {
        if(current == NULL)
            return;
        cout << current->getData() << endl;
        printPreOrder(current->getLeft());
        printPreOrder(current->getRight());
    }


    Tree() {}
    ~Tree() {}
};

int main() {

    Tree t;
    t.insertAsBST(1);
    t.insertAsBST(0);
    t.insertAsBST(3);
    t.insertAsBST(6);
    t.insertAsBST(8);
    t.insertAsBST(0);
    t.insertAsBST(-1);
    t.insertAsBST(3);
    t.insertAsBST(5);
    t.insertAsBST(7);
    t.insertAsBST(-2);
    t.insertAsBST(-4);

    t.printPreOrder(t.getRoot());

    return 0;
}