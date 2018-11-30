#include <iostream>
#include <exception>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(){}
    ~Node(){}
};

class Stack {
    Node* head = NULL;
public:
    Stack() {}
    ~Stack() {}

    void push(int value) {
        Node* toAdd = new Node();

        toAdd->next = head;
        head = toAdd;
    }

    void pop() {

        if(this->head != NULL) {
            Node* toBeRemoved = this->head;
            this->head = this->head->next;
            delete toBeRemoved;
            return;
        }
        throw "Empty Stack";
    }

    int top() {
        if(this->head != NULL)
            return this->head->data;
        throw "Empty Stack";
    }
};

int main() {

    Stack s;
    s.push(1);
    s.push(3);
    s.push(4);
    s.push(6);
    s.push(-1);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();


    return 0;
}