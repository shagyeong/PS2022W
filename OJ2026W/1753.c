// G4 1753: 최단경로(데이크스트라,힙,정적 메모리)
// 사전순 삽입->헤드 삽입
// 선형 탐색->힙
// malloc()->정적 메모리

#include<stdio.h>

#define N   20001   // 노드 최대 개수
#define E   300001  // 간선 최대 개수
#define INF 3000001 // 10*300,000

struct node{
    unsigned int v; // value
    unsigned int w; // w
    unsigned int next;
};
struct hode{    // heap node
    unsigned int v; // value
    unsigned int d; // distance
};
struct graph{
    unsigned int n; // 노드 개수
    unsigned int adjs[N]; // 인접리스트 -> 정적 메모리
    unsigned int dist[N];
    struct hode heap[E*3]; // E*3:힙 공간 확보
    unsigned int i; // number of heap item
    unsigned int p; // pool index
};

struct node pool[E];
struct graph g;

void push(unsigned int v,unsigned int d);
struct hode pop(void);
void dijkstra(unsigned int s);
void init_graph(unsigned int n);
void insert(unsigned int u,unsigned int v,unsigned int w);

int main(void) {
    unsigned int j; // loop variable
    unsigned int n; // node
    unsigned int e; // edge
    unsigned int s; // start
    unsigned int u; // insert buffer
    unsigned int v; // insert buffer
    unsigned int w; // insert buffer

    scanf("%d %d",&n,&e);
    scanf("%d",&s);
    init_graph(n+1); // n+1: 1부터 시작하는 과제 환경
    for(j=0;j<e;j++){
        scanf("%d %d %d",&u,&v,&w);
        insert(u,v,w);
    }

    dijkstra(s);
    for(j=1;j<=n;j++){
        w=g.dist[j];
        if(w==INF){printf("INF\n");}
        else      {printf("%u\n",w);}
    }

    return 0;
}
void push(unsigned int v,unsigned int d){
    unsigned int j; // loop variable
    struct hode t;  // temp variable(swap)
    g.heap[++(g.i)].v=v; // 선형 트리 마지막 엘리먼트로 삽입
    g.heap[  (g.i)].d=d;
    j=g.i;

    //heapify
    while((j>1)&&(g.heap[j].d<g.heap[j/2].d)){
        t.v=g.heap[j].v;           t.d=g.heap[j].d;
        g.heap[j].v=g.heap[j/2].v;g.heap[j].d=g.heap[j/2].d;
        g.heap[j/2].v=t.v;         g.heap[j/2].d=t.d;
        j/=2;
    }
}
struct hode pop(void){
    unsigned int j; // loop variable
    unsigned int c; // child
    struct hode r; // root: 리턴값
    struct hode t; // temp variable(swap)

    r=g.heap[1]; // 루트
    g.heap[1]=g.heap[(g.i)--]; // 선형 트리 마지막 엘리먼트를 루트로
    j=1;

    // heapify
    while(j*2<=g.i){
        c=j*2; // lchild
        if((c+1<=g.i)&&(g.heap[c+1].d<g.heap[c].d)){
            c+=1; // rchild
        }
        if(g.heap[j].d<=g.heap[c].d){
            break;
        }
        t.v=g.heap[j].v;           t.d=g.heap[j].d;
        g.heap[j].v=g.heap[c].v;g.heap[j].d=g.heap[c].d;
        g.heap[c].v=t.v;         g.heap[c].d=t.d;
        j=c;
    }
    return r;
}

void dijkstra(unsigned int s){
    struct hode  h;
    unsigned int n; // struct node->unsigned int
    g.dist[s]=0;
    push(s,0);
    while(g.i>0){
        // 방문되지 않은 노드 중 가장 가까운 노드 찾기: pop()
        h=pop();

        // push 이후 시점에 더 짧은 경로가 dist 배열에 갱신된 경우: continue
        if(g.dist[h.v]<h.d){continue;}

        // 인접 노드 갱신
        for(n=g.adjs[h.v];n!=0;n=pool[n].next){ // INF: (n=n->next)!=NULL과 대응
            if (g.dist[h.v]+pool[n].w<g.dist[pool[n].v]){
                g.dist[pool[n].v]=g.dist[h.v]+pool[n].w;
                push(pool[n].v,g.dist[pool[n].v]);
            }
        }
    }
}
void init_graph(unsigned int n){
    unsigned int j;
    for(j=0;j<n;j++){
        g.adjs[j]=0;  // pool index: 1부터 시작
        g.dist[j]=INF;
    }
    g.n=n;
    g.i=0; // number of heam item
    g.p=1; // pool index
}
void insert(unsigned int u,unsigned int v,unsigned int w){
    pool[g.p].v=v;
    pool[g.p].w=w;
    pool[g.p].next=g.adjs[u];
    g.adjs[u]=g.p;
    g.p++;
}
