// class_08 Factorial
#include <iostream>
#include <string>

using namespace std;

long getFactorial11(int n) {
    if (n == 1) return 1;
    return (long)n * getFactorial11(n - 1);
}

long getFactorial12(int n) {
    long res = 1;
    for (int i = 1; i <= n; i++) res *= i;
    return res;
}

int main() {
    int n = 5;
    cout << getFactorial11(n) << endl;
    cout << getFactorial12(n) << endl;
    return 0;
}