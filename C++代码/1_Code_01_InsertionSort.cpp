//basic_calss_01 InsertionSort
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

void insertionSort(vector<int> &arr)
{
    if (arr.empty() || arr.size() < 2)
    {
        return;
    }
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = i - 1; arr[j] > arr[j + 1] && j >= 0; j--)
        {
            swap(arr[j], arr[j + 1]);
        }
    }
}

void comparator(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
}

//for test
void generateRandomArray(int maxSize, int maxValue, vector<int> &arr)
{
    arr.clear();
    srand((int)time(0));
    for (int i = 0; i < maxSize; i++)
    {
        arr.push_back(rand() % (2 * maxValue) - maxValue);
    }
}

//for test
void printArray(vector<int> &arr)
{
    if (arr.empty())
    {
        return;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//for test
int main()
{
    int testTime = 50000;
    int maxSize = 100;
    int maxValue = 100;
    bool succeed = true;
    for (int i = 0; i < testTime; i++)
    {
        vector<int> arr1, arr2;
        arr1.clear();
        arr2.clear();
        generateRandomArray(maxSize, maxValue, arr1);
        arr2.assign(arr1.begin(), arr1.end());
        insertionSort(arr1);
        comparator(arr2);
        if (arr1 != arr2)
        {
            succeed = false;
            break;
        }
    }
    if (succeed)
    {
        cout << "Nice!" << endl;
    }
    else
    {
        cout << "Fucking fucked!" << endl;
        vector<int> arr;
        arr.clear();
        generateRandomArray(maxSize, maxValue, arr);
        printArray(arr);
        insertionSort(arr);
        printArray(arr);
    }
    system("pause");
    return 0;
}