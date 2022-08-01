#include "../include/Edge.h"


Edge::Edge(Node* node_1, Node* node_2, double sr_coeff) {
    node_1_ = node_1;
    node_2_ = node_2;
    sr_coeff_ = sr_coeff;
}