// class_08 Print_All_Permutations
#include <iostream>
#include <string>

using namespace std;

void process(string str, int i) {
    if (i == str.size()) {
        cout << str << endl;
    }
    for (int j = i; j < str.size(); j++) {
        swap(str[i], str[j]);
        process(str, i + 1);
        swap(str[i], str[j]);
    }
}

void printAllPermutation(string str) { process(str, 0); }

int main() {
    string test1 = "abc";
    printAllPermutation(test1);
    return 0;
}