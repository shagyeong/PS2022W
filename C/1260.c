//1260: DFS와 BFS(그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색)
#include<stdio.h>
#include<stdlib.h>

#define NODEMAX 1001
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
void Graph(struct graph* G, unsigned short n);
void insert(struct graph* G, unsigned short u, unsigned short v);
void VISITINIT(struct graph* G, unsigned short n){for(unsigned short i = 0; i <= n; i++){G->visited[i] = UNVISITED;}}
void DFS(struct graph* G, unsigned short s);    //s(start): 시작 노드
void BFS(struct graph* G, unsigned short s);

int main(void){
    //그래프 세팅
    unsigned short n, m, v; scanf("%hd %hd %hd", &n, &m, &v);
    unsigned short u, w;
    struct graph* G = (struct graph*)malloc(sizeof(struct graph));
    Graph(G, n);
    for(int i = 0; i < m; i++){
        scanf("%hd %hd", &u, &w);
        insert(G, u, w);
    }
    //정답 출력
    DFS(G, v);printf("\n");VISITINIT(G, n);
    BFS(G, v);printf("\n");
}
void Graph(struct graph* G, unsigned short n){
    for(unsigned short i = 0; i <= n; i++){
        //노드 세팅  
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->value = i;
        newnode->next = NULL;
        G->adjs[i] = newnode;
        //DFS 방문 배열 초기화
        G->visited[i] = UNVISITED;
    }
}
void insert(struct graph* G, unsigned short u, unsigned short v){
    struct node* U = (struct node*)malloc(sizeof(struct node));
    struct node* V = (struct node*)malloc(sizeof(struct node));
    U->value = u; U->next = NULL;
    V->value = v; V->next = NULL;
    
    struct node* buf = (struct node*)malloc(sizeof(struct node));
    buf = G->adjs[u];
    while((buf->next != NULL) && (v > buf->next->value)){buf = buf->next;}
    V->next = buf->next;
    buf->next = V;
    buf = G->adjs[v];
    while((buf->next != NULL) && (u > buf->next->value)){buf = buf->next;}
    U->next = buf->next;
    buf->next = U;
}
void DFS(struct graph* G, unsigned short s){
    printf("%hd ", G->adjs[s]->value);
    unsigned short i;
    struct node* buf = (struct node*)malloc(sizeof(struct node));
    G->visited[s] = PROGRESS;
    buf = G->adjs[s];
    while((buf = buf->next) != NULL){
        i = buf->value;
        if(G->visited[i] == UNVISITED){
            DFS(G, i);
        }
    }
    G->visited[s] == ALLDONE;
}
void BFS(struct graph* G, unsigned short s){
    //노드 버퍼
    struct node* buf = (struct node*)malloc(sizeof(struct node));
    buf = G->adjs[s];
    //BFS 노드 배열 L
    struct node* L[NODEMAX];
    struct node* R[NODEMAX];
    L[0] = buf; L[1] = NULL;
    R[0] = NULL;

    unsigned short d;   //깊이
    unsigned short i = 0;   //L 인덱스 제어
    unsigned short j = 0;   //L + 1 초기화 인덱스
    unsigned short v;   //value 버퍼

    for(d = 0; d < NODEMAX; d++){
        if(d%2 == 0){
            while(buf != NULL){
                while(buf != NULL){
                    v = buf->value;
                    if(G->visited[v] == UNVISITED){
                        printf("%hd ", v);
                        G->visited[v] = ALLDONE;
                        R[j++] = G->adjs[v];   //L_i+1
                    }
                    buf = buf->next;    //adjs 이동
                }
                buf = L[++i];           //탐색 대상 노드 이동
            }
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
                        L[j++] = G->adjs[v];   //L_i+1
                    }
                    buf = buf->next;    //adjs 이동
                }
                buf = R[++i];           //탐색 대상 노드 이동
            }
            L[j] = NULL;
            buf = L[0]; if(buf == NULL){break;}
            i = 0; j = 0;
        }
    }
}
