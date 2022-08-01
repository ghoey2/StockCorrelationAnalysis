#pragma once 


#include <vector>
#include <string>
#include <list>
#include <map>
#include "Edge.h"
#include "Node.h"


    class Node;
    class Edge;

    class Graph {
        public:

            void AddNode(std::string ticker); 
            void AddEdge(Node* node_1, Node* node_2, double sr_coeff);  
            void LoadNodes(std::string filepath);
            void LoadEdges(std::string filepath);  
            Node* getNode(std::string ticker);
            std::vector<Node*> nodes_;
                
        //std::map<std::string, Node*> ticker_to_node_;

        private: 
            size_t node_count_ = 0;
            std::map<std::string, Node*> ticker_to_node_;
      

};