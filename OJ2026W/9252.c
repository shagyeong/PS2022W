// 9252: LCS2(DP, LCS)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int lcs(char* x,char* y,char* p,int m,int n);

int main(void){
    char a[1000]; scanf("%s",a);
    char b[1000]; scanf("%s",b);
    char c[1000]; // 역추적
    char* x=&a[0]; int m=strlen(x);
    char* y=&b[0]; int n=strlen(y);
    char* p=&c[0];
    int l; // length
    l=lcs(x,y,p,m,n);
    printf("%d",l);
    if(l!=0){printf("\n%s",p);}
}

int lcs(char* x,char* y,char* p,int m,int n){
    int j; // loop variable
    int k; // loop variable
    int d; // table value dummy
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
    // 역추적 결과 저장: char* p
    for(j=0;j<t[m][n];j++){p++;}
    *p='\0'; p--;
    
    j=m; k=n;
    while((j>=1)&&(k>=1)){
        d=t[j][k];
        if((d>t[j-1][k-1])&&(d>t[j-1][k])&&(d>t[j][k-1])){*p=x[j-1]; p--; j--; k--;}
        else if((d==t[j][k-1])&&(d>t[j-1][k])){                                k--;}
        else{                                                             j--;     }
    }
    return t[m][n];
}