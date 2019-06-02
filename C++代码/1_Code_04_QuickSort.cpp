// basic_calss_01 QuickSort
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

vector<int> partition(vector<int> &arr, int l, int r) {
    int less = l - 1;
    int more = r;
    while (l < more) {
        if (arr[l] < arr[r])
            swap(arr[++less], arr[l++]);
        else if (arr[l] > arr[r])
            swap(arr[--more], arr[l]);
        else
            l++;
    }
    swap(arr[more], arr[r]);
    return {less + 1, more};
}

void quickSort(vector<int> &arr, int l, int r) {
    if (l < r) {
        vector<int> p = partition(arr, l, r);
        quickSort(arr, l, p[0] - 1);
        quickSort(arr, p[1] + 1, r);
    }
}

void quickSort(vector<int> &arr) {
    if (arr.empty() || arr.size() < 2) {
        return;
    }
    quickSort(arr, 0, arr.size() - 1);
}

void comparator(vector<int> &arr) { sort(arr.begin(), arr.end()); }

// for test
void generateRandomArray(int maxSize, int maxValue, vector<int> &arr) {
    arr.clear();
    srand((int)time(0));
    for (int i = 0; i < maxSize; i++) {
        arr.push_back(rand() % (2 * maxValue) - maxValue);
    }
}

// for test
void printArray(vector<int> &arr) {
    if (arr.empty()) {
        return;
    }
    for (auto const a : arr) cout << a << " ";
    cout << endl;
}

// for test
int main() {
    int testTime = 50000;
    int maxSize = 100;
    int maxValue = 100;
    bool succeed = true;
    for (int i = 0; i < testTime; i++) {
        vector<int> arr1, arr2;
        arr1.clear();
        arr2.clear();
        generateRandomArray(maxSize, maxValue, arr1);
        arr2.assign(arr1.begin(), arr1.end());
        quickSort(arr1);
        comparator(arr2);
        if (arr1 != arr2) {
            succeed = false;
            break;
        }
    }
    if (succeed) {
        cout << "Nice!" << endl;
    } else {
        cout << "Fucking fucked!" << endl;
        vector<int> arr;
        arr.clear();
        generateRandomArray(maxSize, maxValue, arr);
        printArray(arr);
        quickSort(arr);
        printArray(arr);
    }
    system("pause");
    return 0;
}