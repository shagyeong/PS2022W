// G2 1202: 보석 도둑(정렬,힙,그리디)
#include<stdio.h>
#include<stdlib.h>

struct node{
    int w;
    int v;
};
struct heap{
    int* a; // array: 선형 트리
    int  i; // item: 엘리먼트 개수
};

int compare     (const void* u,const void* v);
int compare_node(const void* u,const void* v);
void push(struct heap* h,int v);
int   pop(struct heap* h);

int main(void){
    long long int r=0; // answer
    int i=0; // index of node
    int j; // loop variable
    int n; int k; scanf("%d %d",&n,&k);
    int w; int v;
    struct node a[n];
    int         b[k];
    struct heap h;
    h.a=(int*)malloc(sizeof(int)*(n+1)); // n+1: 1부터 시작하는 힙 인덱스
    h.i=0;
    for(j=0;j<n;j++){scanf("%d %d",&w,&v); a[j].w=w; a[j].v=v;}
    for(j=0;j<k;j++){scanf("%d",&b[j]);}
    qsort(&a[0],n,sizeof(struct node),compare_node);
    qsort(&b[0],k,sizeof(int),        compare);

    for(j=0;j<k;j++){
        while((i<n)&&(a[i].w)<=b[j]){push(&h,a[i++].v);}
        if(h.i>0){r+=pop(&h);}
    }
    printf("%lld",r);
}

int compare(const void* u,const void* v){
    if((*((int*)u))<(*((int*)v))){return -1;}
    if((*((int*)u))>(*((int*)v))){return  1;}
    return 0;
}
int compare_node(const void* u,const void* v){
    if((((struct node*)u)->w)< (((struct node*)v)->w)){return -1;}
    if((((struct node*)u)->w)> (((struct node*)v)->w)){return  1;}
    if((((struct node*)u)->w)==(((struct node*)v)->w)){
    if((((struct node*)u)->v)< (((struct node*)v)->v)){return -1;}
    if((((struct node*)u)->v)> (((struct node*)v)->v)){return  1;}
    }
    return 0;
}
void push(struct heap* h,int v){
    int j; // loop variable
    int t; // temp variable(swap)
    h->a[++(h->i)]=v; // 선형 트리 마지막 엘리먼트로 삽입
    j=h->i;
    while((j>1)&&(h->a[j]>h->a[j/2])){ // 부모: floor(j/2)
        t=h->a[j];
        h->a[j]=h->a[j/2];
        h->a[j/2]=t;
        j/=2;
    }
}
int pop(struct heap* h){
    int r; // root: 리턴값
    int j; // loop variable
    int t; // temp variable(swap)
    int c; // child

    r=h->a[1]; // 루트
    h->a[1]=h->a[(h->i)--]; // 선형 트리 마지막 엘리먼트를 루트로
    j=1;
    while(j*2<=h->i){
        c=j*2; // lchild
        if((c+1<=h->i)&&(h->a[c+1]>h->a[c])){
            c+=1; // rchild: j*2+1
        }
        if(h->a[j]>=h->a[c]){
            break;
        }
        t=h->a[j];
        h->a[j]=h->a[c];
        h->a[c]=t;
        j=c;
    }
    return r;
}