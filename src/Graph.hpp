//
// Created by tieu on 8/12/2021.
//

#ifndef MST_SFML_GRAPH_HPP
#define MST_SFML_GRAPH_HPP


#include <vector>
#include <forward_list>
#include <Node.hpp>

class Graph {
public:
    Graph(int numOfNode = 0);

    void addEdge(Node node1, Node node2, int weight);

    void print();

private:
    int numberOfNode;
    std::vector<std::forward_list<std::pair<Node, int>>> graph;



};


#endif //MST_SFML_GRAPH_HPP
