// class_06 GraphGenerator
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Edge;

class Node {
   public:
    int value;
    int in;
    int out;
    vector<Node*> nexts;
    vector<Edge> edges;

    Node() {}
    Node(int value) : value(value), in(0), out(0) {}
    ~Node() {}
};

class Edge {
   public:
    int weight;
    Node* from;
    Node* to;
    Edge() {}
    Edge(int weight, Node* from, Node* to)
        : weight(weight), from(from), to(to) {}
    friend bool operator<(Edge a, Edge b) { return a.weight > b.weight; }
    ~Edge() {}
};

class Graph {
   public:
    map<int, Node*> nodes;
    set<Edge> edges;
    Graph() {}
    ~Graph() {}
};

static Graph createGraph(const vector<vector<int>> matrix) {
    Graph graph;
    for (int i = 0; i < matrix.size(); i++) {
        int weight = matrix[i][0];
        int from = matrix[i][1];
        int to = matrix[i][2];
        if (graph.nodes.find(from) == graph.nodes.end())
            graph.nodes.insert({from, new Node(from)});
        if (graph.nodes.find(to) == graph.nodes.end())
            graph.nodes.insert({to, new Node(to)});
        Node* fromNode = graph.nodes[from];
        Node* toNode = graph.nodes[to];
        Edge newEdge(weight, fromNode, toNode);
        fromNode->nexts.push_back(toNode);
        fromNode->out++;
        toNode->in++;
        fromNode->edges.push_back(newEdge);
        graph.edges.insert(newEdge);
    }
    return graph;
}