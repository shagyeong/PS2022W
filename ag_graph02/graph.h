#include<stdio.h>
#include<stdlib.h>

#define NODEMAX 10
#define INF 32767   //short 최대값
#define NOTSURE -1
#define ALLDONE 1

struct node{
    short value;
    short weight;
    struct node* next;
};
struct graph{
    struct node* adjs[NODEMAX];
    short distance[NODEMAX];
    char visited[NODEMAX];      //노드 마크
};
void graphinit(struct graph* G);
void visitinit(struct graph* G);
void dijkstra(struct graph* G, short s);
void insert(struct graph* G, short u, short v, short w);
void distanceinit(struct graph* G);
void printgraph(struct graph* G);
