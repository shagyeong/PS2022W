# 3장 힙
## 3-1 더 맵게
```C
#include<stdio.h>
#include<stdlib.h>

struct heap{
    int* a;
    int  i;
};

void push(struct heap* h,int v);
int   pop(struct heap* h);

int main(void){
    int j; int l; /// loop variable
    int n; int k; scanf("%d %d",&n,&k);
    int* a=(int*)malloc(sizeof(int)*(n+1));
    int u; int v;
    struct heap h;
    h.a=&a[0];
    h.i=0;
    for(j=0;j<n;j++){scanf("%d",&v); push(&h,v);}

    l=0;
    while(h.i>=2){
        u=pop(&h); if(u>=k){break;}
        v=pop(&h);
        push(&h,u+2*v);
        l++;
    }
    if(h.i==1){
        if(pop(&h)>=k){printf("%d",l);}
        else          {printf("-1");}
    }
    else              {printf("%d",l);}
}

void push(struct heap* h,int v){
    int j;
    int t;
    h->a[++(h->i)]=v;
    j=h->i;

    while((j>1)&&(h->a[j]<h->a[j/2])){
        t=h->a[j];
        h->a[j]=h->a[j/2];
        h->a[j/2]=t;
        j/=2;
    }
}
int pop(struct heap* h){
    int r;
    int j;
    int t;
    int c;

    r=h->a[1];
    h->a[1]=h->a[(h->i)--];
    j=1;

    while(j*2<=h->i){
        c=j*2;
        if((c+1<=h->i)&&(h->a[c+1]<h->a[c])){c+=1;}
        if(h->a[j]<=h->a[c]){break;}
        t=h->a[j];
        h->a[j]=h->a[c];
        h->a[c]=t;
        j=c;
    }
    return r;
}
```
```
$ ./test
6 7
1 2 3 9 10 12
2
```
## 3-2 디스크 컨트롤러
```C
```
```
```
## 3-3 이중우선순위큐
```C
```
```
```
