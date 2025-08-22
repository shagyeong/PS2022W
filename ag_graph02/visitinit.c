#include "graph.h"

void visitinit(struct graph* G){
    for(short i =0; i < NODEMAX; i++){G->visited[i] = NOTSURE;}   
}