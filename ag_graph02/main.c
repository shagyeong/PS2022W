#include<stdio.h>
#include<stdlib.h>
#include "graph.h"

int main(void){
    struct graph* G = (struct graph*)malloc(sizeof(struct graph));
    graphinit(G);
    //insert(G, 0, 1, 1);
    //insert(G, 0, 4, 25);
    //insert(G, 1, 2, 1);
    //insert(G, 1, 4, 22);
    //insert(G, 2, 3, 4);
    //insert(G, 3, 4, 20);

    insert(G, 1, 2, 4);
    insert(G, 1, 3, 2);
    insert(G, 1, 4, 7);
    insert(G, 2, 1, 1);
    insert(G, 2, 3, 5);
    insert(G, 3, 1, 2);
    insert(G, 3, 4, 4); 
    insert(G, 4, 2, 3);
    
    printgraph(G);

    dijkstra(G, 1);

    for(short i = 0; i < NODEMAX; i++){
        printf("%hd distance: %hd\n", i, G->distance[i]);
    }
}
