// class_06 Kruskal
#include <iostream>
#include <queue>
#include "6_GraphGenerator.h"

using namespace std;

class UnionFind {
   private:
    map<Node*, Node*> fatherMap;  //节点和集合的代表节点
    map<Node*, int> rankMap;      //集合的代表节点和节点数量
    Node* findFather(Node* n) {
        Node* father = fatherMap[n];
        if (father != n) father = findFather(father);
        fatherMap.insert({n, father});
        return father;
    }

   public:
    UnionFind() = default;
    void makeSet(vector<Node*> nodes) {
        fatherMap.clear();
        rankMap.clear();
        for (const auto node : nodes) {
            fatherMap.insert({node, node});
            rankMap.insert({node, 1});
        }
    }
    bool isSameSet(Node* a, Node* b) { return findFather(a) == findFather(b); }
    void uni(Node* a, Node* b) {
        if (!a || !b) return;
        Node* aFather = findFather(a);
        Node* bFather = findFather(b);
        if (aFather != bFather) {
            int aFrank = rankMap[aFather];
            int bFrank = rankMap[bFather];
            if (aFrank <= bFrank) {
                fatherMap.insert({aFather, bFather});
                rankMap.insert({bFather, aFrank + bFrank});
            } else {
                fatherMap.insert({bFather, aFather});
                rankMap.insert({aFather, aFrank + bFrank});
            }
        }
    }
};

static set<Edge> kruskalMST(Graph graph) {
    UnionFind unionFind;
    vector<Node*> nodes;
    //构造并查集
    for (auto node : graph.nodes) nodes.push_back(node.second);
    unionFind.makeSet(nodes);
    //将边放入优先级队列，小顶堆
    priority_queue<Edge> priorityQueue;
    for (auto edge : graph.edges) priorityQueue.push(edge);
    set<Edge> result;
    while (!priorityQueue.empty()) {
        Edge edge = priorityQueue.top();
        priorityQueue.pop();
        //使用并查集检测边的两端点是否以联通
        if (!unionFind.isSameSet(edge.from, edge.to)) {
            result.insert(edge);
            unionFind.uni(edge.from, edge.to);
        }
    }
    return result;
}

int main() {}