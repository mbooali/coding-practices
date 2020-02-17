#include <iostream>
using namespace std;

int partition(int* a, int left, int right, int pivot) {

    //while to maintain the whole pointers
    while(left <= right) {

        //find the left bad value
        while(a[left] < pivot){
            left++;
        }
        //find the right bad value
        while(a[right] > pivot){
            right--;
        }
        //swap the bad value of left and right
        if(left <= right) {
            swap(a[left], a[right]);
            left++;
            right--;
        }
        //iterate
    }
    return left;
}

void quickSort(int* a, int left, int right) {
    if(left >= right) return;

    int pivot = a[(left+right)/2];

    int index = partition(a, left, right, pivot);

    //partion and call quick sort for each partition based on
    quickSort(a, left, index - 1);
    quickSort(a, index, right);
}

int main() {

    int numbers[] = {4, 38, 91, 7, 98, 6, 61, 16, 89, 17,
                     32, 36, 10, 55, 55, 25, 94, 48, 83,
                     14, 52, 8, 27, 58, 36, 32, 77, 37,
                     64, 49, 87, 18, 82, 37, 13, 47, 9,
                     12, 12, 70, 23, 91, 87, 39, 44, 66,
                     2, 9, 12, 64, 25, 25, 42, 74, 93, 68,
                     91, 16, 26, 33, 2, 70, 9, 2, 90, 43,
                     9, 58, 58, 35, 94, 30, 46, 93, 69, 76,
                     97, 24, 6, 22, 18, 46, 41, 100, 98, 41,
                     15, 57, 74, 46, 20, 8, 12, 25, 99, 63,
                     34, 13, 5, 32};

    quickSort(&numbers[0], 0, 99);

    for(int i = 0; i < 100; i++) {
        cout << numbers[i] << endl;
    }

    return 0;
}