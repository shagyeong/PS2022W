#include "graph.h"

void graphinit(struct graph* G){
    for(unsigned short i = 0; i < NODEMAX; i++){
        //노드 세팅
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->value = i;
        newnode->next = NULL;
        G->adjs[i] = newnode;
        //탐색 마크 배열 초기화
        G->visited[i] = UNVISITED;
    }
}
