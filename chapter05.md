# 5장 문자열
## 5.1 파싱
### 5.1.1 기초 분리 및 변환
#### 구분자 처리: strtok()
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
#### 공백없는 격자그래프
```C
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j; int k;
    int r; int c; scanf("%d %d",&r,&c);
    int** g=(int**)malloc(sizeof(int*)*r);
    int*  d=(int*) malloc(sizeof(int) *r*c);
    for(j=0;j<r;j++){g[j]=d+(c*j);}
    for(j=0;j<r;j++){for(k=0;k<c;k++){scanf("%1d",&g[j][k]);}}
    for(j=0;j<r;j++){for(k=0;k<c;k++){printf("%d ",g[j][k]);}printf("\n");}
    free(d);
    free(g);
}
```
```
$ ./test
2 3
010
111
0 1 0 
1 1 1 
```



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
### 5.2.4 접미사 조작
#### strcmp()
```C
#include<string.h>

int strcmp(const char* s1,const char* s2);
```
사전순 내림차순  
#### 접미사 배열: 사전순 정렬
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



<!-- ## 5.3 패턴 매칭 -->
