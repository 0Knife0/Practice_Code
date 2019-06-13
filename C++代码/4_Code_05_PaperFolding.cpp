// class_04 PaperFolding
#include <iostream>

using namespace std;

static void printProcess(int i, int N, bool down) {
    if (i > N) return;
    printProcess(i + 1, N, true);
    string res = down ? "down" : "up";
    cout << res << endl;
    printProcess(i + 1, N, false);
}

static void printAllFolds(int N) { printProcess(1, N, true); }

int main() {
    int N = 4;
    printAllFolds(4);
}