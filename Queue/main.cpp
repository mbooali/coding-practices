#include <iostream>
using namespace std;

class QueueArray {
private:
    int* data = nullptr;
    int size = 0, head = 0, tail = 0;

public:
    QueueArray() {}
    QueueArray(int size) {
        if(size < 1)
            throw "Minimum size for Queue is 1";
        this->size = size;
        data = new int[size];
    }
    ~QueueArray() {
        delete data;
    }

    void enque(int value) {
        if(this->tail == size) {
            //expand the queue's size
            auto newData = new int[this->size * 2];
            for(int i = 0; i < this->size; i++)
                newData[i] = this->data[i];
            delete data;
            this->data = newData;
            this->size *= 2;
            cout << "Expantion: " << endl;
        }

        this->data[this->tail] = value;
        this->tail++;
    }

    int deque() {
        if(this->head == this->tail) {
//            throw "Queue is empty";
            cout << "Queue is empty" << endl;
            return -1;
        }

        int returnValue = this->data[this->head];
        this->head++;
        if(this->head == this->tail) {
            this->head = this->tail = 0;
        }
        return returnValue;
    }
};

class Node {
public:
    Node() : next(nullptr), previous(nullptr) {}
    Node(int value): data(value), next(nullptr), previous(nullptr) {}
    ~Node() {}

    int data;
    Node* next;
    Node* previous ;
};

class QueueLinkedList {
private:
    Node* head = nullptr;
    Node* tail = nullptr;

public:
    QueueLinkedList() {}

    ~QueueLinkedList() {
        //free up the allocated memories
    }

    void enque(int value) {
        Node* toAdd = new Node(value);

        toAdd->previous = tail;
        toAdd->next = nullptr;
        if(tail != nullptr)
            tail->next = toAdd;
        tail = toAdd;
        if(head == nullptr)
            head = toAdd;
    }

    int deque() {
        if(head == tail && tail == nullptr) {
            cout << "empty! " ;
            return -1;
        }

        int returnValue = head->data;
        if(head == tail){
            head = tail = nullptr;
            return returnValue;
        }

        head->next->previous = nullptr;
        Node* headToRemove = head;
        head = head->next;
        delete headToRemove;

        return returnValue;

    }
};

int main() {

    QueueLinkedList q;

    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    q.enque(5);
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;

    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    q.enque(5);
    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    q.enque(5);
    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    q.enque(5);

    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;

    cout << q.deque() << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}