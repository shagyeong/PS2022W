#include<stdio.h>
#include<stdlib.h>
#include "graph.h"

int main(void){
    struct graph* G = (struct graph*)malloc(sizeof(struct graph));
    graphinit(G);
    insert(G, 1, 2);
    insert(G, 2, 3);
    insert(G, 3, 4);
    insert(G, 2, 4);
    insert(G, 1, 5);
    insert(G, 3, 6);
    insert(G, 3, 7);
    insert(G, 5, 8);
    insert(G, 5, 9);
    printf("printgraph\n"); printgraph(G); printf("\n");
    printf("dfs\n"); dfs(G, 1); printf("\n\n");
    printf("bfs\n"); visitinit(G); bfs(G, 1);
}
