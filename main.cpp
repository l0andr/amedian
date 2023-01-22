#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>
#include "amedian_calc.h"
using namespace std;

template <typename T>
T naiveMedian(T a[], int n) {
    sort(a, a + n);
    if (n % 2 == 0) {
        return a[n / 2 - 1];
    } else {
        return a[n / 2];
    }
}

int main()
{

    int n = 20;
    vector<float> a(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(0, 100);

    for (int i = 0; i < n; i++) {
        a[i] = dis(gen); // generates a random number between 1 and 100
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Naive Median:"<<naiveMedian<float>(a.data(),a.size());
    cout << " QuickSelect Median:"<<quickselectMedian<float>(a.data(),a.size());

    return 0;
}
