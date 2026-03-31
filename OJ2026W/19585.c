// P3 19585: 전설(트라이,해시)
// 색상이 다른 색상의 접두사일 수 있음: isend 플래그 등장시 위치를 배열에 담음(즉시 리턴하는 것이 아님)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 26
#define L 2001
#define D 50003 // hash divisor

struct arrr{
    int* a;
    int  i;
};
struct trie{
    struct node* r;
};
struct node{
    struct node* c[N];
    int f;
};

struct hode{
    char* s;
    int v;
    struct hode* next;
};
struct hash{
    int n;
    struct hode** t;
};

// trie
void    init_trie(struct trie* t);
void  insert_trie(struct trie* t,char* s);
void search_color(struct trie* t,char* s);

// hash
int         hash(char* s,int u);
void   init_hash(struct hash* h,int n);
void insert_hash(struct hash* h,char* s);
int        query(struct hash* h,char* s,int u); // u: 시작 인덱스

struct arrr a;

int main(void){
    int j; int k;
    int n; scanf("%d",&n);
    int m; scanf("%d",&m);
    int q;
    int f;
    char* s=(char*)malloc(sizeof(char)*L);
    struct trie color; init_trie(&color);
    struct hash names; init_hash(&names,D);
    for(j=0;j<n;j++){scanf("%s",s); insert_trie(&color,s);}
    for(j=0;j<m;j++){scanf("%s",s); insert_hash(&names,s);}

    a.a=(int*)malloc(sizeof(int)*1000);

    scanf("%d",&q);
    for(j=0;j<q;j++){
        scanf("%s",s);
        search_color(&color,s);
        f=0;
        for(k=0;k<a.i;k++){
            f=query(&names,s,a.a[k]);
            if(f==1){break;}
        }
        if(f==0){printf("No\n");}
        else    {printf("Yes\n");}
    }
}

void         init_trie(struct trie* t){
    int j;
    t->r=(struct node*)malloc(sizeof(struct node));
    t->r->f=0;
    for(j=0;j<N;j++){t->r->c[j]=NULL;}
}
void       insert_trie(struct trie* t,char* s){
    int j; int k;
    int i;
    struct node* d=t->r;
    for(j=0;s[j]!='\0';j++){
        i=s[j]-'a';
        if(d->c[i]==NULL){
            d->c[i]=(struct node*)malloc(sizeof(struct node));
            d->c[i]->f=0;
            for(k=0;k<N;k++){d->c[i]->c[k]=NULL;}
        }
        d=d->c[i];
    }
    d->f=1;
}
void search_color(struct trie* t,char* s){
    int j;
    int i;
    struct node* d=t->r;
    a.i=0;
    for(j=0;s[j]!='\0';j++){
        i=s[j]-'a';
        if(d->f==1){a.a[a.i++]=j;}
        if(d->c[i]==NULL){break;}
        d=d->c[i];
    }
    if(s[j]=='\0'){if(d->f==1){a.a[a.i++]=j;}}
}
int         hash(char* s,int u){
    s+=u;
    int h=5381;
    while(*s!='\0'){h=((h<<5)+h)+*s++;}
    return h&0x7FFFFFFF;
}
void   init_hash(struct hash* h,int n){
    h->n=n;
    h->t=(struct hode**)calloc(n,sizeof(struct hode*));
}
void insert_hash(struct hash* h,char* s){
    int v=hash(s,0);
    int i=v%h->n;
    struct hode* n=(struct hode*)malloc(sizeof(struct hode));
    n->s=strdup(s);
    n->v=v;
    n->next=h->t[i]; // chaining
    h->t[i]=n;
}
int        query(struct hash* h,char* s,int u){
    int v=hash(s,u);
    int i=v%h->n;
    struct hode* d=h->t[i];
    while(d!=NULL){
        if((d->v==v)&&(strcmp(d->s,s+u)==0)){return 1;}
        d=d->next;
    }
    return 0;
}