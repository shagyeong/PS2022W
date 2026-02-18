// S1 10844: 쉬운 계단 수(DP)
#include<stdio.h>
#include<stdlib.h>

#define D 1000000000

int main(void){
    int j; int k=0;
    int a=0; // answer
    int n; scanf("%d",&n);
    int** t=(int**)malloc(sizeof(int*)*(n+1));
    int*  d=(int*) malloc(sizeof(int)* (n+1)*10);
    for(j=0;j<=n;j++){t[j]=d+k;k+=10;}
    for(j=1;j<10;j++){t[1][j]=1;}
    t[1][0]=0;
    for(j=2;j<=n;j++){
        t[j][0]=t[j-1][1];
        t[j][9]=t[j-1][8];
        for(k=1;k<9;k++){
            t[j][k]=t[j-1][k-1]+t[j-1][k+1];
            t[j][k]%=D;
        }
    }
    for(j=0;j<10;j++){
        a+=t[n][j];
        a%=D;
    }
    printf("%d",a);
    free(d);
    free(t);
}