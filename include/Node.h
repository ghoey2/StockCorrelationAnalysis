#pragma once 

#include "Edge.h"
#include <string>
#include <list>

class Edge;
   
class Node {
    public:
      Node(std::string ticker);
      std::string ticker_; 
      std::list<Edge*> edges_;
};
