#include <iostream>
using namespace std;

void merge(int* a, int leftStart, int leftFinish, int rightStart, int rightFinish) {

    int* sorted = new int[leftFinish - leftStart + rightFinish - rightStart + 2];
    int i = leftStart, j = rightStart, sIndex = 0;

    while(i <= leftFinish && j <= rightFinish) {
        if(a[i] < a[j]) {
            sorted[sIndex] = a[i];
            i++;
        }
        else {
            sorted[sIndex] = a[j];
            j++;
        }
        sIndex++;
    }

    for(; i <= leftFinish; i++, sIndex++) {
        sorted[sIndex] = a[i];
    }

    for(; j <= rightFinish; j++, sIndex++) {
        sorted[sIndex] = a[j];
    }

    for(j = 0, i = leftStart; i <= rightFinish; i++, j++) {
        a[i] = sorted[j];
    }

}


void mergeSort(int* a, int start, int end) {

    if(end - start  < 1) return;

    int middle = start + ((end - start) / 2);

    mergeSort(a, start, middle);
    mergeSort(a, middle + 1, end);
    merge(a, start, middle, middle + 1, end);

}

int main() {
    //100 random numbers
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

    mergeSort(&numbers[0], 0, 99);

    for(int i = 0; i < 100; i++) {
        cout << numbers[i] << endl;
    }

    return 0;
}