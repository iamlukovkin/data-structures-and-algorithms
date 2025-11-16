#include <stdio.h>
#include <stdlib.h>

#include "graph/graph.h"

int main() {
    int nodesCount = 4;
    int matrix[4][4] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };
    int **adjMatrix = malloc(nodesCount * sizeof(int*));
    for (int i = 0; i < nodesCount; i++) {
        adjMatrix[i] = matrix[i];
    }
    struct Graph* graph = buildGraphFromMatrix(adjMatrix, nodesCount);
    printGraph(graph);
    freeGraph(graph);
    free(adjMatrix);
    return 0;
}

