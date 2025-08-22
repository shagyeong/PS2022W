#include "graph.h"

void visitinit(struct graph* G){
    for(unsigned short i = 0; i < NODEMAX; i++){
        G->visited[i] = UNVISITED;
    }
}
