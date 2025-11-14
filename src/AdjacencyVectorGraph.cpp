#include "../include/AdjacencyVectorGraph.h"

AdjacencyVectorGraph::AdjacencyVectorGraph(const std::vector<std::vector<int>> &adjMatrix) : AbstractGraph(adjMatrix) {
    _nodesCount = (int) adjMatrix.size();
    _adjacencyVector = new int *[_nodesCount];
    _rowSizes = new int[_nodesCount];
    int maxSize = 0;
    for (size_t row = 0; row < adjMatrix.size(); row++) {
        int curSize = 0;
        for (int col = 0; col < adjMatrix.size(); col++)
            if (adjMatrix[row][col] == 1) curSize++;
        if (curSize > maxSize) maxSize = curSize;
        _adjacencyVector[row] = new int[curSize];
        _rowSizes[row] = curSize;
        int adjColIdx = 0;
        for (int srcColIdx = 0; srcColIdx < adjMatrix.size(); srcColIdx++) {
            if (adjMatrix[row][srcColIdx] == 1) {
                _adjacencyVector[row][adjColIdx] = srcColIdx;
                adjColIdx++;
            }
        }
    }
}

RangeInterface *AdjacencyVectorGraph::getNeighbours(int index) {
    return new VectorRange(_adjacencyVector[index], _rowSizes[index]);
}

std::string AdjacencyVectorGraph::toString() {
    std::string result = "VectorGraph: (\n";
    for (int curIdx = 0; curIdx < _nodesCount; curIdx++) {
        result += std::format("\t{}: ", curIdx);
        int rowSize = _rowSizes[curIdx];
        result += "[";
        for (int i = 0; i < rowSize; i++) {
            result += std::format("{}", _adjacencyVector[curIdx][i]);
            result += (i == rowSize - 1) ? "" : ", ";
        }
//        auto *cur = _head[curIdx];
//        while (cur) {
//            result += std::format("{}", cur->data);
//            result += (cur->next == nullptr) ? "" : "->";
//            cur = cur->next;
//        }
        result += "];\n";
    }
    result += ")\n";
    return result;
}