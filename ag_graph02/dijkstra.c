#include "graph.h"

void dijkstra(struct graph* G, short s){
    short ibuf;
    short wbuf;
    G->distance[s] = 0;
    struct node* buf = (struct node*)malloc(sizeof(struct node));
    
    //while NOTSURE nodes exist
    //d[u]가 최소인 u를 선택
    //v for d[u]'s adjs
    //d[v] <- min(dv], d[u] + w(u, v))
    for(short i = 0; i < NODEMAX; i++){
        ibuf = 0;
        wbuf = 32767;
        for(short j = 0; j < NODEMAX; j++){
            if(G->distance[j] < wbuf && G->visited[j] == NOTSURE){
                wbuf = G->distance[j];
                ibuf = j;
            }
        }
        buf = G->adjs[ibuf]->next;
        while(buf != NULL){
            if((wbuf + buf->weight > 0) && (wbuf + buf->weight < G->distance[buf->value])){
                G->distance[buf->value] = wbuf + buf->weight;
            }
            buf = buf->next;
        }
        G->visited[ibuf] = ALLDONE;
    }
}
