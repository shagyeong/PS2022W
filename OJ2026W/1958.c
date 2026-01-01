// 1958: LCS 3(DP, LCS)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int lcs(char* x,char* y,char* z,int m,int n,int o);

int main(void){
    char a[100]; scanf("%s",a);
    char b[100]; scanf("%s",b);
    char c[100]; scanf("%s",c);
    char* x=&a[0]; int m=strlen(x);
    char* y=&b[0]; int n=strlen(y);
    char* z=&c[0]; int o=strlen(z);
    printf("%d",lcs(x,y,z,m,n,o));
}

int lcs(char* x,char* y,char* z,int m,int n,int o){
    int j; // loop variable
    int k; // loop variable
    int l; // loop variable
    int d; // dummy
    int t[m+1][n+1][o+1];

    for(j=0;j<=m;j++){
        for(k=0;k<=n;k++){
            for(l=0;l<=o;l++){
                t[j][k][l]=0;
            }
        }
    }
    
    for(j=1;j<=m;j++){
        for(k=1;k<=n;k++){
            for(l=1;l<=o;l++){
                if((x[j-1]==y[k-1])&&(y[k-1]==z[l-1])){
                    t[j][k][l]=t[j-1][k-1][l-1]+1;
                }
                else{
                    d=t[j-1][k][l];
                    if(d<t[j][k-1][l]){d=t[j][k-1][l];}
                    if(d<t[j][k][l-1]){d=t[j][k][l-1];}
                    t[j][k][l]=d;
                }
            }
        }
    }
    return t[m][n][o];
}