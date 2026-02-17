// S2 15665: N과 M 11(재귀,백트래킹)
#include<stdio.h>
#include<stdlib.h>

int a[9]; // 원본 배열
int u[9]; // 중복값 제거
int t[9];
int n;
int m;
int asc(const void* u,const void* v);
void backtrack(int d);

int main(void){
    int j;
    int i; // 중복값 제거 배열 인덱스
    scanf("%d %d",&n,&m);
    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    for(j=n;j<9;j++){a[j]=10001;} // INF
    qsort(a,n,sizeof(int),asc);
    
    // 중복값 제거
    i=0;
    u[i++]=a[0];
    for(j=1;j<n;j++){
        if(a[j]!=a[j-1]){u[i++]=a[j];}
    }
    n=i;
    backtrack(0);
}

int asc(const void* u,const void* v){
    return *((int*)u)-*((int*)v);
}
void backtrack(int d){
    int j;
    if(d==m){for(j=0;j<m;j++){printf("%d ",t[j]);} printf("\n"); return;}
    else    {for(j=0;j<n;j++){t[d]=u[j];backtrack(d+1);}}
}