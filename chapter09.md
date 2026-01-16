# 9장 기타 과제 유형
<!-- ## 9.1 재귀 -->
<!-- ## 9.2 백트래킹 -->



## 9.3 문자열 조작
<!-- ### 9.3.1 파싱 -->
<!-- ### 9.3.2 팰린드롬 -->
### 9.3.3 트라이
#### 트라이: 소문자 알파벳 환경
```C
#include<stdio.h>
#include<stdlib.h>

#define N 26 // 소문자 알파벳 환경

struct trie{
    struct node* r;
};
struct node{
    struct node* c[N];
    int          f; // flag: isend
};

void   init(struct trie* t);
void insert(struct trie* t,char* s); // trie, character array
int  search(struct trie* t,char* s);

int main(void){
    struct trie t;
    init(&t);
    char s[10]="abcdef";
    insert(&t,s);
    printf("%s: %d\n",s,    search(&t,s));
    printf("%s: %d\n","abc",search(&t,"abc"));
}

void   init(struct trie* t){
    int j;
    t->r=(struct node*)malloc(sizeof(struct node));
    t->r->f=0;
    for(j=0;j<N;j++){t->r->c[j]=NULL;}
}
void insert(struct trie* t,char* s){
    int j=0; // loop variable
    int i; // index
    struct node* d=t->r;
    for(j=0;s[j]!='\0';j++){
        i=s[j]-'a'; // 97~122 -> 0~25
        if(d->c[i]==NULL){
            d->c[i]=(struct node*)malloc(sizeof(struct node));
            d->c[i]->f=0; // is not end
            for(int x=0;x<N;x++){d->c[i]->c[x]=NULL;}
        }
        d=d->c[i];
    }
    d->f=1;
}
int  search(struct trie* t,char* s){
    int j; // loop variable
    int i; // index
    struct node* d=t->r;
    for(j=0;s[j]!='\0';j++){
        i=s[j]-'a'; // 97~122 -> 0~25
        if(d->c[i]==NULL){return 0;}
        d=d->c[i];
    }
    return d->f;
}
```
```
$ ./test
abcdef: 1
abc: 0
```
#### 접두사 탐색
```C
int  search(struct trie* t,char* s){
    int j; // loop variable
    int i; // index
    struct node* d=t->r;
    for(j=0;s[j]!='\0';j++){
        i=s[j]-'a'; // 97~122 -> 0~25
        if(d->c[i]==NULL){return 0;}
        d=d->c[i];
        if(d->f==1){return 1;}
    }
    return 1; // 루프 break 없음: 접두사
}
```
```
$ ./test
abcdef: 1
abc: 1
```
<!-- ### 9.3.4 접미사 -->


## 9.4 P-NP 문제
### 9.4.1 TSP
#### TSP
TSP: traveling salesman problem  
순회 세일즈맨(또는 외판원) 문제  
#### 부르트포스 TSP
```C
#include <stdio.h>

#define N 10 // 노드 최대 개수
#define INF 2147483647

struct graph{
    int n;          // 노드 개수
    int adjs[N][N]; // 인접행렬
    int vist[N];    // 방문 상태: 0(NO),1(YES)
    int m;          // 최소비용
};

void tsp(struct graph* g,int cur,int num,int acc);

int main(void){
    int j; // loop variable

    // 그래프 초기화
    struct graph g;
    g.n=4;
    g.m=INF;
    for(j=0;j<g.n;j++){g.vist[j]=0;}
    g.adjs[0][0]=0; g.adjs[0][1]=10; g.adjs[0][2]=15;g.adjs[0][3]=20;
    g.adjs[1][0]=5; g.adjs[1][1]=0;  g.adjs[1][2]=9; g.adjs[1][3]=10;
    g.adjs[2][0]=6; g.adjs[2][1]=13; g.adjs[2][2]=0; g.adjs[2][3]=12;
    g.adjs[3][0]=8; g.adjs[3][1]=8;  g.adjs[3][2]=9; g.adjs[3][3]=0;

    // TSP
    g.vist[0]=1;
    tsp(&g,0,1,0);
    
    // 결과 출력
    if(g.m==INF){printf("-1\n");}
    else        {printf("%d\n",g.m);}
}

void tsp(struct graph* g,int cur,int num,int acc){
    int j; // loop variable
    if(num==g->n){
        if(g->adjs[cur][0]!=0){
            if(g->m>acc+g->adjs[cur][0]){
               g->m=acc+g->adjs[cur][0];
            }
        }
        return;
    }
    for(j=0;j<g->n;j++){
        if((g->vist[j]==0)&&(g->adjs[cur][j]!=0)){
            g->vist[j]=1;
            tsp(g,j,num+1,acc+g->adjs[cur][j]);
            g->vist[j]=0;
        }
    }
}
```
```
$ ./test
35
```
<!-- #### DP TSP -->
