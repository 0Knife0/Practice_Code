// class_08 Print_All_Subsquences
#include <iostream>
#include <string>

using namespace std;

void process(const string str, int i, string res) {
    if (i == str.size()) {
        cout << res << endl;
        return;
    }
    process(str, i + 1, res);
    process(str, i + 1, res + str[i]);
}

void printAllSubsquence(string str) {
    process(str, 0, "");
    return;
}

int main() {
    string str = "abc";
    printAllSubsquence(str);
    return 0;
}