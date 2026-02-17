// S2 15663: N과 M 9(재귀,백트래킹)
#include<stdio.h>
#include<stdlib.h>

int a[9]; // 원본 배열
int t[9];
int v[9]; // 방문 상태 관리
int n;
int m;
int asc(const void* u,const void* v);
void backtrack(int d);

int main(void){
    int j;
    scanf("%d %d",&n,&m);
    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    for(j=n;j<9;j++){a[j]=10001;} // INF
    qsort(a,n,sizeof(int),asc);
    backtrack(0);
}

int asc(const void* u,const void* v){
    return *((int*)u)-*((int*)v);
}

void backtrack(int d){
    int j;
    int p=-1; // prev
    if(d==m){for(j=0;j<m;j++){printf("%d ",t[j]);} printf("\n"); return;}

    for(j=0;j<n;j++){
        if((v[j]==0)&&(a[j]!=p)){
            v[j]=1;
            p=a[j];
            t[d]=a[j];
            backtrack(d+1);
            v[j]=0;
        }
    }
}