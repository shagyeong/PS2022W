// S3 15649: N과 M 1(재귀,백트래킹)
#include<stdio.h>

int a[9];
int v[9]; // 방문 상태 관리
int n;
int m;
void backtrack(int d);

int main(void){
    scanf("%d %d",&n,&m);
    backtrack(0);
}

void backtrack(int d){
    int j;
    if(d==m){for(j=0;j<m;j++){printf("%d ",a[j]);} printf("\n"); return;}

    for(j=1;j<=n;j++){
        if(v[j]==0){
            v[j]=1;
            a[d]=j;
            backtrack(d+1);
            v[j]=0;
        }
    }
}