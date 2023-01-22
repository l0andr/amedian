#include "amedian_calc.h"
#include <vector>
using namespace std;

template <typename T>
T partition(vector<T>& arr, int low, int high) {
    T pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename T>
T quickselect(vector<T>& arr, int low, int high, int k) {
    if (low <= high) {
        int pivot_index = partition(arr, low, high);
        if (pivot_index == k) {
            return arr[pivot_index];
        } else if (pivot_index > k) {
            return quickselect(arr, low, pivot_index - 1, k);
        } else {
            return quickselect(arr, pivot_index + 1, high, k);
        }
    }
    return -1.0;
}

template <typename T>
T quickselectMedian(T a[], int n) {
    vector<T> myVector(a, a + n);
    T median = quickselect(myVector, 0, n - 1, n / 2 - 1);
    return median;
    }

template float quickselectMedian<float>(float a[], int n);
