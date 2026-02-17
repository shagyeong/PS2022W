// S3 15657: N과 M 8(재귀, 백트래킹)
#include<stdio.h>
#include<stdlib.h>

int a[9]; // 원본 배열
int t[9];
int n;
int m;
int asc(const void* u,const void* v);
void backtrack(int d,int s);

int main(void){
    int j;
    scanf("%d %d",&n,&m);
    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    for(j=n;j<9;j++){a[j]=10001;} // INF
    qsort(a,n,sizeof(int),asc);
    backtrack(0,1);
}

int asc(const void* u,const void* v){
    return *((int*)u)-*((int*)v);
}
void backtrack(int d,int s){
    int j;
    if(d==m){for(j=0;  j<m;j++){printf("%d ",t[j]);} printf("\n");}
    else    {for(j=s-1;j<n;j++){t[d]=a[j]; backtrack(d+1,j+1);}}
}