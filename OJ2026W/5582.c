// G5 5582: 공통 부분 문자열(LCS)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int j;
    int k=0;
    char* u=(char*)malloc(sizeof(char)*4001); scanf("%s",u);
    char* v=(char*)malloc(sizeof(char)*4001); scanf("%s",v);
    int n=strlen(u);
    int m=strlen(v);
    int l=0; // length of (current) LCS
    int** t=(int**)malloc(sizeof(int*)*(n+1));
    int*  d=(int*) malloc(sizeof(int) *(n+1)*(m+1));
    for(j=0;j<=n;j++){t[j]=d+k; k+=(m+1);}
    for(j=0;j<=n;j++){t[j][0]=0;}
    for(j=0;j<=m;j++){t[0][j]=0;}

    for(j=1;j<=n;j++){
    for(k=1;k<=m;k++){
        if(u[j-1]==v[k-1]){
            t[j][k]=t[j-1][k-1]+1;
            if(l<t[j][k]){l=t[j][k];}
        }
        else{t[j][k]=0;}
    }}

    printf("%d",l);
    free(u); free(v);
    free(d); free(t);
}