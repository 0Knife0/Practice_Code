// basic_calss_01 QuickSort
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

void heapInsert(vector<int> &arr, int index) {
    while (arr[index] > arr[(index - 1) / 2]) {
        swap(arr[index], arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void heapify(vector<int> &arr, int index, int size) {
    int left = index * 2 + 1;
    while (left < size) {
        int largest =
            left + 1 < size && arr[left + 1] > arr[left] ? left + 1 : left;
        largest = arr[largest] > arr[index] ? largest : index;
        if (largest == index) break;
        swap(arr[largest], arr[index]);
        index = largest;
        left = index * 2 + 1;
    }
}

void heapSort(vector<int> &arr) {
    if (arr.empty() || arr.size() < 2) return;
    for (int i = 0; i < arr.size(); ++i) heapInsert(arr, i);
    int size = arr.size();
    swap(arr[0], arr[--size]);
    while (size > 0) {
        heapify(arr, 0, size);
        swap(arr[0], arr[--size]);
    }
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
        heapSort(arr1);
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
        heapSort(arr);
        printArray(arr);
    }
    system("pause");
    return 0;
}