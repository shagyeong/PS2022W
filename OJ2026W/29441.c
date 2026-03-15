// P3 29441: XOR(트라이)
#include<stdio.h>
#include<stdlib.h>

#define N 2  // 이진 트라이
#define L 32 // 32비트 이진 정수

struct trie{struct node* r;};
struct node{struct node* c[N];};

void   itoa(char* s,unsigned int i);
void   init(struct trie* t);
void insert(struct trie* t,char* s);
unsigned int search(struct trie* t,char* s);

int main(void){
    unsigned int j;
    unsigned int n; unsigned int m;
    unsigned int v;
    char s[L];
    struct trie t;
    init(&t);
    scanf("%u",&n); for(j=0;j<n;j++){scanf("%u",&v); itoa(s,v); insert(&t,s);}
    scanf("%u",&m); for(j=0;j<m;j++){scanf("%u",&v); itoa(s,v); printf("%u ",search(&t,s));}
}

void   itoa(char* s,unsigned int i){
    unsigned int j=32;
    while(--j<32){s[j]=(i&1)+'0';i>>=1;} // unsigned: 오버플로우로 탈출
}
void   init(struct trie* t){
    unsigned int j;
    t->r=(struct node*)malloc(sizeof(struct node));
    for(j=0;j<N;j++){t->r->c[j]=NULL;}
}
void insert(struct trie* t,char* s){
    unsigned int j; unsigned int k;// loop variable
    unsigned int i; // index
    struct node* d=t->r;
    for(j=0;j<32;j++){
        i=s[j]-'0';
        if(d->c[i]==NULL){
            d->c[i]=(struct node*)malloc(sizeof(struct node));
            for(k=0;k<N;k++){d->c[i]->c[k]=NULL;}
        }
        d=d->c[i];
    }
}
unsigned int search(struct trie* t,char* s){
    unsigned int j; // loop variable
    unsigned int i; // index
    unsigned int a=0; // answer
    struct node* d=t->r;
    for(j=0;j<32;j++){
        i=s[j]-'0';
        if(d->c[i^1]!=NULL){d=d->c[i^1]; a|=((i^1)<<(31-j));}
        else               {d=d->c[i];   a|=((i)  <<(31-j));}
    }
    return a;
}