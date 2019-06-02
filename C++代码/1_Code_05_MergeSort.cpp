//basic_calss_01 mergeSort
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

void merge(vector<int> &arr, vector<int> &arrL, vector<int> &arrR)
{
    int p1 = 0;
    int p2 = 0;
    int n1 = arrL.size();
    int n2 = arrR.size();
    while (p1 < n1 || p2 < n2)
    {
        if (p1 >= n1)
            arr.push_back(arrR[p2++]);
        else if (p2 >= n2)
            arr.push_back(arrL[p1++]);
        else if (arrL[p1] < arrR[p2])
            arr.push_back(arrL[p1++]);
        else
            arr.push_back(arrR[p2++]);
    }
}

void mergeSort(vector<int> &arr)
{
    if (arr.empty() || arr.size() < 2)
    {
        return;
    }
    vector<int> arrL, arrR;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (i < n / 2)
            arrL.push_back(arr[i]);
        else
            arrR.push_back(arr[i]);
    }
    mergeSort(arrL);
    mergeSort(arrR);
    arr.clear();
    merge(arr, arrL, arrR);
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
        mergeSort(arr1);
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
        mergeSort(arr);
        printArray(arr);
    }
    system("pause");
    return 0;
}