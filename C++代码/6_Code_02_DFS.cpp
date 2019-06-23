// class_06 DFS
#include <iostream>
#include <stack>
#include "6_GraphGenerator.h"

using namespace std;

static void dfs(Node* node) {
    if (!node) return;
    stack<Node*> sta;
    set<Node*> tmp;
    sta.push(node);
    tmp.insert(node);
    cout << node->value << endl;
    while (!sta.empty()) {
        Node* cur = sta.top();
        for (auto next : cur->nexts) {
            if (tmp.find(cur) == tmp.end()) {
                sta.push(next);
                tmp.insert(next);
                cout << next->value << endl;
                break;
            }
        }
    }
}