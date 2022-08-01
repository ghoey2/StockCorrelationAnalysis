#include "../include/BFS.h"
#include "../include/Graph.h"
#include <vector>
#include <queue>
#include <iostream>

std::vector<std::string> BFS::traverse(Node* start) {
    std::vector<std::string> vector_nodes;
    q_.push(start);
    traved_.insert({start, true});
    while (!q_.empty()) {
        Node* curr = q_.front();
        //std::cout<<curr->ticker_<<std::endl;
        q_.pop();
        vector_nodes.push_back(curr->ticker_);
        //std::cout << curr->ticker_ << " | ";
        for (Edge * e : curr->edges_) {
            Node* neighbor;
            if (e->node_1_ != curr) {
                neighbor = e->node_1_;
            } else {
                neighbor = e->node_2_;
            }
            //std::cout<<neighbor->ticker_<<std::endl;
            if (traved_.find(neighbor) == traved_.end() ) {
                //std::cout<<"here"<<std::endl;
                q_.push(neighbor);
                traved_.insert({neighbor, true});
            }
        }
    }
    
    return vector_nodes;
}