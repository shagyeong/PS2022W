// G3 16934: 게임 닉네임(트라이,해시)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 26 // 소문자 알파벳 환경
#define L 11 // 문자열 최대 길이
#define M 100003 // 해시 divisor

struct trie{
    struct node* r;
};
struct node{
    struct node* c[N];
    int f; // flag: isend
};
struct hash{
    int n;
    struct hode** t;
};
struct hode{ // hash node
    char* s;
    int v;
    struct hode* next;
};

void   init(struct trie* t);
void insert(struct trie* t,char* s);
int  search(struct trie* t,char* s);

int       hash(char* s);
void init_hash(struct hash* h,int n);
int query_hash(struct hash* h,char* s);

int main(void){
    int j; int k;
    int n; scanf("%d",&n);
    int i; // 중복 닉네임 identifier
    int l;
    char s[L];
    struct trie t; init(&t);
    struct hash h; init_hash(&h,M);
    for(j=0;j<n;j++){
        scanf("%s",s);
        if((i=query_hash(&h,s))>1){printf("%s%d\n",s,i); insert(&t,s);}
        else{
            l=search(&t,s);
            if(l==(int)strlen(s)){for(k=0;k< l;k++){printf("%c",s[k]);}printf("\n");} // '\0' 출력 방지
            else                 {for(k=0;k<=l;k++){printf("%c",s[k]);}printf("\n");}
            insert(&t,s);
        }
    }
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
        if(d->c[i]==NULL){return j;}
        d=d->c[i];
    }
    return j;
}
int       hash(char* s){
    int h=5381;
    while(*s!='\0'){h=((h<<5)+h)+*s++;}
    return h&0x7FFFFFFF;
}
void init_hash(struct hash* h,int n){
    h->n=n;
    h->t=(struct hode**)calloc(n,sizeof(struct hode*));
}
int query_hash(struct hash* h,char* s){
    int v=hash(s);
    int i=v%h->n;
    struct hode* n; // new
    struct hode* d=h->t[i];
    while(d!=NULL){
        if(strcmp(d->s,s)==0){return ++d->v;}
        d=d->next;
    }
    n=(struct hode*)malloc(sizeof(struct hode));
    n->s=strdup(s);
    n->v=1;
    n->next=h->t[i];
    h->t[i]=n;
    return 1; // n->v
}