#include <iostream>
using namespace std;

template <class T>
class Vector {
    int size = 1;
    int lastIndex = -1;
    T* data = nullptr;
public:
    Vector() {
        data = new T[1];
        size = 1;
    }

    Vector(int initialSize) {
        size = initialSize;
        data = new T[initialSize];
    }

    void insert(int index, T value) {
        lastIndex++;
        if(lastIndex == size) {     //expansion needed (double the size)
            T* newData = new T[size * 2];
            for(int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete data;
            data = newData;
            size *= 2;
        }


        for(int i = lastIndex; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value;
    }

    void push_back(T value) {
        lastIndex++;
        if(lastIndex == size) {     //expansion needed (double the size)
            T* newData = new T[size * 2];
            for(int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete data;
            data = newData;
            size *= 2;
        }

        data[lastIndex] = value;
    }

    void removeAt(int index) {
        //check if it's not out of range

        for(int i = index; i <= lastIndex - 1; i++)
            data[i] = data[i+1];
        lastIndex--;
    }

    T pop_back() {
        if(lastIndex < 0)
            return NULL;
        lastIndex--;
        return data[lastIndex + 1];
    }




};
int main() {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.insert(2, 1000);
    v.removeAt(3);
    cout << v.pop_back() << endl;
    cout << v.pop_back() << endl;
    cout << v.pop_back() << endl;
    cout << v.pop_back() << endl;
    cout << v.pop_back() << endl;
    cout << v.pop_back() << endl;
    cout << v.pop_back() << endl;
    cout << v.pop_back() << endl;
    return 0;
}