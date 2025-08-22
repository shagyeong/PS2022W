#include "graph.h"

void insert(struct graph* G, short u, short v, short w){
    struct node* buf = (struct node*)malloc(sizeof(struct node));
    struct node* U = (struct node*)malloc(sizeof(struct node));
    struct node* V = (struct node*)malloc(sizeof(struct node));
    U->value = u; U->weight = w; U->next = NULL;
    V->value = v; V->weight = w; V->next = NULL;
    
    //가중치 오름차순을 유지하며 인접리스트에 삽입
    buf = G->adjs[u];
    while((buf->next != NULL) && (w > buf->next->weight)){buf = buf->next;}
    V->next = buf->next; buf->next = V;
    //무향 그래프에서 활성화
    //buf = G->adjs[v];
    //while((buf->next != NULL) && (w > buf->next->weight)){buf = buf->next;}
    //U->next = buf->next; buf->next = U;
}
