// G5 2225: 합분해(DP,조합론)
// combination(n+i-1,n)
#include<stdio.h>
#include<stdlib.h>

# define D 1000000000 // divisor

int main(void){
    int j; int k;
    int n; int i; scanf("%d %d",&n,&i);
    int m=n+i-1;
    int** comb=(int**)malloc(sizeof(int*)*(m+1));
    int*  data=(int*) malloc(sizeof(int) *(m+1)*(m+1));
    k=0;
    for(j=0;j<=m;j++){
        comb[j]=data+k; k+=m;
        comb[j][0]=1;
        comb[j][j]=1;
    }
    for(j=2;j<=m;j++){
        for(k=1;k<j;k++){
            comb[j][k]=comb[j-1][k-1]+comb[j-1][k];
            comb[j][k]%=D;
        }
    }
    printf("%d",comb[m][n]);
    free(data);
    free(comb);
}