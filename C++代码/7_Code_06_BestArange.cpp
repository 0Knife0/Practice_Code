// class_07 BestArange
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Program {
   public:
    int start;
    int end;

    Program(const int s, const int e) : start(s), end(e) {}
};

bool comp(const Program &o1, const Program &o2) { return o1.end < o2.end; }

int bestArrange(vector<Program> programs, int start) {
    sort(programs.begin(), programs.end(), comp);
    int res = 0;
    for (int i = 0; i < programs.size(); i++) {
        if (start <= programs[i].start) {
            res++;
            start = programs[i].end;
        }
    }
    return res;
}

int main() { return 0; }