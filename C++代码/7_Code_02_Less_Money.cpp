// class_07 Less_Money
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int lessMoney(vector<int> arr) {
    priority_queue<int, vector<int>, greater<int> > pQ;
    for (const auto a : arr) pQ.push(a);
    int sum = 0;
    int cur = 0;
    while (pQ.size() > 1) {
        cur = pQ.top();
        pQ.pop();
        cur += pQ.top();
        pQ.pop();
        sum += cur;
        pQ.push(cur);
    }
    return sum;
}

int main() {
    vector<int> arr = {6, 7, 8, 9};
    cout << lessMoney(arr) << endl;
    vector<int> arrForHeap = {3, 5, 2, 7, 0, 1, 6, 4};

    // max heap
    priority_queue<int> minQ1;
    for (int i = 0; i < arrForHeap.size(); i++) minQ1.push(arrForHeap[i]);
    while (!minQ1.empty()) {
        cout << minQ1.top() << " " << endl;
        minQ1.pop();
    }

    // min heap use Comparator
    priority_queue<int, vector<int>, greater<int> > minQ2;
    for (int i = 0; i < arrForHeap.size(); i++) minQ2.push(arrForHeap[i]);
    while (!minQ2.empty()) {
        cout << minQ2.top() << " " << endl;
        minQ2.pop();
    }

    // max heap use comparator
    priority_queue<int, vector<int>, less<int> > maxQ;
    for (int i = 0; i < arrForHeap.size(); i++) maxQ.push(arrForHeap[i]);
    while (!maxQ.empty()) {
        cout << maxQ.top() << " " << endl;
        maxQ.pop();
    }

    return 0;
}