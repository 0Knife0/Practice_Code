// basic_calss_01 MaxGap
#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int bucket(long num, long len, long min, long max) {
    return (int)((num - min) * len /
                 (max - min));  //类比最大最小归一化，分在对应的桶
}

int maxGap(vector<int> nums) {
    if (nums.empty() || nums.size() < 2) return 0;
    int len = nums.size();
    int minNum = INT_MAX;
    int maxNum = INT_MIN;
    for (int i = 0; i < len; i++) {
        minNum = min(minNum, nums[i]);
        maxNum = max(maxNum, nums[i]);
    }
    if (minNum == maxNum) return 0;
    bool hasNum[len + 1] = {0};
    int maxs[len + 1], mins[len + 1];
    int bid = 0;
    //记录每个桶内最小值最大值
    for (int i = 0; i < len; i++) {
        bid = bucket(nums[i], len, minNum, maxNum);
        //有值选桶内最小的，无值直接赋值
        mins[bid] = hasNum[bid] ? min(mins[bid], nums[i]) : nums[i];
        maxs[bid] = hasNum[bid] ? max(maxs[bid], nums[i]) : nums[i];
        hasNum[bid] = true;
    }
    int res = 0;
    int lastMax = maxs[0];
    int i = 1;
    for (; i <= len; i++) {
        if (hasNum[i]) {
            res = max(res, mins[i] - lastMax);
            lastMax = maxs[i];
        }
    }
    return res;
}

// for test
int comparator(vector<int> nums) {
    if (nums.empty() || nums.size() < 2) return 0;
    sort(nums.begin(), nums.end());
    int gap = INT_MIN;
    for (int i = 1; i < nums.size(); i++) gap = max(nums[i] - nums[i - 1], gap);
    return gap;
}

// for test
void generateRandomArray(int maxSize, int maxValue, vector<int> &arr) {
    arr.clear();
    srand((int)time(0));
    for (int i = 0; i < maxSize; i++) {
        arr.push_back(rand() % (2 * maxValue) - maxValue);
    }
}

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
        if (maxGap(arr1) != comparator(arr2)) {
            cout << maxGap(arr1) << endl << comparator(arr2) << endl;
            succeed = false;
            break;
        }
    }
    if (succeed)
        cout << "Nice!" << endl;
    else
        cout << "Fucking fucked!" << endl;
}