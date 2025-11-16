#ifndef GRAPH_H
#define GRAPH_H

struct Graph {
  int **adjacencyVector;
  int *rowSizes;
  int nodesCount;
};

struct Graph* buildGraphFromMatrix(int **matrix, int nodesCount);
void printGraph(struct Graph* graph);
void freeGraph(struct Graph* graph);

#endif
