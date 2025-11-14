#include "../include/AdjacencyListGraph.h"

AdjacencyListGraph::AdjacencyListGraph(std::vector<std::vector<int>> adjMatrix) : AbstractGraph(adjMatrix) {
    _size = static_cast<int>(adjMatrix.size());
    _head.resize(_size, nullptr);
    for (int i = 0; i < _size; i++) {
        Node<int> *currentHead = nullptr;
        Node<int> *currentTail = nullptr;
        for (int j = 0; j < _size; j++) {
            if (adjMatrix[i][j] != 0) {
                if (!currentHead) {
                    currentHead = new Node<int>(j);
                } else {
                    currentTail = currentTail == nullptr ? currentHead : currentTail;
                    currentTail->next = new Node<int>(j);
                    currentTail = currentTail->next;
                }
            }
        }
        _head[i] = currentHead;
    }
}

RangeInterface *AdjacencyListGraph::getNeighbours(int index) {
    return new ListRange(_head[index]);
}

std::string AdjacencyListGraph::toString() {
    std::string result = "ListGraph: (\n";
    for (int curIdx = 0; curIdx < _size; curIdx++) {
        result += std::format("\t{}->", curIdx);
        auto *cur = _head[curIdx];
        while (cur) {
            result += std::format("{}->", cur->data);
            cur = cur->next;
        }
        result += "nullptr";
        result += "\n";
    }
    result += ")\n";
    return result;
}

AdjacencyListGraph::~AdjacencyListGraph() {
    for (auto ptr: _head) delete ptr;
}
