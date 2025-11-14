#include <iostream>
#include "include/AdjacencyListGraph.h"
#include "include/AdjacencyVectorGraph.h"

void dfsTest() {
    std::cout << "--- DFS TEST ---\n";
    std::vector<std::vector<int>> matrix = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 0, 1},
            {1, 0, 0, 0, 1, 0},
            {0, 0, 0, 1, 0, 0},
            {1, 0, 0, 1, 0, 0},
            {0, 1, 0, 0, 0, 0}
    };
    auto *lGraph = new AdjacencyListGraph(matrix);
    auto *vGraph = new AdjacencyVectorGraph(matrix);
    std::cout << lGraph->toString();
    std::cout << vGraph->toString();
    for (int i = 0; i < lGraph->getNodesCount(); i++) {
        std::cout << std::format("{}: ListGraph: ", i);
        lGraph->dfsFull(i);
        std::cout << "VectorGraph: ";
        vGraph->dfsFull(i);
        std::cout << "\n";
    }
    delete lGraph;
    delete vGraph;
}

void bfsTest() {
    std::cout << "--- BFS TEST ---\n";
    std::vector<std::vector<int>> matrix = {
            {0, 1, 0, 0, 1, 1},
            {0, 0, 1, 0, 0, 1},
            {0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 0, 0},
            {0, 0, 1, 1, 1, 0}
    };
    auto *lGraph = new AdjacencyListGraph(matrix);
    auto *vGraph = new AdjacencyVectorGraph(matrix);
    std::cout << lGraph->toString();
    std::cout << vGraph->toString();
    for (int i = 0; i < lGraph->getNodesCount(); i++) {
        std::cout << std::format("{}: ListGraph: ", i);
        lGraph->bfsFull(i);
        std::cout << "VectorGraph: ";
        vGraph->bfsFull(i);
        std::cout << "\n";
    }
    delete lGraph;
    delete vGraph;
}

void connectedComponentsTest() {
    std::cout << "--- CONNECTED COMPONENTS TEST ---\n";
    std::vector<std::vector<int>> matrix = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 0, 1},
            {1, 0, 0, 0, 1, 0},
            {0, 0, 0, 1, 0, 0},
            {1, 0, 0, 1, 0, 0},
            {0, 1, 0, 0, 0, 0}
    };
    auto *lGraph = new AdjacencyListGraph(matrix);
    auto *vGraph = new AdjacencyVectorGraph(matrix);
    std::cout << lGraph->toString();
    std::cout << vGraph->toString();
    std::function arr_to_string = [&](const std::vector<int> &arr) {
        int size = (int) arr.size();
        std::string result = "[";
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] == 1) count++;
        }
        for (int i = 0; i < size; i++) {
            if (arr[i] == 1) {
                result += std::to_string(i);
                count--;
                if (count != 0) result += ", ";
            }
        }
        result += "]";
        return result;
    };
    for (int i = 0; i < lGraph->getNodesCount(); i++) {
        std::cout << std::format("{}: \n", i);
        std::vector<int> conCompLD = lGraph->getConnectedComponentsDFS(i);
        std::vector<int> conCompVD = vGraph->getConnectedComponentsDFS(i);
        std::vector<int> conCompLB = lGraph->getConnectedComponentsBFS(i);
        std::vector<int> conCompVB = vGraph->getConnectedComponentsBFS(i);
        std::cout << std::format(
                "\tList(DFS): {}\n"
                "\tVector(DFS): {}\n"
                "\tList(BFS): {}\n"
                "\tVector(BFS): {}\n",
                arr_to_string(conCompLD),
                arr_to_string(conCompVD),
                arr_to_string(conCompLB),
                arr_to_string(conCompVB)
        );
    }
    delete lGraph;
    delete vGraph;
}

void topologicalSortTest() {
    std::cout << "--- TOPOLOGICAL TEST ---\n";
    std::vector<std::vector<int>> matrix = {
            {0, 1, 0, 0, 0, 1},
            {0, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0},
            {1, 0, 0, 1, 0, 1},
            {0, 1, 1, 1, 0, 0}
    };
    auto *lGraph = new AdjacencyListGraph(matrix);
    auto *vGraph = new AdjacencyVectorGraph(matrix);
    std::cout << lGraph->toString();
    std::cout << vGraph->toString();
    std::function arr_to_string = [&](const std::vector<int> &arr) {
        int size = (int) arr.size();
        std::string result = "[";
        for (int i = 0; i < size; i++) {
            result += std::to_string(arr[i]);
            if (i != size - 1) result += ", ";
        }
        result += "]";
        return result;
    };
    std::cout << "topological sort(List): [";
    auto rl = lGraph->topologicalSort();
    std::cout << std::format("] Labels: {}\n", arr_to_string(rl));
    std::cout << "topological sort(Vector): [";
    auto rv = vGraph->topologicalSort();
    std::cout << std::format("] Labels: {}\n", arr_to_string(rv));
}

void contoursSearchTest() {
    std::cout << "--- TOPOLOGICAL TEST ---\n";
    std::vector<std::vector<int>> matrix = {
            {0, 1, 0, 0, 0, 1},
            {0, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0},
            {1, 0, 0, 1, 0, 0},
            {0, 1, 1, 1, 1, 0}
    };
    auto *lGraph = new AdjacencyListGraph(matrix);
    auto *vGraph = new AdjacencyVectorGraph(matrix);
    std::cout << lGraph->toString();
    std::cout << vGraph->toString();
    std::cout << "contours search(List): ";
    lGraph->isContoursExists();
    std::cout << "\ncontours search(Vector): ";
    vGraph->isContoursExists();
}

int main() {
    dfsTest();
    bfsTest();
    connectedComponentsTest();
    topologicalSortTest();
    contoursSearchTest();
}