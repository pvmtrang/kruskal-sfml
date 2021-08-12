//
// Created by tieu on 8/12/2021.
//

#include <iostream>
#include <algorithm>
#include "Graph.hpp"

Graph::Graph(int numOfNode) : numberOfNode(numOfNode) {
}

void Graph::addEdge(Edge otherEdge) {
    edge.emplace_back(otherEdge);
}

void Graph::addEdge(Node node1, Node node2, int weight) {
    //check xem da noi chua??
    edge.emplace_back(Edge(std::pair(node1, node2), weight));
}

void Graph::print() {

    for (int i = 0; i < edge.size(); i++) {
        std::cout << edge[i].getNode().first.getData() << "-" << edge[i].getNode().second.getData()
                    << ": " << edge[i].getWeight();
        std::cout << std::endl;
    }
}

const std::vector<Edge> &Graph::getEdge() const {
    return edge;
}

int Graph::getNumberOfNode() const {
    return numberOfNode;
}


