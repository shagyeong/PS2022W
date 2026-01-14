// G5 13549: 숨바꼭질 3(0-1BFS)
#include<stdio.h>
#include<stdlib.h>

#define N 100001

struct node{
    int v; // value
    struct node* prev;
    struct node* next;
};
struct queue{
    int n;          // number of item
    struct node* h; // head
};

void fenqueue(struct queue* q,int v);
void renqueue(struct queue* q,int v);
int  fdequeue(struct queue* q);
int  rdequeue(struct queue* q);

int main(void){
    int j;
    int c; // current
    int x; // next
    int n; int k; scanf("%d %d",&n,&k);
    struct queue q;
    q.n=0;
    q.h=(struct node*)malloc(sizeof(struct node));
    q.h->v=-1;
    q.h->prev=q.h;
    q.h->next=q.h;

    int d[N];
    for(j=0;j<N;j++){d[j]=-1;}
    d[n]=0;
    fenqueue(&q,n);
    while(q.n>0){
        c=rdequeue(&q);
        if(c==k){printf("%d",d[c]); break;}
        x=c*2; if((x< N)&&((d[x]==-1)||(d[x]>d[c]  ))){d[x]=d[c];fenqueue(&q,x);}
        x=c-1; if((x>=0)&&((d[x]==-1)||(d[x]>d[c]+1))){d[x]=d[c]+1;renqueue(&q,x);}
        x=c+1; if((x< N)&&((d[x]==-1)||(d[x]>d[c]+1))){d[x]=d[c]+1;renqueue(&q,x);}
    }
}

void fenqueue(struct queue* q,int v){
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    n->v=v;
    n->prev         =q->h;
    n->next         =q->h->next;
    q->h->next->prev=n;
    q->h->next      =n;
    q->n+=1;
}
void renqueue(struct queue* q,int v){
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    n->v=v;
    n->prev         =q->h->prev;
    n->next         =q->h;
    q->h->prev->next=n;
    q->h->prev      =n;
    q->n+=1;
}
int  fdequeue(struct queue* q){
    int d; // dequeue
    struct node* f; // free
    f=q->h->prev; d=f->v;
    q->h->prev->prev->next=q->h;
    q->h->prev            =q->h->prev->prev;
    q->n-=1; free(f);
    return d;
}
int rdequeue(struct queue* q){
    int d; // dequeue
    struct node* f; // free
    f=q->h->next; d=f->v;
    q->h->next->next->prev=q->h;
    q->h->next            =q->h->next->next;
    q->n-=1; free(f);
    return d;
}