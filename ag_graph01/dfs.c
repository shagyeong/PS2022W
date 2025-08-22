#include "graph.h"

void dfs(struct graph* G, unsigned short s){
    unsigned short i;
    struct node* buf = (struct node*)malloc(sizeof(struct node));
    printf("%hd ", s);
    buf = G->adjs[s]; G->visited[s] = PROGRESS;
    while((buf = buf->next) != NULL){
        i = buf->value;
        if(G->visited[i] == UNVISITED){
            dfs(G, i);
        }
    }
    G->visited[s] = ALLDONE;
}
