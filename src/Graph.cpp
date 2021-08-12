//
// Created by tieu on 8/12/2021.
//

#include <iostream>
#include "Graph.hpp"

Graph::Graph(int numOfNode) : numberOfNode(numOfNode) {
    for (int i = 0; i < numberOfNode; i++) {
        graph.emplace_back(std::forward_list<std::pair<Node, int>>());
        graph[i].emplace_front(std::pair(Node(i), 0));
    }
}

void Graph::addEdge(Node node1, Node node2, int weight) {
    int data1 = node1.getData();
    int data2 = node2.getData();

    graph[data1].emplace_after(graph[data1].begin(), std::pair(node2, weight));
    graph[data2].emplace_after(graph[data2].begin(), std::pair(node1, weight));

}

void Graph::print() {
    std::cout << "print graph" << std::endl;
    std::forward_list<std::pair<Node, int>>::iterator iterator;
    for (int i = 0; i < numberOfNode; i++) {
        for (iterator = graph[i].begin(); iterator != graph[i].end(); iterator++) {
            std::cout << iterator->first.getData() << "-" << iterator->second << " ";
        }
        std::cout << std::endl;
    }

}
