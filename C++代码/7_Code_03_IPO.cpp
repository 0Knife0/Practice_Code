// class_07 IPO
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node {
   public:
    int Profits;
    int Capital;

    Node(const int p, const int c) : Profits(p), Capital(c) {}
};

//大顶堆
bool maxProfits(const Node& o1, const Node& o2) {
    return o1.Profits < o2.Profits;
}

//小顶堆
bool minCapital(const Node& o1, const Node& o2) {
    return o2.Capital < o1.Capital;
}

int findMaximizedCapital(int k, int W, vector<int> Profits,
                         vector<int> Capital) {
    vector<Node> nodes;
    for (int i = 0; i < Profits.size(); i++) {
        Node node = Node(Profits[i], Capital[i]);
        nodes.push_back(node);
    }
    priority_queue<Node, vector<Node>, decltype(minCapital)*> minCapitalQ(
        minCapital);
    priority_queue<Node, vector<Node>, decltype(maxProfits)*> maxProfitsQ(
        maxProfits);
    for (int i = 0; i < nodes.size(); i++) minCapitalQ.push(nodes[i]);
    for (int i = 0; i < k; i++) {
        while (!minCapitalQ.empty() && minCapitalQ.top().Capital <= W) {
            maxProfitsQ.push(minCapitalQ.top());
            minCapitalQ.pop();
        }
        if (maxProfitsQ.empty()) return W;
        W += maxProfitsQ.top().Profits;
        maxProfitsQ.pop();
    }
    return W;
}

int main() { return 0; }