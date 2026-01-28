// B1 2775: 부녀회장이 될테야(DP)
#include<stdio.h>

int main(void){
    int j; int l; // loop variable
    int t[15][15];
    int m; scanf("%d",&m);
    int k; int n;

    for(j=0;j<=14;j++){t[0][j]=j;t[j][0]=0;}
    for(j=1;j<=14;j++){
    for(l=1;l<=14;l++){
        t[j][l]=t[j][l-1]+t[j-1][l];
    }}

    for(j=0;j<m;j++){
        scanf("%d %d",&k,&n);
        printf("%d\n",t[k][n]);
    }
}