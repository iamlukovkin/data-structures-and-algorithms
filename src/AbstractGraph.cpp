#include "../include/AbstractGraph.h"

void AbstractGraph::search(
        int index,
        const std::function<void(int, bool *, const std::function<void(int)> &)> &searchFunc,
        const std::function<void(int)> &action
) {
    int nodesCount = getNodesCount();
    bool marks[nodesCount];
    for (int i = 0; i < nodesCount; i++) marks[i] = true;
    searchFunc(index, marks, action);
}

void AbstractGraph::depthFirstSearch(int index, const std::function<void(int)> &action) {
    std::function searchFunc = [this](int i, bool marks[], const std::function<void(int)> &action) {
        this->depthFirstSearchWithCheck(i, marks, action);
    };
    search(index, searchFunc, action);
}

void AbstractGraph::depthFirstSearch(int index) {
    std::function action = [](int i) { std::cout << i << " "; };
    depthFirstSearch(index, action);
    std::cout << "\n";
}

void AbstractGraph::depthFirstSearchWithCheck(int index, bool *marks, const std::function<void(int)> &action) {
    int j;
    marks[index] = false;
    action(index);
    auto range = getNeighbours(index);
    for (auto iter = range->begin(); iter != range->end(); ++iter) {
        j = *iter;
        if (marks[j])
            depthFirstSearchWithCheck(j, marks, action);
    }
}

void AbstractGraph::breadthFirstSearch(int index) {
    std::function action = [](int i) { std::cout << i << " "; };
    breadthFirstSearch(index, action);
    std::cout << "\n";
}

void AbstractGraph::breadthFirstSearch(int index, const std::function<void(int)> &action) {
    int nodesCount = getNodesCount();
    bool marks[nodesCount];
    for (int i = 0; i < nodesCount; i++) marks[i] = true;
    if (marks[index])
        breadthFirstSearchWithCheck(index, marks, action);
}

void AbstractGraph::breadthFirstSearchWithCheck(int index, bool *marks, const std::function<void(int)> &action) {
    std::queue<int> q;
    int j, k;
    marks[index] = false;
    q.push(index);
    while (!q.empty()) {
        j = q.front();
        q.pop();
        action(j);
        auto range = getNeighbours(j);
        for (auto iter = range->begin(); iter != range->end(); ++iter) {
            k = *iter;
            if (marks[k]) {
                marks[k] = false;
                q.push(k);
            }
        }
    }
}

std::vector<int> AbstractGraph::getConnectedComponentsDFS(int index) {
    int nodesCount = getNodesCount();
    bool marks[nodesCount];
    std::vector<int> components(nodesCount, 0);
    for (int i = 0; i < nodesCount; i++) marks[i] = true;
    depthFirstSearch(index, [&](int idx) { components[idx] = 1; });
    return components;
}

std::vector<int> AbstractGraph::getConnectedComponentsBFS(int index) {
    int nodesCount = getNodesCount();
    bool marks[nodesCount];
    std::vector<int> components(nodesCount, 0);
    for (int i = 0; i < nodesCount; i++) marks[i] = true;
    breadthFirstSearch(index, [&](int idx) { components[idx] = 1; });
    return components;
}

std::vector<int> AbstractGraph::topologicalSort() {
    int nodesCount = getNodesCount();
    std::vector<bool> marks(nodesCount, true);
    int num = nodesCount;
    std::vector<int> labels(nodesCount, -1);
    int j;
    auto dfsTopSort = [&](int idx, auto &&self) -> void {
        marks[idx] = false;
        auto range = getNeighbours(idx);
        for (auto iter = range->begin(); iter != range->end(); ++iter) {
            j = *iter;
            if (marks[j]) self(j, self);
        }
        labels[idx] = --num;
        std::cout << idx << " ";
    };

    for (int i = 0; i < nodesCount; i++) {
        if (marks[i]) dfsTopSort(i, dfsTopSort);
    }
    return labels;
}

bool AbstractGraph::isContoursExists() {
    int nodesCount = getNodesCount();
    std::vector<bool> marks(nodesCount, true);
    std::vector<int> labels(nodesCount, 0); // 0 = не завершена, >0 = завершена
    bool hasCycle = false;
    int num = nodesCount;
    int j;
    auto dfsTopSort = [&](int idx, auto &&self) -> void {
        marks[idx] = false;

        auto range = getNeighbours(idx);
        for (auto iter = range->begin(); iter != range->end(); ++iter) {
            j = *iter;
            if (marks[j]) {
                self(j, self);
            } else if (labels[j] == 0) {
                std::cout << std::format("contour between {} and {}\n", idx, j);
                throw std::exception();
            }
        }
        labels[idx] = num--;
    };

    for (int i = 0; i < nodesCount; i++) {
        if (marks[i]) dfsTopSort(i, dfsTopSort);
    }

    return hasCycle;
}

void AbstractGraph::dfsFull(int index) {
    std::function action = [](int i) { std::cout << i << " "; };
    int nodesCount = getNodesCount();
    bool marks[nodesCount];
    for (int i = 0; i < nodesCount; i++) marks[i] = true;
    for (int i = 0; i < nodesCount; i++) {
        if (marks[index])
            depthFirstSearchWithCheck(index, marks, action);
    }
}

void AbstractGraph::bfsFull(int index) {
    std::function action = [](int i) { std::cout << i << " "; };
    int nodesCount = getNodesCount();
    bool marks[nodesCount];
    for (int i = 0; i < nodesCount; i++) marks[i] = true;
    for (int i = 0; i < nodesCount; i++) {
        if (marks[index])
            breadthFirstSearchWithCheck(index, marks, action);
    }
}
