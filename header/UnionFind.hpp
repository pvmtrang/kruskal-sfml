//
// Created by tieu on 7/29/2021.
//

#ifndef DSA_UNION_HPP
#define DSA_UNION_HPP

#include <vector>

class UnionFind {
private:
    int numberOfNode;
    std::vector<int> id;


    int findRoot(int node);

public:
    UnionFind(int numberOfNode = 0);
    void connect(int node1, int node2);
    bool isConnected(int node1, int node2);

    void printComponent();

};


#endif //DSA_UNION_HPP
