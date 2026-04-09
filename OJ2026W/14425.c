// S4 14425: 문자열 집합(해시)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define D 50009 // divisor
#define L 501

struct node{
    char s[L];
    int next;
};
struct hash{
    int n; // number of words
    int p; // pool pointer
    int* adjs;
    struct node* pool;
};

int    hash(char* s);
void   init(struct hash* h,int n);
void  clean(struct hash* h);
void insert(struct hash* h,char* s);
int   query(struct hash* h,char* s);

int main(void){
    int j;
    int n; int m; scanf("%d %d",&n,&m);
    char q[L];
    struct hash h;
    int a=0; // answer
    init(&h,n);
    for(j=0;j<n;j++){scanf("%s",q); insert(&h,q);}
    for(j=0;j<m;j++){scanf("%s",q); a+=query(&h,q);}
    printf("%d",a);
    clean(&h);
}

int    hash(char* s){
    int h=5381;
    while(*s!='\0'){h=((h<<5)+h)+*s++;}
    return h&0x7FFFFFFF;
}
void   init(struct hash* h,int n){
    h->n=n;
    h->p=0;
    h->adjs=(int*)malloc(sizeof(int)*D);
    h->pool=(struct node*)malloc(sizeof(struct node)*n);
    memset(h->adjs,-1,sizeof(int)*D);
}
void  clean(struct hash* h){
    free(h->adjs);
    free(h->pool);
}
void insert(struct hash* h,char* s){
    int i=hash(s)%D;
    strcpy(h->pool[h->p].s,s);
    h->pool[h->p].next=h->adjs[i]; // chaining
    h->adjs[i]=h->p++;
}
int   query(struct hash* h,char* s){
    int i=hash(s)%D;
    int d=h->adjs[i];
    while(d!=-1){
        if(strcmp(h->pool[d].s,s)==0){return 1;}
        d=h->pool[d].next;
    }
    return 0;
}