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
void Graph(struct graph* G);
void visitinit(struct graph* G);
void printgraph(struct graph* G);
void insert(struct graph* G, unsigned short u, unsigned short v);
void dfs(struct graph* G, unsigned short s);
void bfs(struct graph* G, unsigned short s);

int main(void){
    struct graph* G = (struct graph*)malloc(sizeof(struct graph));
    Graph(G);
    insert(G, 1, 2);
    insert(G, 2, 3);
    insert(G, 3, 4);
    insert(G, 2, 4);
    insert(G, 1, 5);
    insert(G, 3, 6);
    insert(G, 3, 7);
    insert(G, 5, 8);
    insert(G, 5, 9);
    printgraph(G);
    dfs(G, 1);printf("\n");
    visitinit(G);
    bfs(G, 1);
}
void Graph(struct graph* G){
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
void visitinit(struct graph* G){
    for(unsigned short i = 0; i < NODEMAX; i++){
        G->visited[i] = UNVISITED;
    }
}
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
void dfs(struct graph* G, unsigned short s){
    unsigned short i;
    struct node* buf = (struct node*)malloc(sizeof(struct node));
    printf("%hd ", s);
    buf = G->adjs[s]; G->visited[s] = PROGRESS;
    while((buf = buf->next) != NULL){
        i = buf->value;
        if(G->visited[i] == UNVISITED){
            dfs(G, i);
        }
    }
    G->visited[s] = ALLDONE;
}
void bfs(struct graph* G, unsigned short s){
    //노드 버퍼
    struct node* buf = (struct node*)malloc(sizeof(struct node));
    //제어 변수
    unsigned short d = 0;   //depth: 깊이
    unsigned short i = 0;   //L_i 인덱스 제어
    unsigned short j = 0;   //L_i+1 초기화 제어
    unsigned short v;       //value 버퍼 
    //노드 배열
    struct node* L[NODEMAX];
    struct node* R[NODEMAX];
    L[0] = buf; L[1] = NULL;
    R[0] = NULL;
    //depth 0(시작 노드) 출력
    buf = G->adjs[s]; G->visited[s] = ALLDONE;
    printf("depth %hd: %hd\n", d, s);
    //depth 1부터 출력
    for(d = 1; d < NODEMAX; d++){
        printf("depth %hd: ", d);
        if(d%2 == 1){
            while(buf != NULL){
                while(buf != NULL){
                    v = buf->value;
                    if(G->visited[v] == UNVISITED){
                        printf("%hd ", v);
                        G->visited[v] = ALLDONE;
                        R[j++] = G->adjs[v];    //L_i+1 초기화
                    }
                    buf = buf->next;            //ajds 이동
                }
                buf = L[++i];                   //탐색 대상 노드 이동
            }
            printf("\n");
            R[j] = NULL;
            buf = R[0]; if(buf == NULL){break;}
            i = 0; j = 0;
        }
        else{
            while(buf != NULL){
                while(buf != NULL){
                    v = buf->value;
                    if(G->visited[v] == UNVISITED){
                        printf("%hd ", v);
                        G->visited[v] = ALLDONE;
                        L[j++] = G->adjs[v];
                    }
                    buf = buf->next;
                }
                buf = R[++i];
            }
            printf("\n");
            L[j] = NULL;
            buf = L[0]; if(buf == NULL){break;}
            i = 0; j = 0;
        }
    }
}
