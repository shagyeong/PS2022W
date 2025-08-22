#include "graph.h"

void insert(struct graph* G, unsigned short u, unsigned short v){
    struct node* buf = (struct node*)malloc(sizeof(struct node));
    struct node* U = (struct node*)malloc(sizeof(struct node));
    struct node* V = (struct node*)malloc(sizeof(struct node));
    U->value = u; U->next = NULL;
    V->value = v; V->next = NULL;
    //U 인접리스트에 V 삽입
    buf = G->adjs[u];
    while(buf->next != NULL && v > buf->next->value){buf = buf->next;}
    V->next = buf->next; buf->next = V;
    //V 인접리스트에 U 삽입
    buf = G->adjs[v];
    while(buf->next != NULL && u > buf->next->value){buf = buf->next;}
    U->next = buf->next; buf->next = U;
}
