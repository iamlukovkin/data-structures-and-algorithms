#ifndef ABSTRACT_GRAPH_H
#define ABSTRACT_GRAPH_H

#include <iostream>
#include <string>
#include "RangeInterface.h"

class AbstractGraph {
private:
    void search(int index, const std::function<void(int, bool *, const std::function<void(int)> &)> &traversalFunc,
                const std::function<void(int)> &action);

    void depthFirstSearchWithCheck(int index, bool *marks, const std::function<void(int)> &action);

    void breadthFirstSearchWithCheck(int index, bool *marks, const std::function<void(int)> &action);

public:
    explicit AbstractGraph([[maybe_unused]] const std::vector<std::vector<int>> &adjMatrix) {}

    void depthFirstSearch(int index);

    void dfsFull(int index);

    void bfsFull(int index);

    void depthFirstSearch(int index, const std::function<void(int)> &action);

    void breadthFirstSearch(int index);

    void breadthFirstSearch(int index, const std::function<void(int)> &action);

    std::vector<int> getConnectedComponentsDFS(int index);

    std::vector<int> getConnectedComponentsBFS(int index);

    std::vector<int> topologicalSort();

    bool isContoursExists();

    virtual int getNodesCount() = 0;

    virtual std::string toString() = 0;

    virtual RangeInterface *getNeighbours(int index) = 0;

//    virtual ~AbstractGraph() = default;
};

#endif
