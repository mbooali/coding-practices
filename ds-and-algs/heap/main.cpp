#include <iostream>
using namespace std;

//Implement min-heap
class Heap {
public:
    int* harr = nullptr;
    int size = 0;
    int maxSize = 10;

    Heap() {
        harr = new int[10];
        delete harr;
    }
    ~Heap() {}

    int getLeftChild(int i) { return 2 * i + 1; }
    int getRightChild(int i) { return 2 * i + 2; }

    bool hasLeftChild(int i) { return (2 * i + 1) < size; }
    bool hasRightChild(int i) { return (2 * i + 2) < size; }

    int hasParent(int i) { return i > 0; }

    int getParent(int i) {

        if(i % 2 == 0) {
            return (i / 2) - 1;
        }

        if(i % 2 == 1) {
            return (i / 2);
        }
    }

    void expandAsNeeded() {
        if(size == maxSize) {
            int* newArray = new int[maxSize * 2];
            for(int i = 0; i < maxSize; i++)
                newArray[i] = harr[i];
            maxSize *= 2;
//            delete harr;
            harr = newArray;
        }
    }

    void insert(int value) {
        expandAsNeeded();
        harr[size] = value;
        size++;
        heapifyUpMin(size - 1);

        this->print();
    }

    int extractMin() {
        int min = harr[0];

        harr[0] = harr[size-1];
        size--;
        heapifyDownMin(0);
        return min;
    }

    void heapifyUpMin(int i) {

        int parent = 0;
        while(hasParent(i) && harr[getParent(i)] > harr[i]) {
            swap(harr[getParent(i)], harr[i]);
            heapifyDownMin(getParent(i));
            i = getParent(i);
        }
    }

    void heapifyDownMin(int i) {
        int smallest = i;
        int l = getLeftChild(i);
        int r = getRightChild(i);

        if(l < size && harr[l] < harr[smallest])
            smallest = l;
        if(r < size && harr[r] < harr[smallest])
            smallest = r;
        if(smallest != i) {
            swap(harr[i], harr[smallest]);
            heapifyDownMin(smallest);
        }


    }

    void print() {
        for(int i = 0; i < size; i++)
            cout << harr[i] << endl;

        cout << "--------------" << endl;
    }

};

int main() {

    Heap h;
    h.insert(10);
    h.insert(9);
    h.insert(8);
    h.insert(7);
    h.insert(6);
    h.insert(5);
    h.insert(4);
    h.insert(3);
    h.insert(2);
    h.insert(1);
    h.insert(0);

    h.print();

    //heapsort
    while(h.size > 0)
        cout << h.extractMin() << endl;

    return 0;
}