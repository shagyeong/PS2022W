// 9251: LCS(DP, LCS)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int lcs(char* x,char* y,int m,int n);

int main(void){
    char a[1000]; scanf("%s",a);
    char b[1000]; scanf("%s",b);
    char* x=&a[0]; int m=strlen(x);
    char* y=&b[0]; int n=strlen(y);
    printf("%d",lcs(x,y,m,n));
}

int lcs(char* x,char* y,int m,int n){
    int j; // loop variable
    int k; // loop variable
    int t[m+1][n+1];
    for(j=0;j<=m;j++){t[j][0]=0;}
    for(j=0;j<=n;j++){t[0][j]=0;}
    for(j=1;j<=m;j++){
        for(k=1;k<=n;k++){
            if(x[j-1]==y[k-1]){
                t[j][k]=t[j-1][k-1]+1;
            }
            else{
                if(t[j][k-1]>t[j-1][k]){t[j][k]=t[j][k-1];}
                else{                   t[j][k]=t[j-1][k];}
            }
        }
    }
    return t[m][n];
}