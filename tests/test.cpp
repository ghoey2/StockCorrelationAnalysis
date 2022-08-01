#include "../cs225/catch/catch.hpp"
#include "../Graph.h"
#include "../Edge.h"
#include "../Node.h"
#include "../BFS.h"
#include "../Dijkstra.h"

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

TEST_CASE("pass", "[weight=10][valgrind]") {
    REQUIRE(1 == 1);
}

// TEST_CASE("fail", "[weight=20][valgrind]") {
//     REQUIRE(0 == 1);
// }

TEST_CASE("Load Nodes", "[weight=20][valgrind]") {
    Graph G;
    G.LoadNodes("tests/test_data/test_nodes.txt");
    REQUIRE(((G.nodes_[0])->ticker_) == "AAPL");
    REQUIRE(((G.nodes_[1])->ticker_) == "A");
    REQUIRE(((G.nodes_[2])->ticker_) == "B");
    REQUIRE(((G.nodes_[3])->ticker_) == "MRNA");
}

TEST_CASE("Load Edges", "[weight=20][valgrind]") {
    Graph G;
    G.LoadNodes("tests/test_data/test_nodes.txt");
    G.LoadEdges("tests/test_data/test_edges.txt");
    REQUIRE(((G.nodes_[0])->edges_.front()->sr_coeff_) == 0.9);
    REQUIRE(((G.nodes_[0])->edges_.front()->node_2_->ticker_) == "AAPL");
    REQUIRE(((G.nodes_[0])->edges_.front()->node_1_->ticker_) == "MRNA");
}

TEST_CASE("BFS standard example", "[weight=10][valgrind]") {
    Graph G;
    G.LoadNodes("tests/test_data/test_nodes.txt");
    G.LoadEdges("tests/test_data/test_edges.txt");
    BFS bfs;
    std::vector<std::string> test = bfs.traverse(G.nodes_[0]);
    std::vector<std::string> compare = {"AAPL", "MRNA", "A", "B"};
    REQUIRE(test == compare);
}

TEST_CASE("BFS non-connected", "[weight=10][valgrind]") {
    Graph G;
    G.LoadNodes("tests/test_data/test_nodes.txt");
    G.LoadEdges("tests/test_data/test_edges.txt");
    BFS bfs;
    std::vector<std::string> test = bfs.traverse(G.nodes_[4]);
    std::vector<std::string> compare = {"TSLA"};
    REQUIRE(test == compare);
}

TEST_CASE("Load Edges does not create certain edges below threshold", "[weight=20][valgrind]") {
    Graph G;
    G.LoadNodes("tests/test_data/test_nodes.txt");
    G.LoadEdges("tests/test_data/test_edges_under.txt");
    BFS bfs;
    std::vector<std::string> test = bfs.traverse(G.nodes_[0]);
    std::vector<std::string> compare = {"AAPL"};
    REQUIRE(test == compare);
}

TEST_CASE("Dijkstra single-edge example", "[weight=10][valgrind]") {
    Graph G;
    G.LoadNodes("tests/test_data/test_nodes.txt");
    G.LoadEdges("tests/test_data/test_edges.txt");
    Dijkstra d;
    Node* source = G.nodes_[0];
    REQUIRE(source->ticker_ == "AAPL");
    d.ComputeDistances(G, source);
    REQUIRE(d.GetDist( G.nodes_[1]) == Approx(1.176).margin(.01));

    std::vector<std::string> actual; 
    actual = d.NodesPath(G.nodes_[1]);
    std::vector<std::string> expected = {"AAPL", "A"};

    REQUIRE(expected == actual);
}



TEST_CASE("Dijkstra multi-edge example", "[weight=10][valgrind]") {
    Graph G;
    G.LoadNodes("tests/test_data/test_nodes.txt");
    G.LoadEdges("tests/test_data/test_edges.txt");
    Dijkstra d;
    Node* source = G.nodes_[0];
    REQUIRE(source->ticker_ == "AAPL");
    d.ComputeDistances(G, source);
    REQUIRE(d.GetDist( G.nodes_[2]) == Approx(2.42).margin(.01));


    std::vector<std::string> actual; 
    actual = d.NodesPath(G.nodes_[2]);
    std::vector<std::string> expected = {"AAPL", "A", "B"};

    REQUIRE(expected == actual);
}

TEST_CASE("Dijkstra no path example", "[weight=10][valgrind]") {
    Graph G;
    G.LoadNodes("tests/test_data/test_nodes.txt");
    G.LoadEdges("tests/test_data/test_edges.txt");
    Dijkstra d;
    Node* source = G.nodes_[0];
    REQUIRE(source->ticker_ == "AAPL");
    d.ComputeDistances(G, source);
    REQUIRE(d.GetDist( G.nodes_[4]) == Approx(-1).margin(.01));


    REQUIRE(d.NodesPath(G.nodes_[4]).size() == 0);
}

TEST_CASE("CC", "[weight=10][valgrind]") {
    Graph G;
    G.LoadNodes("tests/test_data/test_nodes.txt");
    G.LoadEdges("tests/test_data/test_edges.txt");
    CC c(G);
    Node* source = G.nodes_[0];
    REQUIRE(source->ticker_ == "AAPL");
    std::vector<std::vector<std::string>> test;
    test = c.connectTheComponents();


    REQUIRE(true);
}