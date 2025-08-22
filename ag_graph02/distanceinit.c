#include "graph.h"

void distanceinit(struct graph* G){
    for(short i = 0; i < NODEMAX; i++){G->distance[i] = (short)INF;}   
}
