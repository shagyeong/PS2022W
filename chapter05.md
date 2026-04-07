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
### 5.3.1 접미사 배열과 LCP 배열
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
banana
a
ana
anana
banana
na
nana
```
#### 접미사 배열과 LCP 배열: 멘버-마이어스, 카사이
|sa[j]|0|1|2|3|4|5||접미사|인접 접미사|공통 접두사|공통 접두사 길이(lcp[j])|
|---|---|---|---|---|---|---|---|---|---|---|---|
|char* s|b|a|n|a|n|a||
|sa[0]=5| | | | | |a||a |*없음*|-|lcp[0]=-1|
|sa[1]=3| | | |a|n|a||ana   |a     |a  |lcp[1]=1|
|sa[2]=1| |a|n|a|n|a||anana |ana   |ana|lcp[2]=3|
|sa[3]=0|b|a|n|a|n|a||banana|anana |   |lcp[3]=0|
|sa[4]=4| | | | |n|a||na    |banana|   |lcp[4]=0|
|sa[5]=2| | |n|a|n|a||nana  |na    |na |lcp[5]=2|

```
$ ./test
banana
5 3 1 0 4 2 # suffix array
-1 1 3 0 0 2 # lcp array
```
```C
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 256 // 8비트 문자 환경
#define L 101

char* s;
int* a; // SA
int* b; // lcp
int* i; // indexes of s
int* r; // character ranks
int* t; // temp of r
int* c; // count: 계수정렬
int l; // length of s
int m; // leng of c
int o;
int p;

void manbermyers(void);
void kasai(void);

int main(void){
    s=(char*)malloc(sizeof(char)*(L)); scanf("%s",s);
    l=(int)strlen(s);
    m=(l>N)?l:N;
    a=(int*)calloc(l,    sizeof(int));
    b=(int*)calloc(l,    sizeof(int));
    i=(int*)calloc(l,    sizeof(int));
    r=(int*)calloc(2*l+1,sizeof(int));
    t=(int*)calloc(2*l+1,sizeof(int));
    c=(int*)calloc(m+1,  sizeof(int));
    manbermyers(); printf("\n");
    kasai();       printf("\n");
    free(s);
    free(a);
    free(b);
    free(i);
    free(r);
    free(t);
    free(c);
}

void manbermyers(void){
    int j;
    for(j=0;j<l;j++){
        a[j]=j;
        r[j]=s[j];
    }
    for(j=0;  j< m;j++){c[j]=0;}
    for(j=0;  j< l;j++){c[r[j]]++;}
    for(j=1;  j< m;j++){c[j]+=c[j-1];}
    for(j=l-1;j>=0;j--){a[--c[r[j]]]=j;}
    for(o=1;o<l;o<<=1){
        p=0;
        for(j=l-o;j< l;j++){i[p++]=j;}
        for(j=0;  j< l;j++){if(a[j]>=o){i[p++]=a[j]-o;}}
        for(j=0;  j< m;j++){c[j]=0;}
        for(j=0;  j< l;j++){c[r[i[j]]]++;}
        for(j=1;  j< m;j++){c[j]+=c[j-1];}
        for(j=l-1;j>=0;j--){a[--c[r[i[j]]]]=i[j];}
        t[a[0]]=1;
        for(j=1;j<l;j++){t[a[j]]=t[a[j-1]]+(((r[a[j-1]]==r[a[j]])&&(r[a[j-1]+o]==r[a[j]+o]))?0:1);}
        for(j=0;j<l;j++){r[j]=t[j];}
        if(r[a[l-1]]==l){break;}
        m=l+1;
    }
    for(j=0;j<l;j++){printf("%d ",a[j]);}
}
void kasai(void){
    int j;
    int k;
    int h=0;
    b[0]=-1;
    for(j=0;j<l;j++){
        k=r[j]-1;
        if(k>0){
            while((j+h<l)&&(a[k-1]+h<L)&&(s[j+h]==s[a[k-1]+h])){h++;}
            b[k]=h;
            if(h>0){h--;}
        }
    }
    for(j=0;j<l;j++){printf("%d ",b[j]);}
}
```



## 5.4 패턴 매칭
### 5.4.1 KMP
#### 실패함수
쿼리 문자열의 각 위치에서 가장 긴 진접두사인 동시에 진접미사인 부분의 길이  
#### 실패함수
k: 진접두사 오프셋  
j: 쿼리 문자열 오프셋  
```C
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define L 10002 // +2: '\n', '\0'(fgets: 공백 포함 문자열 대응)

int* fail(char* q,int l);

int main(void){
    int j;
    char* q=(char*)malloc(sizeof(char)*(L)); fgets(q,L,stdin);
    int l=(int)strlen(q); l--; q[l]='\0';
    int* f=fail(q,l);
    for(j=0;j<l;j++){printf("%c\t",q[j]);} printf("\n");
    for(j=0;j<l;j++){printf("%d\t",f[j]);} printf("\n");
    free(f);
    free(q);
}

int* fail(char* q,int l){
    int j;
    int k=0;
    int* f=(int*)calloc(l,sizeof(int));
    for(j=1;j<l;j++){
        while((k>0)&&(q[j]!=q[k])){k=f[k-1];}
        if(q[j]==q[k]){f[j]=++k;}
    }
    return f;
}
```
```
$ ./test
abcxxxabcabc
a       b       c       x       x       x       a       b       c       a       b       c
0       0       0       0       0       0       1       2       3       1       2       3

$ ./test
ababac
a       b       a       b       a       c
0       0       1       2       3       0
```
#### KMP
```C
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define L 10002 // +2: '\n', '\0'(fgets: 공백 포함 문자열 대응)

void kmp(char* a,char* q);

int main(void){
    char* a=(char*)malloc(sizeof(char)*L);
    char* q=(char*)malloc(sizeof(char)*L);
    fgets(a,L,stdin); a[strlen(a)-1]='\0';
    fgets(q,L,stdin); q[strlen(q)-1]='\0';
    kmp(a,q);
    free(a);
    free(q);
}

void kmp(char* a,char* q){
    int j;
    int k;
    int n=strlen(a);
    int m=strlen(q);
    int c=0; // 등장 횟수
    int* r=(int*)calloc(n,sizeof(int)); // 등장 위치
    int* f=(int*)calloc(m,sizeof(int)); // 실패함수

    // 실패함수
    k=0;
    for(j=1;j<m;j++){
        while((k>0)&&(q[j]!=q[k])){k=f[k-1];}
        if(q[j]==q[k]){f[j]=++k;}
    }
    
    // 매칭
    k=0;
    for(j=0;j<n;j++){
        while((k>0)&&(a[j]!=q[k])){k=f[k-1];}
        if(a[j]==q[k]){
            if(k==m-1){r[c++]=j-m+2; k=f[k];} // 매치
            else      {              k++;}
        }
    }

    // 결과 출력
    printf("%d\n",c);
    for(j=0;j<c;j++){printf("%d ",r[j]);}
    free(r);
    free(f);
}
```
```
$ ./test
longest proper prefix which is also a suffix
fix
2
19 42 
```
### 5.4.2 라빈-카프
#### 라빈 카프: 롤링 해시
$N^0q_0\\N^1q_0+N^0q_1\\N^2q_0+N^1q_1+N^0q_2\\\vdots$  
```C
for(j=0;j<m;j++){
    v=(v*N+q[j])%D;
    u=(u*N+a[j])%D;
}
```
슬라이딩 윈도우 기준값: $\mathrm{h}=N^{m-1}$  
$N\times((N^2q_0+N^1q_1+N^0q_2)-\mathrm{h}q_0)+q_3=(N^2q_1+N^1q_2+N^0q_3)$  
```C
if(j<n-m){
    u=(N*(u-a[j]*h)+a[j+m])%D;
    if(u<0){u+=D;}
}
```
#### 라빈-카프
```C
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 256 // 8바이트 문자 환경
#define L 10002
#define D 1000000007 // hash divisor

void rabinkarp(char* a,char* q);

int main(void){
    char* a=(char*)malloc(sizeof(char)*L);
    char* q=(char*)malloc(sizeof(char)*L);
    fgets(a,L,stdin); a[strlen(a)-1]='\0';
    fgets(q,L,stdin); q[strlen(q)-1]='\0';
    rabinkarp(a,q);
    free(a);
    free(q);
}

void rabinkarp(char* a,char* q){
    int j;
    int k;
    int n=strlen(a);
    int m=strlen(q);
    int c=0; // 정답열 인덱스
    int* r=(int*)calloc(n,sizeof(int)); // 정답열(등장 위치)
    int f; // 매칭 플래그
    long long int h=1; // 슬라이딩 윈도우 해시 기준값: n^(m-1)
    long long int u=0; // 원본 부분문자열 해시값
    long long int v=0; // 쿼리 문자열 해시값)
    
    // 해시값 확보
    for(j=0;j<m-1;j++){
        h*=N;
        h%=D;
    }
    for(j=0;j<m;j++){
        v=(v*N+q[j])%D;
        u=(u*N+a[j])%D;
    }

    // 슬라이딩 윈도우
    for(j=0;j<=n-m;j++){
        if(u==v){
            f=1;
            for(k=0;k<m;k++){if(a[j+k]!=q[k]){f=0; break;}} // collision
            if(f==1){r[c++]=j+1;}
        }
        if(j<n-m){
            u=(N*(u-a[j]*h)+a[j+m])%D;
            if(u<0){u+=D;}
        }
    }

    // 결과 출력
    printf("%d\n",c);
    for(j=0;j<c;j++){printf("%d ",r[j]);}
    free(r);
}
```
```
$ ./test
The Rabin-Karp algorithm is a string-searching algorithm that uses hashing to find an exact match of a pattern string int a text. It uses a rolling hash to quickly filter out positions of the text that cannot match the pattern.
hash
2
68 149 
```
