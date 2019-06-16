// class_05 HashMap
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, string> m;
    m.insert({"zuo", "31"});

    if (m.find("zuo") != m.end())
        cout << "true! value is: " << m["zuo"] << endl;
    else
        cout << "false" << endl;
}