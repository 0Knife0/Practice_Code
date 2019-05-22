// basic_calss_01 NetherlandsFlags
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

vector<int> partition(vector<int> &arr, int l, int r, int p) {
    int less = l - 1;
    int more = r + 1;
    while (l < more) {
        if (arr[l] < p)
            swap(arr[++less], arr[l++]);
        else if (arr[l] > p)
            swap(arr[l], arr[--more]);
        else
            ++l;
    }
    return {less + 1, more - 1};
}

void printArray(vector<int> &arr) {
    if (arr.empty()) {
        return;
    }
    for (auto const &a : arr) cout << a << " ";
    cout << endl;
}

int main() {
    vector<int> test = {1, 5, 8, 2, 5, 3, 9, 3};
    partition(test, 0, test.size() - 1, 5);
    printArray(test);
}