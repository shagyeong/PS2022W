// G4 5052: 전화번호 목록(트라이)
#include<stdio.h>
#include<stdlib.h>

#define N 10 // 10진수 환경

struct trie{
    struct node* r;
};
struct node{
    struct node* c[N]; // 10진수 환경
    int          f; // flag: isend
};

void   init(struct trie* t);
void insert(struct trie* t,char* s); // trie, character array
int  search(struct trie* t,char* s);

int main(void){
    int j;
    int k;
    struct trie t;
    char s[10];
    int n; scanf("%d",&n);
    int p;

    for(j=0;j<n;j++){
        init(&t);
        scanf("%d",&p);
        for(k=0;k<p;k++){
            scanf("%s",s);
            if(search(&t,s)==1){printf("NO\n");goto escape;}
            insert(&t,s);
        }
        printf("YES\n"); continue;
        escape:
        while(++k<p){scanf("%s",s);}
    }
}

void   init(struct trie* t){
    int j;
    t->r=(struct node*)malloc(sizeof(struct node));
    t->r->f=0;
    for(j=0;j<N;j++){t->r->c[j]=NULL;}
}
void insert(struct trie* t,char* s){
    int j=0; // loop variable
    int i; // index
    struct node* d=t->r;
    for(j=0;s[j]!='\0';j++){
        i=s[j]-'0'; // 48~57 -> 0~9
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
        i=s[j]-'0'; // 48~57 -> 0~9
        if(d->c[i]==NULL){return 0;}
        d=d->c[i];
        if(d->f==1){return 1;}
    }
    return 1; // 루프 break 없음: 접두사
}