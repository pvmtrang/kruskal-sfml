//
// Created by tieu on 8/12/2021.
//

#include <algorithm>
#include <iostream>
#include "Kruskal.hpp"

Kruskal::Kruskal() {
    isGraphSet = false;
}

Kruskal::Kruskal(const Graph &graph) {
    setGraph(graph);
}

void Kruskal::setGraph(const Graph &graph) {
    std::cout << "kruskal graph is set" << std::endl;

    Kruskal::graph = graph;
    isGraphSet = true;
    edge = graph.getEdge();
    finalGraph = Graph(sf::Color::Red);
    unionFind = UnionFind(graph.getNumberOfNode());
    numberOfAddedEdge = 0;
}

/**
 * To find the minimum spanning tree if graph is set.
 */
void Kruskal::findMST() {
    //this if is for rendering
    if (isGraphSet) {
        //descending sort for easier pop
        std::sort(edge.begin(), edge.end(), std::greater<>());

        //number of edges in spanning tree = number of node - 1
        //if - while
        if (numberOfAddedEdge != graph.getNumberOfNode() - 1) {
            std::cout << "finding mst" << std::endl;
            //pick the smallest weighted edge
            Edge currentEdge = edge.back();
            edge.pop_back();

            //check cycle and add
            Node node1 = currentEdge.getNode().first;
            Node node2 = currentEdge.getNode().second;

            //if two nodes are in the same component -> pass, else -> add
            if (!unionFind.isConnected(node1.getData(), node2.getData())) {
                std::cout << node1.getData() << " " << node2.getData() << std::endl;
                finalGraph.addEdge(currentEdge);
                unionFind.connect(node1.getData(), node2.getData());

                numberOfAddedEdge += 1;
            }
        }
    }
}

void Kruskal::draw(sf::RenderTarget &target, sf::RenderStates state) const {
    if (isGraphSet) {
        target.draw(finalGraph);
    }
}




