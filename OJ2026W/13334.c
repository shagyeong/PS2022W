// G2 13334: 철로(정렬,힙,스위핑)
#include<stdio.h>
#include<stdlib.h>

struct node{
    int l;
    int r;
};
struct heap{
    int* a; // array
    int  n; // number of element
};

void init(struct heap* h,int n);
void push(struct heap* h,int v);
int   pop(struct heap* h);
int compare(const void* u,const void* v);

int main(void){
    int m=0; // answer
    int j;
    int u; int v;
    int n; scanf("%d",&n);
    int d;
    struct node* a=(struct node*)malloc(sizeof(struct node)*n);
    struct heap h;
    init(&h,n);
    for(j=0;j<n;j++){
        scanf("%d %d",&u,&v);
        if(u<v){a[j].l=u; a[j].r=v;}
        else   {a[j].l=v; a[j].r=u;}
    }
    scanf("%d",&d);

    qsort(&a[0],n,sizeof(struct node),compare);
    for(j=0;j<n;j++){
        if(d<(a[j].r-a[j].l)){continue;}
        push(&h,a[j].l);
        while((h.n>0)&&(h.a[1]<a[j].r-d)){pop(&h);}
        m=(m<h.n)?h.n:m;
    }
    printf("%d",m);
}

void init(struct heap* h,int n){
    h->a=(int*)malloc(sizeof(int)*(n+1)); // n+1: 1부터 시작하는 선형 트리 인덱스
    h->n=0;
}
void push(struct heap* h,int v){
    int i=++(h->n); // index of tree
    int t;          // temp variable: swap
    
    h->a[i]=v;      // 마지막 엘리먼트로 삽입 후 heapify up
    while((i>1)&&(h->a[i]<h->a[i/2])){
        t=h->a[i];
        h->a[i]=h->a[i/2];
        h->a[i/2]=t;
        i/=2;
    }
}
int pop(struct heap* h){
    int r=h->a[1]; // return value
    int i=1;       // index of tree
    int t;         // temp variable(swap)
    int c;         // child

    h->a[i]=h->a[(h->n)--]; // 루트 덮어쓰기 후 heapify down
    while(i*2<=h->n){
        if((i*2+1<=h->n)&&(h->a[i*2+1]<h->a[i*2])){c=i*2+1;} // rchild
        else                                      {c=i*2;}   // lchild
        if(h->a[i]<=h->a[c]){break;}
        t=h->a[i];
        h->a[i]=h->a[c];
        h->a[c]=t;
        i=c;
    }
    return r;
}
int compare(const void* u,const void* v){
    if((((struct node*)u)->r)<(((struct node*)v)->r)){return -1;}
    if((((struct node*)u)->r)>(((struct node*)v)->r)){return  1;}
    return 0;
}