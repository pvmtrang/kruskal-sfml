//
// Created by tieu on 8/12/2021.
//

#include <iostream>
#include <algorithm>
#include "Graph.hpp"
#include <algorithm>

//hinh nhu numofnode chang de lam gi??
Graph::Graph () {
    //cho tam 10 node truoc da
    for (int i = 0; i < 2; i++) {
        adjacencyList.emplace_back(std::vector<int>());
    }
    numberOfNode = 10;
}

void Graph::addEdge(const Edge& otherEdge) {
    expandList(otherEdge.getNode().first);
    expandList(otherEdge.getNode().second);
    if (!hasCreatedThisEdge(otherEdge.getNode().first, otherEdge.getNode().second)) {
        edge.emplace_back(otherEdge);
        adjacencyList[otherEdge.getNode().first.getData()].emplace_back(otherEdge.getNode().second.getData());
        adjacencyList[otherEdge.getNode().second.getData()].emplace_back(otherEdge.getNode().first.getData());
        std::cout << "edge added to graph" << std::endl;
    } else {
        std::cout << "this edge has been created before" << std::endl;
    }


}

void Graph::addEdge(const Node& node1, const Node& node2, int weight) {
    expandList(node1);
    expandList(node2);

    if (!hasCreatedThisEdge(node1, node2)) {
        //check xem da noi chua??
        edge.emplace_back(Edge(std::pair(node1, node2), weight));
        adjacencyList[node1.getData()].emplace_back(node2.getData());
        adjacencyList[node2.getData()].emplace_back(node1.getData());
        std::cout << "edge created from " << node1.getData() << "-" << node2.getData() << ": " << weight << std::endl;
    } else {
        std::cout << "this edge has been created before" << std::endl;
    }

}

bool Graph::hasCreatedThisEdge(const Node& node1, const Node& node2) {
    int data1 = node1.getData();
    int data2 = node2.getData();

    /*std::cout << "check adj list" << std::endl;

    std::cout << "adj list 1: ";
    for (int i = 0; i < adjacencyList[data1].size(); i++) {
        std::cout << adjacencyList[data1][i] << " ";
    }
    std::cout << std::endl;

    std::cout << "adj list 2: ";
    for (int i = 0; i < adjacencyList[data2].size(); i++) {
        std::cout << adjacencyList[data2][i] << " ";
    }
    std::cout << std::endl;*/

    //check twice just in case
    if (std::count(adjacencyList[data1].begin(), adjacencyList[data1].end(), data2)
        || std::count(adjacencyList[data2].begin(), adjacencyList[data2].end(), data1)) {
        return true;
    }
    return false;
}

void Graph::expandList(const Node& node) {
    std::cout << "comtemplating expading edge" << std::endl;
    /*int oldSize = adjacencyList.size();
    std::cout << "old size = " << oldSize << std::endl;
    if (node.getData() >= oldSize) {
        adjacencyList.resize(oldSize + 1, std::vector<int>{oldSize});
        std::cout << "list expanded" << std::endl;
        numberOfNode += 1;
    }*/
    //eg: adjlist size = 3.
    //add edge from node 5 to 3
    // 5 > size -> resize = 6 (0->5)
    //if add edge from 3 to 5
    // 3 == size -> size = 6 (0->3)
    if (node.getData() >= adjacencyList.size()) {
        adjacencyList.resize(node.getData() + 1, std::vector<int>());
        std::cout << "list expanded" << std::endl;
    }
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

void Graph::draw(sf::RenderTarget &target, sf::RenderStates state) const {
    for (int i = 0; i < edge.size(); i++) {
        target.draw(edge[i]);
    }

}






