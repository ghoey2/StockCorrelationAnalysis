#include "Graph.h"
#include <vector>
#include <string>
#include <stack>

using std::map;
using std::vector;
using std::string;

class ConnectedComponenets {
    public:
        vector<vector<string>> connectTheComponents();
        ConnectedComponenets(Graph graph);
    private:
        void fillOrder(Node* node, map<Node*, bool> &traved_, std::stack<int> &stack);
        vector<Node *> DFSTraverse(Node* node, map<Node*, bool> &traved_, vector<Node*> adjacent_nodes);

        Graph graph_;
        map<Node*, bool> traved_;
};