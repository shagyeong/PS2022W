#include "graph.h"

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