#include "amedian_calc.h"
#include <vector>
#include <algorithm>
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
T quickSelect(vector<T>& arr, int low, int high, int k) {
    if (low <= high) {
        int pivot_index = partition(arr, low, high);
        if (pivot_index == k) {
            return arr[pivot_index];
        } else if (pivot_index > k) {
            return quickSelect(arr, low, pivot_index - 1, k);
        } else {
            return quickSelect(arr, pivot_index + 1, high, k);
        }
    }
    return -1.0;
}

template <typename T>
T quickselectMedian(T a[], int n) {
    vector<T> myVector(a, a + n);
    T median = quickSelect(myVector, 0, n - 1, n / 2 - 1);
    return median;
    }

template <typename T>
T median_of_median(vector<T>& arr) {
    if (arr.size() <= 5) {
        sort(arr.begin(), arr.end());
        return arr[arr.size() / 2];
    }
    vector<T> medians;
    for (int i = 0; i < arr.size(); i += 5) {
        int sub_end = min((int)arr.size(), i + 5);
        vector<T> sub(arr.begin() + i, arr.begin() + sub_end);
        sort(sub.begin(), sub.end());
        medians.push_back(sub[sub.size() / 2]);
    }
    T median_of_medians = median_of_median(medians);
    vector<T> low, high;
    for (auto x : arr) {
        if (x < median_of_medians) {
            low.push_back(x);
        } else if (x > median_of_medians) {
            high.push_back(x);
        }
    }
    if (low.size() >= arr.size() / 2) {
        return median_of_median(low);
    } else if (low.size() + medians.size() >= arr.size() / 2) {
        return median_of_medians;
    } else {
        return median_of_median(high);
    }
}

template <typename T>
T medianOfMedian(T a[], int n) {
    vector<T> arr(a,a + n);
    T median = median_of_median(arr);
    return median;
}

template float quickselectMedian<float>(float a[], int n);
template float medianOfMedian<float>(float a[],int n);
