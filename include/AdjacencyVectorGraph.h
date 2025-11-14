#ifndef ADJACENCY_VECTOR_GRAPH_H
#define ADJACENCY_VECTOR_GRAPH_H

#include "AbstractGraph.h"
#include "VectorRange.h"

class AdjacencyVectorGraph : public AbstractGraph {
private:
    int **_adjacencyVector;
    int _nodesCount = 0;
    int *_rowSizes;
public:
    explicit AdjacencyVectorGraph(const std::vector<std::vector<int>> &adjMatrix);

    int getNodesCount() override { return _nodesCount; }

    RangeInterface *getNeighbours(int index) override;

    std::string toString() override;

    ~AdjacencyVectorGraph() override;
};
#endif
