# 4장 정렬
## 4-1 K번째수
```C
#include<stdio.h>
#include<stdlib.h>

int compare(const void* u,const void* v){
    if((*((int*)u))<(*((int*)v))){return -1;}
    if((*((int*)u))>(*((int*)v))){return  1;}
    return 0;
}

int main(void){
    int l;
    int n;
    int i; int j; int k;
    scanf("%d",&n);
    scanf("%d %d %d",&i,&j,&k);
    i-=1; j-=1; k-=1; // 1부터 시작하는 과제 환경

    int* a=(int*)malloc(sizeof(int)*n);
    int* b=(int*)malloc(sizeof(int)*(j-i+1));
    for(l=0;l<n; l++){scanf("%d",&a[l]);}
    for(l=i;l<=j;l++){b[l-i]=a[l];}

    qsort(&b[0],j-i+1,sizeof(int),compare);
    printf("%d",b[k]);
}
```
```
$ ./test
7
2 5 3
1 5 2 6 3 7 4
5

$ ./test
7
4 4 1
1 5 2 6 3 7 4
6

$ ./test
7
1 7 3
1 5 2 6 3 7 4
3
```
## 4-2 가장큰수
```C
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compare(const void* u,const void* v){
    char a[10]; // uv꼴로 이어붙인 형태
    char b[10]; // vu꼴로 이어붙인 형태
    sprintf(a,"%s%s",*((char**)u),*((char**)v));
    sprintf(b,"%s%s",*((char**)v),*((char**)u));
    return strcmp(b,a);
}

int main(void){
    int j;
    int n; scanf("%d",&n);
    char* a[n];
    for(j=0;j<n;j++){
        a[j]=(char*)malloc(sizeof(char)*5); // 4자리수, '\0'
        scanf("%s",a[j]);
    }

    qsort(&a[0],n,sizeof(char*),compare);
    if(*(a[0])=='0'){printf("0");}
    else{for(j=0;j<n;j++){printf("%s",a[j]);}}
}
```
```
$ ./test
3
6 10 2
6210

$ ./test
5
3 30 34 5 9
9534330
```
## 4-3 H-Index
```C
#include<stdio.h>
#include<stdlib.h>

int compare(const void* u,const void* v){
    if((*((int*)u))>(*((int*)v))){return -1;}
    if((*((int*)u))<(*((int*)v))){return  1;}
    return 0;
}

int main(void){
    int j;
    int n; scanf("%d",&n);
    int* a=(int*)malloc(sizeof(int)*n); for(j=0;j<n;j++){scanf("%d",&a[j]);}
    qsort(&a[0],n,sizeof(int),compare);

    for(j=0;j<n;j++){if(a[j]<j+1){break;}}
    printf("%d",j);
}
```
```
$ ./test
5
3 0 6 1 5
3
```
