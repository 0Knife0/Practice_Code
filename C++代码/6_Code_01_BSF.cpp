//class_06 BSF
#include <iostream>
#include <queue>
#include "6_GraphGenerator.h"

using namespace std;

static void bfs(Node* node){
    if (node == NULL) return;
    queue<Node*> que;
    set<Node*> tmp;
    que.push(node);
    tmp.insert(node);
    while(!que.empty()){
        Node* cur = que.front();
        cout << cur->value << endl;
        for(auto next: cur->nexts){
            if(tmp.find(next) == tmp.end()){
                tmp.insert(next);
                que.push(next);
            }
        }
    }
}