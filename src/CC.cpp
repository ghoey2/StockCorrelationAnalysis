#include "../include/CC.h"
#include <stack>
#include <map>

using std::stack;

vector<Node*> ConnectedComponenets::DFSTraverse(Node* node, map<Node*, bool> &traved_, vector<Node*> adjacent_nodes) {
    traved_.insert({node, true});
    adjacent_nodes.push_back(node);
    for (Edge * edge : node->edges_) {
        Node* neighbor;
        if (edge->node_1_ != node) {
            neighbor = edge->node_1_;
        } else {
            neighbor = edge->node_2_;
        }
        if (traved_.find(neighbor) != traved_.end()) {
            DFSTraverse(neighbor, traved_, adjacent_nodes);
        }
    }
}

void ConnectedComponenets::fillOrder(Node* node, map<Node*, bool> &traved_, std::stack<int> &stack) {
    traved_.insert({node, true});
    for (Edge * edge : node->edges_) {
        Node* neighbor;
        if (edge->node_1_ != node) {
            neighbor = edge->node_1_;
        } else {
            neighbor = edge->node_2_;
        }
        if (traved_.find(neighbor) != traved_.end()) {
            DFSTraverse(neighbor, traved_, stack);
        }
    }
    stack.push(node);
}

ConnectedComponenets::ConnectedComponenets(Graph graph) {
    graph_ = graph;
    traved_ = map<Node*, bool>();
}

vector<vector<string>> ConnectedComponenets::connectTheComponents() {
    stack<Node*> stack;
    traved_ = map<Node*, bool>();
    for (Node* node : graph.nodes) {
        if (map.find(node) != map.end()) {
            fillOrder(node, map, stack);
        }
    }

    traved_ = map<Node*, bool>();

    while(!stack.empty()) {
        Node* node = stack.top();
        stack.pop();
        vector<vector<Node*>> connected_components;
        if (map.find(node) != map.end()) {
            vector<Node*> component = DFSTraverse(node, traved_);
            connected_components.push_back(component);
        }
    }

    return connected_components;
}