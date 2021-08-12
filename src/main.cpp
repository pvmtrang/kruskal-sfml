#include <iostream>
#include "Graph.hpp"

int main() {
    Graph graph(5);
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 5);
    graph.addEdge(1, 3, 6);
    graph.addEdge(2, 4, 10);

    graph.print();


    return 0;
}
