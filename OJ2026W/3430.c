// G5 3430: AC(파싱,데크)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int v;
    struct node* prev;
    struct node* next;
};

struct queue{
    int n; // number of item
    int f; // flag: "뒤집기" 상태
    struct node* h; // head
};

void fe(struct queue* q,int v);
void re(struct queue* q,int v);
int fd(struct queue* q);
int rd(struct queue* q);
void freeq(struct queue* q); // 메모리 반납
void printq(struct queue* q);

int main(void){
    int j;
    int k;
    int n; scanf("%d",&n);
    int l;   // length
    int d;   // dequeue result
    int e=0; // error flag
    char* t; // t
    char f[100001]; // 작업 입력 문자열
    char a[400001]; // 데크 입력 문자열
    struct queue q;
    q.h=(struct node*)malloc(sizeof(struct node));
    
    for(j=0;j<n;j++){
        scanf("%s", f);
        scanf("%d", &l);
        scanf("%s", a); 
        q.n=0;
        q.f=0; // flag: 0 (정방향)
        q.h->prev=q.h;
        q.h->next=q.h;
        e=0;
        if(l>0){
            t=strtok(a+1,",]");
            while(t!=NULL){
                re(&q,atoi(t));
                t=strtok(NULL,",]");
            }
        }

        l=strlen(f);
        for(k=0;k<l;k++){
            if(f[k]=='R'){q.f=1-q.f;} // "뒤집기" 상태 토글
            if(f[k]=='D'){
                if(q.f==0){d=rd(&q);}
                else      {d=fd(&q);}
                if(d==-1) {e=1;break;}
            }
        }
        if(e==1){printf("error\n");}
        else    {printq(&q);}
        freeq(&q);
    }
    free(q.h);
}
void fe(struct queue* q,int v){
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    n->v=v;
    n->prev=q->h;
    n->next=q->h->next;
    q->h->next->prev=n;
    q->h->next=n;
    q->n+=1;
}
void re(struct queue* q,int v){
    struct node* n=(struct node*)malloc(sizeof(struct node)); // new
    n->v=v;
    n->prev=q->h->prev;
    n->next=q->h;
    q->h->prev->next=n;
    q->h->prev=n;
    q->n+=1;
}
int fd(struct queue* q){
    if(q->n==0){return -1;}
    int d; // dequeue value
    struct node* f; // free
    f=q->h->prev; d=f->v;
    q->h->prev->prev->next=q->h;
    q->h->prev=q->h->prev->prev;
    free(f); q->n-=1;
    return d;
}
int rd(struct queue* q){
    if(q->n==0){return -1;}
    int d;
    struct node* f;
    f=q->h->next; d=f->v;
    q->h->next->next->prev=q->h;
    q->h->next=q->h->next->next;
    free(f); q->n-=1;
    return d;
}
void freeq(struct queue* q){
    int j;
    int n;
    struct node* b;
    struct node* f;
    b=q->h->next;
    n=q->n;
    for(j=1;j<n;j++){
        f=b;
        b=b->next;
        free(f);
    }
}
void printq(struct queue* q){
    int j;
    struct node* b;
    if(q->n==0){printf("[]\n");}
    else{
        printf("[");
        if(q->f==0){
            b=q->h->next;
            for(j=0;j<q->n;j++){
                printf("%d%s",b->v,(j==(q->n-1))?"":",");
                b=b->next;
            }
        }
        else{
            b=q->h->prev;
            for(j=0;j<q->n;j++){
                printf("%d%s",b->v,(j==(q->n-1))?"":",");
                b=b->prev;
            }
        }
        printf("]\n");
    }
}