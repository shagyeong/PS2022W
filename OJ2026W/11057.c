// S1 11057: 오르막 수(DP)
#include<stdio.h>
#include<stdlib.h>

#define D 10007 // divisor

int main(void){
    int j; int k;
    int n; scanf("%d",&n); if(n==1){printf("10"); return 0;}
    int** t=(int**)calloc(n+1,     sizeof(int*));
    int*  d=(int*) calloc((n+1)*10,sizeof(int));
    k=0;
    for(j=1;j<=n;j++){t[j]=d+k; k+=10;}
    for(j=0;j<10;j++){t[1][j]=1;}
    for(j=2;j<=n;j++){
        t[j][0]=1;
        for(k=1;k<10;k++){
            t[j][k]=t[j][k-1]+t[j-1][k];
            t[j][k]%=D;
        }
    }

    k=0;
    for(j=0;j<10;j++){
        k+=t[n][j];
        k%=D;
    }
    printf("%d",k);
    free(d);
    free(t);
    return 0;
}