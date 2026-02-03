# 5장 문자열
<!-- ## 5.1 파싱 -->



## 5.2 문자열 분석
### 5.2.3 접두사 조작
#### 트라이: 소문자 알파벳 환경
```C
#include<stdio.h>
#include<stdlib.h>

#define N 26 // 소문자 알파벳 환경

struct trie{
    struct node* r;
};
struct node{
    struct node* c[N];
    int          f; // flag: isend
};

void   init(struct trie* t);
void insert(struct trie* t,char* s); // trie, character array
int  search(struct trie* t,char* s);

int main(void){
    struct trie t;
    init(&t);
    char s[10]="abcdef";
    insert(&t,s);
    printf("%s: %d\n",s,    search(&t,s));
    printf("%s: %d\n","abc",search(&t,"abc"));
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
        i=s[j]-'a'; // 97~122 -> 0~25
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
        i=s[j]-'a'; // 97~122 -> 0~25
        if(d->c[i]==NULL){return 0;}
        d=d->c[i];
    }
    return d->f;
}
```
```
$ ./test
abcdef: 1
abc: 0
```
#### 접두사 탐색
```C
int  search(struct trie* t,char* s){
    int j; // loop variable
    int i; // index
    struct node* d=t->r;
    for(j=0;s[j]!='\0';j++){
        i=s[j]-'a'; // 97~122 -> 0~25
        if(d->c[i]==NULL){return 0;}
        d=d->c[i];
        if(d->f==1){return 1;}
    }
    return 1; // 루프 break 없음: 접두사
}
```
```
$ ./test
abcdef: 1
abc: 1
```



<!-- ## 5.3 패턴 매칭 -->
