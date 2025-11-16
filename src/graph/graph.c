#include "graph/graph.h"
#include <stdio.h>
#include <stdlib.h>

struct Graph* buildGraphFromMatrix(int **matrix, int nodesCount) {
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->nodesCount = nodesCount;
    graph->rowSizes = calloc(nodesCount, sizeof(int));
    for (int i = 0; i < nodesCount; i++) {
        for (int j = 0; j < nodesCount; j++) {
            if (matrix[i][j] != 0) {
                graph->rowSizes[i]++;
            }
        }
    }
    graph->adjacencyVector = malloc(nodesCount * sizeof(int*));
    int current = 0;
    for (int i = 0; i < nodesCount; i++) {
        graph->adjacencyVector[i] = malloc(graph->rowSizes[i] * sizeof(int));
        current = 0;
        for (int j = 0; j < nodesCount; j++) {
            if (matrix[i][j] != 0) {
                graph->adjacencyVector[i][current++] = j;
            }
        }
    }
    return graph;
}

void printGraph(struct Graph* graph) {
    printf("Graph: {\n");
    int rowSize;
    for (int i = 0; i < graph->nodesCount; i++) {
        printf("\t%d: [", i);
        rowSize = graph->rowSizes[i];
        for (int j = 0; j < rowSize; j++) {
            printf("%d", graph->adjacencyVector[i][j]);
            if (j != rowSize - 1) printf(", ");
        }
        printf("]\n");
    }
    printf("}\n");
}

void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->nodesCount; i++) {
        free(graph->adjacencyVector[i]);
    }
    free(graph->adjacencyVector);
    free(graph->rowSizes);
    free(graph);
}


