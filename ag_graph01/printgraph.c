#include "graph.h"

void printgraph(struct graph* G){
    struct node* buf = (struct node*)malloc(sizeof(struct node));
    for(unsigned short i = 0; i < NODEMAX; i++){
        buf = G->adjs[i];
        printf("node %hd: ", i);
        while(buf->next != NULL){
            buf = buf->next;
            printf("%hd ", buf->value);
        }printf("\n");
    }
}
