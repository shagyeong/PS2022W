// S2 1927: 최소 힙(힙)
#include<stdio.h>
#include<stdlib.h>

int A[100000];

struct heap{
    int* a; // array: 선형 트리
    int  i; // item: 엘리먼트 개수
};

void push(struct heap* h,int v);
int pop(struct heap* h);

int main(void){
    int j; // loop variable
    int n;
    int q; // query
    struct heap h;
    h.a=&A[0];
    h.i=0;
    scanf("%d",&n);
    
    for(j=0;j<n;j++){
        scanf("%d",&q);
        if(q==0){printf("%d\n",pop(&h));}
        else    {push(&h,q);}
    }
}

void push(struct heap* h,int v){
    int j; // loop variable
    int t; // temp variable(swap)
    h->a[++(h->i)]=v; // 선형 트리 마지막 엘리먼트로 삽입
    j=h->i;

    // heapify
    while((j>1)&&(h->a[j]<h->a[j/2])){ // 부모: floor(j/2)
        t=h->a[j];
        h->a[j]=h->a[j/2];
        h->a[j/2]=t;
        j/=2;
    }
}
int pop(struct heap* h){
    if(h->i==0){return 0;} // 문제 조건: 힙이 빈 경우 0을 출력
    int r; // root: 리턴값
    int j; // loop variable
    int t; // temp variable(swap)
    int c; // child

    r=h->a[1]; // 루트
    h->a[1]=h->a[(h->i)--]; // 선형 트리 마지막 엘리먼트를 루트로
    j=1;

    // heapify
    while(j*2<=h->i){
        c=j*2; // lchild
        if((c+1<=h->i)&&(h->a[c+1]<h->a[c])){
            c+=1; // rchild: j*2+1
        }
        if(h->a[j]<=h->a[c]){
            break;
        }
        t=h->a[j];
        h->a[j]=h->a[c];
        h->a[c]=t;
        j=c;
    }
    return r;
}