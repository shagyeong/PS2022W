// S4 1620: 포켓몬마스터(해시)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 100007
#define L 21

struct node{
    char* s;
    int v;
    struct node* next;
};
struct hash{
    int n;
    struct node** t;
};

int    hash(char* s);
void   init(struct hash* h,int n);
void  clean(struct hash* h);
void insert(struct hash* h,char* s,int v);
int   query(struct hash* h,char* s);

int main(void){
    int j; int k=0;
    int n; int m; scanf("%d %d",&n,&m);
    char** a=(char**)malloc(sizeof(char*)*(n+1));
    char* _a=(char*) malloc(sizeof(char) *(n+1)*L);
    char*  q=(char*) malloc(sizeof(char) *L); // query
    int r; // 쿼리 리턴값
    struct hash h;
    init(&h,N);
    for(j=0;j<=n;j++){a[j]=_a+k; k+=L;}
    for(j=1;j<=n;j++){scanf("%s",a[j]); insert(&h,a[j],j);}
    for(j=0;j< m;j++){
        scanf("%s",q);
        r=query(&h,q);
        if(r==-1){printf("%s\n",a[atoi(q)]);}
        else     {printf("%d\n",r);}
    }
    free(q);
    free(_a);
    free(a);
}

int    hash(char* s){
    int h=5381;
    while(*s!='\0'){h=((h<<5)+h)+*s++;}
    return h&0x7FFFFFFF;
}
void   init(struct hash* h,int n){
    h->n=n;
    h->t=(struct node**)calloc(n,sizeof(struct node));
}
void  clean(struct hash* h){
    int j;
    struct node* d;
    struct node* f;
    for(j=0;j<h->n;j++){
        d=h->t[j];
        while(d!=NULL){
            f=d;
            d=d->next;
            free(f);
        }
    }
    free(h->t);
}
void insert(struct hash* h,char* s,int v){
    int i=hash(s)%h->n;
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->s=s;
    n->v=v;
    n->next=h->t[i];
    h->t[i]=n;
}
int   query(struct hash* h,char* s){
    int v=hash(s);
    int i=v%h->n;
    struct node* d=h->t[i];
    while(d!=NULL){
        if(strcmp(d->s,s)==0){return d->v;} // 문제 조건: v 중복 없음(1-based)
        d=d->next;
    }
    return -1;
}