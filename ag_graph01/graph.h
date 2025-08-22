#include<stdio.h>
#include<stdlib.h>

#define NODEMAX 10
#define UNVISITED -1
#define PROGRESS 0
#define ALLDONE 1

struct node{
    unsigned short value;
    struct node* next;
};
struct graph{
    struct node* adjs[NODEMAX];
    char visited[NODEMAX];
};

void graphinit(struct graph* G);
void visitinit(struct graph* G);
void printgraph(struct graph* G);
void insert(struct graph* G, unsigned short u, unsigned short v);
void dfs(struct graph* G, unsigned short s);
void bfs(struct graph* G, unsigned short s);
