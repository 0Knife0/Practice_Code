// class_08 Hanoi
#include <iostream>
#include <string>

using namespace std;

void process(int N, string from, string to, string help) {
    if (N == 1)
        cout << "Move 1 from " << from << " to " << to << endl;
    else {
        process(N - 1, from, help, to);
        cout << "Move " << N << " from " << from << " to " << help << endl;
        process(N - 1, help, to, from);
    }
}

void hanoi(int N) {
    if (N > 0) process(N, "left", "right", "mid");
}

int main() {
    int N = 3;
    hanoi(N);
    return 0;
}