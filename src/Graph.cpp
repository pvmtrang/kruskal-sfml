//
// Created by tieu on 8/12/2021.
//

#include <iostream>
#include <algorithm>
#include "Graph.hpp"
#include <fstream>

Graph::Graph(int numOfNode) : numberOfNode(numOfNode) {
}

void Graph::addEdge(Edge otherEdge) {
    edge.emplace_back(otherEdge);
    std::cout << "edge added to graph" << std::endl;
}

void Graph::addEdge(Node node1, Node node2, int weight) {
    //check xem da noi chua??
    edge.emplace_back(Edge(std::pair(node1, node2), weight));
    std::cout << "edge created from " << node1.getData() << "-" << node2.getData() << ": " << weight << std::endl;
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

void Graph::readGraphFromFile(std::string filePath) {



}

void Graph::draw(sf::RenderTarget &target, sf::RenderStates state) const {
    for (int i = 0; i < edge.size(); i++) {
        target.draw(edge[i]);
    }

}


