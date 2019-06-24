// class_06 TopologySort
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include "6_GraphGenerator.h"

using namespace std;

static vector<Node*> sortedTopology(Graph grahp) {
    map<Node*, int> inMap;
    queue<Node*> zeroInQueue;
    for (auto node : grahp.nodes) {
        inMap.insert({node.second, node.second->in});
        if (node.second->in == 0) {
            zeroInQueue.push(node.second);
        }
    }
    vector<Node*> result;
    while (!zeroInQueue.empty()) {
        Node* cur = zeroInQueue.front();
        result.push_back(cur);
        for (auto next : cur->nexts) {
            inMap.insert({next, inMap[next] - 1});
            if (inMap[next] == 0) zeroInQueue.push(next);
        }
    }
    return result;
}