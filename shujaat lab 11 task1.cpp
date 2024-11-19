#include <iostream>
#include <ctime>
using namespace std;
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
double testAndMeasure(int arr[], int n) {
    clock_t start = clock();
    insertionSort(arr, n);
    clock_t end = clock();
    return 1000000.0 * (end - start) / CLOCKS_PER_SEC;
}
int main() {
    int arr1[] = {64, 25, 12, 22, 11};
    int arr2[] = {1, 2, 3, 4, 5, 6, 7};
    int arr3[] = {50, 12, 33, 4, 5, 75, 21};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Time for arr1: " << testAndMeasure(arr1, n1) << " microseconds" << endl;
    cout << "Time for arr2: " << testAndMeasure(arr2, n2) << " microseconds" << endl;
    cout << "Time for arr3: " << testAndMeasure(arr3, n3) << " microseconds" << endl;
    return 0;
}