#ifndef ADJACENCY_LIST_GRAPH_H
#define ADJACENCY_LIST_GRAPH_H

#include "AbstractGraph.h"
#include "Node.h"
#include "ListRange.h"

class AdjacencyListGraph : public AbstractGraph {
private:
    std::vector<Node<int> *> _head;
    int _size;
public:
    explicit AdjacencyListGraph(std::vector<std::vector<int>> adjMatrix);

    int getNodesCount() override { return  _size; }

    std::string toString() override;

    RangeInterface* getNeighbours(int index) override;

//    ~AdjacencyListGraph() override;
};

#endif