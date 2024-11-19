#include <iostream>
#include <ctime>
using namespace std;
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
}
}
}
}
double testAndMeasure(int arr[], int n) {
    clock_t start = clock();
    bubbleSort(arr, n);
    clock_t end = clock();
    return 1000000.0 * (end - start) / CLOCKS_PER_SEC;
}
int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {5, 4, 3, 2, 1};
    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Time for sorted array: " << testAndMeasure(arr1, n1) << " microseconds" << endl;
    cout << "Time for reverse sorted array: " << testAndMeasure(arr2, n2) << " microseconds" << endl;
    cout << "Time for random unsorted array: " << testAndMeasure(arr3, n3) << " microseconds" << endl;
    return 0;
}