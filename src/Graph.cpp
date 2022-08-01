#include "../include/Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

Node* Graph::getNode(std::string ticker) {
   return ticker_to_node_[ticker];
}

void Graph::AddNode(std::string ticker) {
    Node* n = new Node(ticker);
    nodes_.push_back(n); 
    ticker_to_node_.insert({ticker, n});
}

void Graph::AddEdge(Node* node_1, Node* node_2, double sr_coeff) {
    Edge* e = new Edge(node_1, node_2, sr_coeff);
    node_1->edges_.push_front(e);
    node_2->edges_.push_front(e);
}


void Graph::LoadNodes(std::string filepath) {
  std::string line;
  std::ifstream myfile (filepath);
  if (myfile.is_open())
  {
    while (getline(myfile,line) )
    {    
      AddNode(line);
    }
    myfile.close();
  }

}

void Graph::LoadEdges(std::string filepath) {
  std::string line;
  std::ifstream myfile (filepath);
  if (myfile.is_open())
  {
    getline(myfile, line);
    while (getline(myfile,line))
    {
      std::vector<std::string> vec;
      std::stringstream ss(line);
      while(ss.good()) {
        std::string substr;
        getline(ss, substr, ',');
        vec.push_back(substr);
      }

      if (std::stod(vec[2]) >= .6) {
        Node* node_1 = ticker_to_node_.at(vec[0]);
        Node* node_2 = ticker_to_node_.at(vec[1]);
        AddEdge(node_1, node_2, std::stod(vec[2]));
      }
    }
    myfile.close();
  }
}