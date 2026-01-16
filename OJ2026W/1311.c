// G1 1311: 할 일 정하기 1(재귀,비트필드DP)
#include<stdio.h>

#define INF 1000000000
#define N 20

int n;
int c[N][N];    // cost
int a[N][1<<N]; // dp table: [p][m]: 비트필드 m으로 표현된 배정 상태에서 p번째 사람이 소모하는 비용

int f(int p,int m);

int main(void){
    int j;
    int k;
    scanf("%d",&n);
    for(j=0;j<n;j++){for(k=0;k<n;     k++){scanf("%d",&c[j][k]);}}
    for(j=0;j<n;j++){for(k=0;k<(1<<n);k++){a[j][k]=-1;}}
    printf("%d",f(0,0));
}

int f(int p,int m){
    if(p==n)       {return 0;}
    if(a[p][m]!=-1){return a[p][m];}
    int j; // loop variable
    int t; // tmp
    int r=INF;
    for(j=0;j<n;j++){
        if((m&(1<<j))==0){
            t=f(p+1,m|(1<<j))+c[p][j];
            r=(r<t)?r:t;
        }
    }
    return a[p][m]=r;
}