#include "graph.h"

void graphinit(struct graph* G){
    for(short i = 0; i < NODEMAX; i++){
        //노드 세팅
        struct node* newnode =(struct node*)malloc(sizeof(struct node));
        newnode->value = i;
        newnode->weight = 0;
        newnode->next = NULL;
        G->adjs[i] = newnode;
        //최단 경로용 배열 초기화
        G->distance[i] = (short)INF;
        G->visited[i] = NOTSURE;
    }
}
