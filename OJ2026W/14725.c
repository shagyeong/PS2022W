// G3 14725: 개미굴(문자열,트라이)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 1000

struct node{
    char         name[16]; // 문제 조건: 1<=t<=15
    struct node* adjs[N]; // child
    int c; // number of child
};
struct trie{
    struct node* r;
};

void   init(struct trie* t);
void insert(struct trie* t,char** a,int l);
void    dfs(struct node* s,int d);
int compare(const void* u, const void* v); // 자식 노드 사전순

int main(void){
    int j; int k; // loop variable
    int l;
    struct trie t;
    char** a=(char**)malloc(sizeof(char*)*15);
    int n; scanf("%d",&n);

    init(&t);
    for(j=0;j<n;j++){
        scanf("%d",&l);
        for(k=0;k<l;k++){
            a[k]=(char*)malloc(sizeof(char)*16);
            scanf("%s",a[k]);
        }
        insert(&t,a,l);
        for(k=0;k<l;k++){free(a[k]);}
    }
    dfs(t.r,0);
}

void   init(struct trie* t){
    int j;
    t->r=(struct node*)malloc(sizeof(struct node));
    t->r->c=0;
    t->r->name[0]='\0';
    for(j=0;j<N;j++){t->r->adjs[j]=NULL;}
}
void insert(struct trie* t,char** a,int l){
    int j; int k; int m; // loop variable
    struct node*d=t->r;
    int i; // index of node
    
    for(j=0;j<l;j++){
        i=-1;
        for(k=0;k<d->c;k++){
            if(strcmp(d->adjs[k]->name,a[j])==0){
                i=k;
                break;
            }
        }
        if(i==-1){
            struct node* n=(struct node*)malloc(sizeof(struct node)); // new
            strcpy(n->name,a[j]);
            n->c=0;
            for(m=0;m<N;m++){n->adjs[m]=NULL;}
            i=d->c;
            d->adjs[(d->c)++]=n;
        }
        d=d->adjs[i];
    }
}
void    dfs(struct node* s,int d){
    int j; int k;
    qsort(&s->adjs[0],s->c,sizeof(struct node*),compare);
    for(j=0;j<s->c;j++){
        for(k=0;k<d;k++){printf("--");}
        printf("%s\n",s->adjs[j]->name);
        dfs(s->adjs[j],d+1);
    }
}
int compare(const void* u, const void* v){
    return strcmp((*(struct node**)u)->name,(*(struct node**)v)->name);
}