# 5장 문자열
## 5.1 문자 배열 조작
### 5.1.1 str/mem 함수군
#### 주요 str/mem 함수군
```C
#include<string.h>

size_t strlen(const char* s);
int    strcmp(const char* s1,const char* s2);
char*  strcpy(char* dest,const char* src);
char*  strcat(char* dest,const char* src);
char*  strtok(char* str,const char* delim);

void* memset(void* s,int c,size_t n);
```
#### strlen()
```C
int n; scanf("%d",&n);
char* a=(char*)malloc(sizeof(char)*n);
size_t l=strlen(a);
```
#### strcmp()
음수 리턴: s1이 사전순으로 앞섬  
0 리턴: 일치  
양수 리턴: s2가 사전순으로 앞섬  
```C
// 사전순 정렬
int compare(const void* u,const void* v){return strcmp(*((char**)u),*((char**)v));}
```
#### strcpy()
```C
int n; scanf("%d",&n);
char* a=(char*)malloc(sizeof(char)*n);
char* b=(char*)malloc(sizeof(char)*n);
scanf("%s",a);
strcpy(b,a);
```
#### strcat()
```C
int n; scanf("%d",&n);
char* a=(char*)malloc(sizeof(char)*n);
char* b=(char*)malloc(sizeof(char)*n);
scanf("%s",a);
scanf("%s",b);
strcat(b,a);
```
```
$ ./test
abc def # a, b
defabc  # print b
```
#### strtok()
```C
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define L 1024

int main(void){
    int n; scanf("%d",&n);
    int i=0; // index of char* array
    char*  s=(char*) malloc(sizeof(char)* L);
    char** a=(char**)malloc(sizeof(char*)*n);
    char*  p;

    scanf("%s",s);
    p=strtok(s,",");
    while(p!=NULL){
        a[i]=(char*)malloc(strlen(p)+1);
        strcpy(a[i],p);
        i++;
        p=strtok(NULL,","); // 오프셋 유지
    }
    i=0;
    while(i<n){printf("%s\n",a[i]); free(a[i++]);}
    free(s);
    free(a);
}
```
```
$ ./test > test.txt
3
Kim,Lee,Park

$ cat test.txt
Kim
Lee
Park
```
#### memset()
```C
int n; scanf("%d",&n);
char* a=(char*)malloc(sizeof(char)*n);
memset(a,0b00000000,sizeof(char)*n);
```



## 5.2 접두사 조작
### 5.2.1 트라이
#### 접두사 탐색
```C
#include<stdio.h>
#include<stdlib.h>

#define N 26 // 소문자 알파벳 환경
#define L 10001 // 문자열 최대 길이

struct trie{struct node* r;};
struct node{struct node* c[N];};

void   init(struct trie* t);
void insert(struct trie* t,char* s);
int  search(struct trie* t,char* s);

int main(void){
    int j;
    int n; int m; scanf("%d %d",&n,&m);
    char s[L];
    struct trie t;
    init(&t);
    for(j=0;j<n;j++){scanf("%s",s);insert(&t,s);}
    for(j=0;j<m;j++){scanf("%s",s);printf("%d ",search(&t,s));}
}

void   init(struct trie* t){
    int j;
    t->r=(struct node*)malloc(sizeof(struct node));
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
            for(int x=0;x<N;x++){d->c[i]->c[x]=NULL;}
        }
        d=d->c[i];
    }
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
```
```
$ ./test
2 5 # number of node, query
abcd efgh
abcd ab efgh e x
4 2 4 1 0 
```



## 5.3 접미사 조작
### 5.3.1 접미사 배열
#### 이차로그시간 접미사 배열: 정렬
```C
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare(const void* u,const void* v){return strcmp(*((char**)u),*((char**)v));}

int main(void){
    int j; int k;
    char* s=(char*)malloc(sizeof(char)*1000);
    int l;
    char** a;

    scanf("%s",s);
    l=(int)(strlen(s));
    a=(char**)malloc(sizeof(char*)*l);

    for(j=0;j<l;j++){
        a[j]=(char*)malloc(sizeof(char)*(l-j+1));
        for(k=j;k<l;k++){a[j][k-j]=s[k];}
        a[j][l-j]='\0';
    }

    qsort(&a[0],l,sizeof(char*),compare);
    for(j=0;j<l;j++){printf("%s\n",a[j]); free(a[j]);}
    free(a);
}
```
```
$ ./test
shagyeong
agyeong
eong
g
gyeong
hagyeong
ng
ong
shagyeong
yeong
```



<!-- ## 5.4 패턴 매칭 -->
