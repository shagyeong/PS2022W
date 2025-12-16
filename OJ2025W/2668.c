//2668: 숫자 고르기(그래프 이론, 그래프 탐색, 깊이 우선 탐색)
#include<stdio.h>
#include<stdlib.h>

#define NODEMAX 101
#define UNVISITED -1
#define PROGRESS 0
#define ALLDONE 1

struct node{
    unsigned short value;
    struct node* next;
};
struct graph{
    char cycle[NODEMAX];
    char visited[NODEMAX];
    struct node* adjs[NODEMAX];
};
void Graph(struct graph* G, unsigned short n);
void insert(struct graph* G, unsigned short u, unsigned short v);
void VISITINIT(struct graph* G, unsigned short n){for(unsigned short i = 0; i < n; i++){G->visited[i] = UNVISITED;}}
unsigned short DFS(struct graph* G, unsigned short s, unsigned short t);

int main(void){
    unsigned short ans;
    unsigned short count = 0;
    unsigned short n; scanf("%hd", &n);
    unsigned short u;

    //그래프 세팅
    struct graph* G = (struct graph*)malloc(sizeof(struct graph));
    Graph(G, n);
    
    for(unsigned short i = 1; i <= n; i++){
        scanf("%hd", &u);
        insert(G, i, u);
    }
    for(unsigned short i = 1; i<= n; i++){
        DFS(G, i, i); VISITINIT(G, n);
    }
    for(unsigned short i = 1; i <= n; i++){
        count = (G->cycle[i] == 1)?(count + 1):count;
    }
    printf("%hd\n", count);
    for(unsigned short i = 1; i <= n; i++){
        ans = G->cycle[i];
        if(ans == 1){
            printf("%hd\n", i);
        }
    }
}
void Graph(struct graph* G, unsigned short n){
    for(unsigned short i = 0; i <= n; i++){
        //노드 세팅  
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->value = i;
        newnode->next = NULL;
        G->adjs[i] = newnode;
        G->visited[i] = UNVISITED;
        G->cycle[i] = 0;
    }
}
void insert(struct graph* G, unsigned short u, unsigned short v){
    //u points to v
    struct node* V = (struct node*)malloc(sizeof(struct node));
    V->value = v; V->next = NULL;
    
    struct node* buf = (struct node*)malloc(sizeof(struct node));
    buf = G->adjs[u];
    while((buf->next != NULL) && (v > buf->next->value)){buf = buf->next;}
    V->next = buf->next;
    buf->next = V;
}
//s: start(시작 노드), t:target(시작 노드의 값)
unsigned short DFS(struct graph* G, unsigned short s, unsigned short t){
    //printf("%hd ", G->adjs[s]->value);
    unsigned short i;
    struct node* buf = (struct node*)malloc(sizeof(struct node));
    G->visited[s] = PROGRESS;
    buf = G->adjs[s];
    while((buf = buf->next) != NULL){
        i = buf->value;
        if(i == t){
            G->cycle[i] = 1;
            return 1;
        }
        if(G->visited[i] == UNVISITED){
            if(DFS(G, i, t) == 1){
                G->cycle[i] = 1;
                return 1;
            }
        }
    }
    G->visited[s] == ALLDONE;
    return 0;
}
