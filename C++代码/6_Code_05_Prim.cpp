// class_06 Prim
#include <iostream>
#include <queue>
#include <stack>
#include "6_GraphGenerator.h"

using namespace std;

static set<Edge> primMst(Graph graph) {
    priority_queue<Edge> priorityQueue;  //边集的小顶堆
    set<Node*> node_set;                 //已经走过的点集
    set<Edge> result;                    //符合情况的边集
    for (auto node : graph.nodes) {
        //取图中的一个点，看是否走过
        if (node_set.find(node.second) == node_set.end()) {
            //没走过的点加入走过的点集
            node_set.insert(node.second);
            //将这个点连接的边加入边集的小顶堆
            for (auto edge : node.second->edges) {
                priorityQueue.push(edge);
                //当边集的小顶堆不为空时
                while (!priorityQueue.empty()) {
                    //弹出边集中最小的边
                    Edge edge = priorityQueue.top();
                    priorityQueue.pop();
                    Node* toNode = edge.to;
                    //如果边的到达点是一个新的点，加入它
                    if (node_set.find(toNode) == node_set.end()) {
                        node_set.insert(toNode);
                        result.insert(edge);
                        for (auto nextEdge : toNode->edges)
                            priorityQueue.push(nextEdge);
                    }
                }
            }
        }
    }
    return result;
}
int main() {}