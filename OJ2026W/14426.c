// S1 14426: 접두사 찾기(트라이)
#include<stdio.h>
#include<stdlib.h>

#define N 26 // 소문자 알파벳 환경

struct trie{
    struct node* r;
};
struct node{
    struct node* c[N];
    int f; // flag: isend
};

void   init(struct trie* t);
void insert(struct trie* t,char* s);
int  search(struct trie* t,char* s);

int main(void){
    int j;
    int n; int m; scanf("%d %d",&n,&m);
    int a=0; // answer
    char s[10001];
    struct trie t;
    init(&t);
    for(j=0;j<n;j++){scanf("%s",s);insert(&t,s);}
    for(j=0;j<m;j++){scanf("%s",s);a+=search(&t,s);}
    printf("%d",a);
}

void   init(struct trie* t){
    int j;
    t->r=(struct node*)malloc(sizeof(struct node));
    t->r->f=0;
    for(j=0;j<N;j++){t->r->c[j]=NULL;}
}
void insert(struct trie* t,char* s){
    int j; // loop variable
    int i; // index
    struct node* d=t->r;
    for(j=0;s[j]!='\0';j++){
        i=s[j]-'a';
        if(d->c[i]==NULL){
            d->c[i]=(struct node*)malloc(sizeof(struct node));
            d->c[i]->f=0; // is not end
            for(int x=0;x<N;x++){d->c[i]->c[x]=NULL;}
        }
        d=d->c[i];
    }
    d->f=1;
}
int  search(struct trie* t,char* s){
    int j; // loop variable
    int i; // index
    struct node* d=t->r;
    for(j=0;s[j]!='\0';j++){
        i=s[j]-'a';
        if(d->c[i]==NULL){return 0;}
        d=d->c[i];
    }
    return 1; // 루프 break 없음: 접두사
}