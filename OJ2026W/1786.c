// P5 1786: 찾기(문자열,KMP)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 1000002 // +2: \n, \0

void kmp(char* a,char*q);

int main(void){
    char* a=(char*)malloc(sizeof(char)*(N));
    char* q=(char*)malloc(sizeof(char)*(N));
    fgets(a,N,stdin); a[strlen(a)-1]='\0';
    fgets(q,N,stdin); q[strlen(q)-1]='\0';
    kmp(a,q);
}

void kmp(char* a,char* q){
    int j; int k;
    int n=strlen(a);
    int m=strlen(q);
    int c=0; // 등장 횟수
    int* r=(int*)malloc(sizeof(int)*n); // 결과 저장 배열
    int* f=(int*)malloc(sizeof(int)*m); // 실패 배열
    for(j=0;j<m;j++){f[j]=0;}

    // 실패 배열
    k=0;
    for(j=1;j<m;j++){
        while((k>0)&&(q[j]!=q[k])){k=f[k-1];}
        if(q[j]==q[k]){f[j]=++k;}
    }
    
    // 매칭
    k=0;
    for(j=0;j<n;j++){
        while((k>0)&&(a[j]!=q[k])){k=f[k-1];}
        if(a[j]==q[k]){
            if(k==m-1){
                r[c++]=j-m+2;
                k=f[k];
            }
            else{
                k++;
            }
        }
    }

    // 결과 출력
    printf("%d\n",c);
    for(j=0;j<c;j++){printf("%d ",r[j]);}
}
