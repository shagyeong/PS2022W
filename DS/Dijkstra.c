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
void Graph(struct graph* G);
void visitinit(struct graph* G);
void dijkstra(struct graph* G, short s);

void insert(struct graph* G, short u, short v, short w);
void distanceinit(struct graph* G);
void printgraph(struct graph* G);

int main(void){
    struct graph* G = (struct graph*)malloc(sizeof(struct graph));
    Graph(G);
    //insert(G, 0, 1, 1);
    //insert(G, 0, 4, 25);
    //insert(G, 1, 2, 1);
    //insert(G, 1, 4, 22);
    //insert(G, 2, 3, 4);
    //insert(G, 3, 4, 20);

    insert(G, 1, 2, 4);
    insert(G, 1, 3, 2);
    insert(G, 1, 4, 7);
    insert(G, 2, 1, 1);
    insert(G, 2, 3, 5);
    insert(G, 3, 1, 2);
    insert(G, 3, 4, 4); 
    insert(G, 4, 2, 3);
    
    printgraph(G);

    dijkstra(G, 1);

    for(short i = 0; i < NODEMAX; i++){
        printf("%hd distance: %hd\n", i, G->distance[i]);
    }
}
void Graph(struct graph* G){
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
void distanceinit(struct graph* G){
    for(short i = 0; i < NODEMAX; i++){G->distance[i] = (short)INF;}   
}
void visitinit(struct graph* G){
    for(short i =0; i < NODEMAX; i++){G->visited[i] = NOTSURE;}   
}
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
