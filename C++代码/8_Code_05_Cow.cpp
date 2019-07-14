// class_08 Cow
#include <iostream>

using namespace std;

int cowNumber(int n) {
    if (n < 1) return 0;
    if (n >= 1 && n <= 3) return n;
    return cowNumber(n - 1) + cowNumber(n - 3);
}

int main() {
    int n = 20;
    cout << cowNumber(n) << endl;
    return 0;
}