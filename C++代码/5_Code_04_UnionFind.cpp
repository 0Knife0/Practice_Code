// class_05 UnionFind
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

/* struct Node {
    // whatever you like
}; */

class UnionFindSet {
   public:
    map<string, string> fatherMap;
    map<string, int> sizeMap;

   private:
    string findHead(string node) {
        string father = fatherMap[node];
        if (father != node) father = findHead(father);
        fatherMap.insert({node, father});
        return father;
    }

   public:
    UnionFindSet() = default;

    void makeSet(vector<string> nodes) {
        fatherMap.clear();
        sizeMap.clear();
        for (auto node : nodes) {
            fatherMap.insert({node, node});
            sizeMap.insert({node, 1});
        }
    }

    bool isSameSet(string a, string b) { return findHead(a) == findHead(b); }

    void uni(string a, string b) {
        if (a == null || b == null) return;
        string aHead = findHead(a);
        string bHead = findHead(b);
        if (aHead != bHead) {
            int aSetSize = sizeMap[aHead];
            int bSetSize = sizeMap[bHead];
            if (aSetSize <= betSize) {
                fatherMap.insert({aHead, bHead});
                sizeMap.insert({bHead, aSetSize + bSetSize});
            } else {
                fatherMap.insert({bHead, aHead});
                sizeMap.insert({aHead, aSetSize + bSetSize});
            }
        }
    }
};

int main() {}