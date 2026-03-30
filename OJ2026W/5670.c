// P4 5670: 휴대폰 자판(트라이)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 26
#define L 1000001

struct trie{
    struct node* r;
};
struct node{
    struct node* c[N];
    int f; // isend flag
    int o; // 출력 차수: 1인 경우 '자판'을 누르지 않음
};

long long int w; // 전역 카운터
void   init(struct trie* t);
void  reset(struct node* u);
void  clean(struct trie* t);
void insert(struct trie* t,char* s);
void    dfs(struct trie* t,struct node* u,int c);
int   query(struct trie* t,char* s);

int main(void){
    int j;
    int n;
    char* s=(char*)malloc(sizeof(char)*L);
    struct trie t;
    init(&t);
    while(scanf("%d",&n)!=EOF){
        w=0;
        t.r->o=0;
        t.r->f=0;
        for(j=0;j<N;j++){reset(t.r->c[j]); t.r->c[j]=NULL;}
        for(j=0;j<n;j++){
            scanf("%s",s);
            insert(&t,s);
        }
        dfs(&t,t.r,1);
        printf("%.2f\n",(float)w/n);
    }

    clean(&t);
    free(s);
}

void   init(struct trie* t){
    int j;
    t->r=(struct node*)malloc(sizeof(struct node));
    t->r->o=0;
    t->r->f=0;
    for(j=0;j<N;j++){
        t->r->c[j]=NULL;
    }
}
void  reset(struct node* u){
    int j;
    if(u==NULL){return;}
    for(j=0;j<N;j++){reset(u->c[j]);}
    free(u);
}
void  clean(struct trie* t){
    free(t->r);
}
void insert(struct trie* t,char* s){
    int j; int k;
    int i;
    struct node* d=t->r;
    
    for(j=0;s[j]!='\0';j++){
        i=s[j]-'a';
        if(d->c[i]==NULL){
            d->o+=1; // 출력 차수 증가
            d->c[i]=(struct node*)malloc(sizeof(struct node));
            d->c[i]->o=0;
            d->c[i]->f=0;
            for(k=0;k<N;k++){d->c[i]->c[k]=NULL;}
        }
        d=d->c[i];
    }
    d->f=1;
}
void    dfs(struct trie* t,struct node* u,int c){
    int j;
    if(u->f==1){w+=c;}
    for(j=0;j<N;j++){
    if(u->c[j]!=NULL){
        if(u==t->r)             {dfs(t,u->c[j],1);}
        else if(u->o>1||u->f==1){dfs(t,u->c[j],c+1);}
        else                    {dfs(t,u->c[j],c);}
    }}
}