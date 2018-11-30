#include <iostream>
using namespace std;

int binarySearch(int a[], int start, int end, int x) {
    cout << "looking in [ " << start << ", " << end << " ] for " << x << endl;
    if(start > end) return -1;

    int middle = (( end - start ) / 2) + start;
    if(a[middle] == x) return middle;
    if(a[middle] < x ) return binarySearch(a, middle + 1, end, x);
    if(a[middle] > x ) return binarySearch(a, start, middle - 1, x);
}

int main() {

    int num1[] = {1, 3, 7, 9, 10, 10, 10, 14, 16, 20, 21};
    int num2[] = {1, 3, 7, 9, 10, 10, 10, 14, 16, 20};

    std::cout << binarySearch(num1, 0, 10, 21) << std::endl;
    std::cout << binarySearch(num2, 0, 9, 21) << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}