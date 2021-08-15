//
// Created by tieu on 8/12/2021.
//

#include <algorithm>
#include <iostream>
#include "Kruskal.hpp"

Kruskal::Kruskal() {
    isGraphSet = false;
}

Kruskal::Kruskal(const Graph &graph) : graph(graph) {
    edge = graph.getEdge();

    isGraphSet = true;

    finalGraph = Graph(sf::Color::Red);

    unionFind = UnionFind(graph.getNumberOfNode());

    numberOfAddedEdge = 0;
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

void Kruskal::findMST() {
    if (isGraphSet) {
        std::cout << "finding mst" << std::endl;
        //descending sort for easier pop
        std::sort(edge.begin(), edge.end(), std::greater<>());

        //so luong cac canh cua mst = numberofnode - 1
        if (numberOfAddedEdge != graph.getNumberOfNode() - 1) {
            //pick the smallest weighted edge
            Edge currentEdge = edge.back();
            edge.pop_back();

            //check cycle and add
            Node node1 = currentEdge.getNode().first;
            Node node2 = currentEdge.getNode().second;

            if (!unionFind.isConnected(node1.getData(), node2.getData())) {
                std::cout << node1.getData() << " " << node2.getData() << std::endl;
                finalGraph.addEdge(currentEdge);
                unionFind.connect(node1.getData(), node2.getData());

                numberOfAddedEdge += 1;
            }
        }
        std::cout << "print mst" << std::endl;
        finalGraph.print();
    }

}

void Kruskal::draw(sf::RenderTarget &target, sf::RenderStates state) const {
    if (isGraphSet) {
        target.draw(finalGraph);
        std::cout << "draw kruskal graph" << std::endl;
    }

}




