#include "graph.h"

void printgraph(struct graph* G){
    struct node* buf = (struct node*)malloc(sizeof(struct node));
    for(short i = 0; i < NODEMAX; i++){
        buf = G->adjs[i];
        printf("node %hd's adjs: \n", buf->value);
        buf = buf->next;
        while(buf != NULL){
            printf("node %hd: weight %hd\n", buf->value, buf->weight);
            buf = buf->next;
        }printf("\n");
    }
}
