//1119: 그래프(자료 구조, 그래프 이론, 그래프 탐색, 깊이 우선 탐색, 분리 집합)
#include<stdio.h>
#include<stdlib.h>

#define NODEMAX 50
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
void dfs(struct graph* G, unsigned short s, unsigned short* count);

int main(void){
    unsigned short i, j;
    char c;
    unsigned short ans = 0;
    unsigned short count = 0;
    unsigned short countbuf;    //dfs 후 방문 노드 개수 변화가 없는 경우 프리즈
    unsigned short n; scanf("%hd", &n); scanf("%c", &c);   //개행
    
    //그래프 세팅
    struct graph* G = (struct graph*)malloc(sizeof(struct graph));
    Graph(G, n);
    for(i = 0; i < n; i++){
        for(j = 0; j < i; j++){
            scanf("%c", &c);
            if(c == 'Y'){
                count++;
                insert(G, i, j);
            }
        }
        for(j = i; j < n; j++){
            scanf("%c", &c);
        }
        scanf("%c", &c);   //개행
    }
    if(n == 1){
        printf("0");
    }
    else if(count < n - 1){
        printf("-1");
    }
    else{
        count = 0;
        for(i = 0; i < n; i++){
            //간선이 없는 노드
            if(G->adjs[i]->next == NULL){
                printf("-1");goto escape;
            }
            //간선이 있는 경우 dfs
            countbuf = count;
            dfs(G, i, &count);
            if(count == n){
                break;
            }
            if(countbuf != count){
                ans++;
            }
        }
        printf("%hd", ans);
        escape:
    }
}
void Graph(struct graph* G, unsigned short n){
    for(unsigned short i = 0; i < n; i++){
        //노드 세팅
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->value = i;
        newnode->next = NULL;
        G->adjs[i] = newnode;
        //탐색 마크 배열 초기화
        G->visited[i] = UNVISITED;
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
void dfs(struct graph* G, unsigned short s, unsigned short* count){
    unsigned short i;
    struct node* buf = (struct node*)malloc(sizeof(struct node));
    buf = G->adjs[s];
    if(G->visited[s] == UNVISITED){
        G->visited[s] = PROGRESS;
    }
    while((buf = buf->next) != NULL){
        i = buf->value;
        if(G->visited[i] == UNVISITED){
            dfs(G, i, count);
        }
    }
    if(G->visited[s] != ALLDONE){
        G->visited[s] = ALLDONE;
        (*count)++;
    }
}
