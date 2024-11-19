#include <iostream>
#include <ctime>
using namespace std;
struct SortMetrics {
    int comparisons;
    int swaps;
    double time;
};
SortMetrics insertionSort(int arr[], int n) {
    int comparisons = 0, swaps = 0;
    clock_t start = clock();
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
            swaps++;
        }
        comparisons++;
        arr[j + 1] = key;
    }
    return {comparisons, swaps, 1000000.0 * (clock() - start) / CLOCKS_PER_SEC};
}
SortMetrics bubbleSort(int arr[], int n) {
    int comparisons = 0, swaps = 0;
    clock_t start = clock();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
    return {comparisons, swaps, 1000000.0 * (clock() - start) / CLOCKS_PER_SEC};
}
void testSorts() {
    int sorted[] = {1, 2, 3, 4, 5};
    int nearlySorted[] = {1, 3, 2, 4, 5};
    int reverseSorted[] = {5, 4, 3, 2, 1};
    SortMetrics ins_sorted = insertionSort(sorted, 5);
    SortMetrics ins_nearly = insertionSort(nearlySorted, 5);
    SortMetrics ins_reverse = insertionSort(reverseSorted, 5);
    SortMetrics bub_sorted = bubbleSort(sorted, 5);
    SortMetrics bub_nearly = bubbleSort(nearlySorted, 5);
    SortMetrics bub_reverse = bubbleSort(reverseSorted, 5);
    cout << "Insertion - Sorted: " << ins_sorted.comparisons << ", " << ins_sorted.swaps << ", " << ins_sorted.time << endl;
    cout << "Insertion - Nearly: " << ins_nearly.comparisons << ", " << ins_nearly.swaps << ", " << ins_nearly.time << endl;
    cout << "Insertion - Reverse: " << ins_reverse.comparisons << ", " << ins_reverse.swaps << ", " << ins_reverse.time << endl;
    cout << "Bubble - Sorted: " << bub_sorted.comparisons << ", " << bub_sorted.swaps << ", " << bub_sorted.time << endl;
    cout << "Bubble - Nearly: " << bub_nearly.comparisons << ", " << bub_nearly.swaps << ", " << bub_nearly.time << endl;
    cout << "Bubble - Reverse: " << bub_reverse.comparisons << ", " << bub_reverse.swaps << ", " << bub_reverse.time << endl;
}
int main() {
    testSorts();
    return 0;
}
