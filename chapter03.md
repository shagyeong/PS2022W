# 3장 탐색
## 3.1 정렬되어 있지 않은 자료 탐색
### 3.1.1 순차 탐색
#### 순차 탐색
```C
#include<stdio.h>

int search(int a[],int n,int q);

int main(void){
    int n=10; // number of item
    int a[10]={10,14,16,21,22,24,32,42,45,53};
    printf("index of 10: %d\n",search(a,n,10));
    printf("index of 22: %d\n",search(a,n,22));
    printf("index of 53: %d\n",search(a,n,53));
}

int search(int a[],int n,int q){
    int j;
    for(j=0;j<n;j++){if(a[j]==q){return j;}}
    return -1;
}
```
```
$ ./test
index of 10: 0
index of 22: 4
index of 53: 9
```



## 3.2 정렬된 자료 탐색
## 3.2.1 이진 탐색
#### 이진 탐색
```C
#include<stdio.h>

int search(int a[],int n,int q);

int main(void){
    int n=10; // number of item
    int a[10]={10,14,16,21,22,24,32,42,45,53};
    printf("index of 10: %d\n",search(a,n,10));
    printf("index of 22: %d\n",search(a,n,22));
    printf("index of 53: %d\n",search(a,n,53));
}

int search(int a[],int n,int q){
    int s=0;   // start
    int m;     // middle
    int e=n-1; // end
    while(s<=e){
        m=s+(e-s)/2;
        if(a[m]==q){return m;}
        if(a[m]> q){e=m-1;}
        if(a[m]< q){s=m+1;}
    }
    return -1;
}
```
```
$ ./test
index of 10: 0
index of 22: 4
index of 53: 9
```
### 3.2.2 색인 순차 탐색
#### 색인 순차 탐색
```C
#include<stdio.h>

#define S 10 // max size of index table

struct data{
    int  n;    // number of item
    int  s;    // size of index table
    int* a;    // address of array
    int  i[S]; // table of index
    int  k[S]; // table of key
};

void   init(struct data* d);
void  print(struct data* d);
void search(struct data* d,int q);

int main(void){
    int n=10;
    int s=3;
    int a[10]={10,14,16,21,22,24,32,42,45,53};
    struct data d;
    d.n=n;
    d.s=s;
    d.a=&a[0];
    init(&d);
    print(&d);

    search(&d,10);
    search(&d,22);
    search(&d,53);
}

void   init(struct data* d){
    int j;              // loop variable
    int g=(d->n)/(d->s);// gap
    for(j=0;j<d->s;j++){
        d->i[j]=j*g;
        d->k[j]=*((d->a)+j*g);
    }
}
void  print(struct data* d){
    int j; // loop variable
    printf("gap: %d\n",(d->n)/(d->s));
    for(j=0;j<d->s;j++){printf("index: %d, key: %d\n",d->i[j],d->k[j]);}
}
void search(struct data* d,int q){
    int j;              // loop variable
    int s;              // start
    int e;              // end
    s=0;
    e=d->n-1;
    for(j=0;j<d->s-1;j++){
        if((d->k[j]<=q)&&(q<d->k[j+1])){
            s=d->i[j];
            e=d->i[j+1];
            break;
        }
    }
    printf("search %d: [%d,%d]: %d~%d\t",q,s,e,d->a[s],d->a[e]);
    for(j=s;j<=e;j++){if(d->a[j]==q){printf("index: %d\n",j);return;}}
}
```
```
$ ./test
gap: 3
index: 0, key: 10
index: 3, key: 21
index: 6, key: 32
search 10: [0,3]: 10~21 index: 0
search 22: [3,6]: 21~32 index: 4
search 53: [0,9]: 10~53 index: 9
```



<!-- ## 3.3 해싱 -->
