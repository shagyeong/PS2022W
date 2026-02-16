// S1 1932: 정수 삼각형(DP)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j; int k;
    int n; scanf("%d",&n);
    int m; // min
    int** p=(int**)malloc(sizeof(int*)*n);
    int*  d=(int*) malloc(sizeof(int) *n*n);
    for(j=0;j<n;j++){p[j]=d+(j*n);}
    scanf("%d",&p[0][0]);

    for(j=1;j<n;j++){
        scanf("%d",&p[j][0]); p[j][0]+=p[j-1][0];
        for(k=1;k<j;k++){
            scanf("%d",&p[j][k]);
            p[j][k]+=(p[j-1][k-1]>p[j-1][k])?(p[j-1][k-1]):(p[j-1][k]);
        }
        scanf("%d",&p[j][j]); p[j][j]+=p[j-1][j-1];
    }
    m=p[n-1][0];
    for(j=1;j<n;j++){m=(m>p[n-1][j])?m:p[n-1][j];}
    printf("%d",m);

    free(d);
    free(p);
}