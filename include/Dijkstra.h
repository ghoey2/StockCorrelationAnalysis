#pragma once 
#include "Graph.h"
#include <map>

class Dijkstra {
    public: 
        /**
        * computes the distances from source to every other node
        * stores the paths and distacnes in the maps
        * param: source; the node to calculate distance from
        **/
        void ComputeDistances(Graph& G, Node* source);

        /**
        * returns the path the shortest path to the passed node follows
        * param: node; the node you want the shortest path too
        * return: a vector of tickers starting at the source and ending with the passed node, 
        * if there is no path this returns an empty vector
        **/
        std::vector<std::string> NodesPath(Node* node);

        /**
        * returns the distance from one node to another
        * param: node; the node you want the distance too
        **/
        double GetDist(Node* node);


        /*
        this representation of the node allows the nodes to hold a distance from the source, that can be updated while in the heap
        */ 
        struct DjikNode {
            Node* node_;
            double dist_; 

            bool operator <(const DjikNode& d) {
                return dist_ > d.dist_;
            }

        };

        /*
        This is the comparison that allows the min heap to be made
        */
        struct Comp { 
            bool operator()(const DjikNode* a,const DjikNode* b) const { 
                return a->dist_ > b->dist_;
            }    
        }; 

    private: 
        std::map<Node*, Node*> previous_;  
        std::map<Node*, double> distances_; 
        /**
        * this is the node that calculate distances is called on last. and what the Nodepath and getdistance are based on
        **/
        Node* source_; 
};