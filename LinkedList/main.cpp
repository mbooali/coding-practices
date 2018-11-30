#include <iostream>

using namespace std;

class Node {
private:
    Node* next;
    int data;

public:
    Node* getNext() {return next;}
    void setNext(Node* nextPtr) {this->next = nextPtr;}

    void setData(int data) {this->data = data;}
    int getData() {return this->data;}

    Node(int value):data(value), next(NULL){}
    ~Node() {}
};

class LinkedList {
private:
    Node* head;

public:
    Node* getHead() {
        return this->head;
    }

    void setHead(Node* headPtr) {
        this->head = headPtr;
    }

    void insert(int data) {
        Node* newNode = new Node(data);

        if(this->head == NULL) {
            this->head = newNode;
        }
        else {
            newNode->setNext(head);
            this->head = newNode;
        }
    }

    void remove() {
        if(head == NULL)
            return;
        Node* toRemove = head;
        head = head->getNext();
        delete toRemove;
    }



    LinkedList() {}

    ~LinkedList() {}
};

int main() {
    LinkedList l;

    l.insert(1);
    l.insert(4);
    l.insert(7);
    l.insert(2);

    Node* current = l.getHead();

    while(current != NULL) {
        cout << current->getData() << endl;
        current = current->getNext();
    }
    return 0;
}