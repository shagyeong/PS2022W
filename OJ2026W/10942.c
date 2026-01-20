// G4 10942: 팰린드롬?(DP)
#include<stdio.h>
#include<stdlib.h>

int* a;
int** t; // DP table

void init(int n); // DP 테이블 작성

int main(void){
    int j;
    int n;
    int m;
    int u; int v;

    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    init(n);

    scanf("%d",&m);
    for(j=0;j<m;j++){
        scanf("%d %d",&u,&v);
        printf("%d\n",t[u][v]);
    }
}

void init(int n){
    int j; int k; int l; // loop variable
    t=(int**)malloc(sizeof(int*)*(n+1)); // n+1: 1부터 시작하는 과제 환경
    for(j=1;j<=n;j++){t[j]=(int*)calloc((n+1),sizeof(int));}
    
    for(j=1;j<=n;j++){t[j][j]=1;}
    for(j=1;j<n;j++){if(a[j-1]==a[j]){t[j][j+1]=1;}}
    for(j=3;j<=n;j++){
    for(k=1;k<=n-j+1;k++){
        l=k+j-1;
        if((a[k-1]==a[l-1])&&(t[k+1][l-1]==1)){t[k][l]=1;}
    }}
}