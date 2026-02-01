# 5장 브루트포스
## 5-1 최소직사각형
```C
#include<stdio.h>
#include<stdlib.h>

int solve(int** a,int r,int c);

int main(void){
    int j;
    int r; scanf("%d",&r);
    int c=2;
    int** a=(int**)malloc(sizeof(int*)*r);
    for(j=0;j<r;j++){
        a[j]=(int*)malloc(sizeof(int)*c);
        scanf("%d %d",&a[j][0],&a[j][1]);
    }

    printf("%d",solve(a,r,c));
}

int solve(int** a,int r,int c){ // c: unused parameter
    int j;
    int t; // tmp: swap
    int w=1; // answer
    int m=0; // max
    for(j=0;j<r;j++){
        if(a[j][0]>a[j][1]){
            t=a[j][0];
            a[j][0]=a[j][1];
            a[j][1]=t;
        }
    }
    for(j=0;j<r;j++){m=(a[j][0]>m)?a[j][0]:m;} w*=m; m=0;
    for(j=0;j<r;j++){m=(a[j][1]>m)?a[j][1]:m;} w*=m;
    return w;
}
```
```
$ ./test
4
60 50
30 70
60 30
80 40
4000
```
## 5-2 모의고사
```C
#include<stdio.h>
#include<stdlib.h>

void solve(int* a,int n);

int main(void){
    int j;
    int n; scanf("%d",&n);
    int* a=(int*)malloc(sizeof(int)*n);
    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    solve(a,n);
}

void solve(int* a,int n){
    int j; // loop variable
    int i; // index
    int x=0; // score of a
    int y=0; // score of b
    int z=0; // score of c
    int m; // max

    // lcm(5,8,10)=40
    int p[40]={1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};
    int q[40]={2,1,2,3,2,4,2,5,2,1,2,3,2,4,2,5,2,1,2,3,2,4,2,5,2,1,2,3,2,4,2,5,2,1,2,3,2,4,2,5};
    int r[40]={3,3,1,1,2,2,4,4,5,5,3,3,1,1,2,2,4,4,5,5,3,3,1,1,2,2,4,4,5,5,3,3,1,1,2,2,4,4,5,5};

    for(j=0;j<n;j++){
        i=j%40;
        x=(p[i]==a[j])?(x+1):x;
        y=(q[i]==a[j])?(y+1):y;
        z=(r[i]==a[j])?(z+1):z;
    }

    m=x;
    m=(m<y)?y:m;
    m=(m<z)?z:m;
    if(x==m){printf("1 ");}
    if(y==m){printf("2 ");}
    if(z==m){printf("3 ");}
}

```
```
$ ./test
5
1 2 3 4 5
1 
$ ./test
5
1 3 2 4 2
1 2 3 
```