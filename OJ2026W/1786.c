// P5 1786: 찾기(문자열,KMP)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define L 1000002 // +2: '\n', '\0'(fgets: 공백 포함 문자열 대응)

void kmp(char* a,char* q);

int main(void){
    char* a=(char*)malloc(sizeof(char)*L);
    char* q=(char*)malloc(sizeof(char)*L);
    fgets(a,L,stdin); a[strlen(a)-1]='\0';
    fgets(q,L,stdin); q[strlen(q)-1]='\0';
    kmp(a,q);
    free(a);
    free(q);
}

void kmp(char* a,char* q){
    int j;
    int k;
    int n=strlen(a);
    int m=strlen(q);
    int c=0; // 등장 횟수
    int* r=(int*)calloc(n,sizeof(int)); // 등장 위치
    int* f=(int*)calloc(m,sizeof(int)); // 실패함수

    // 실패함수
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
            if(k==m-1){r[c++]=j-m+2; k=f[k];} // 매치
            else      {              k++;}
        }
    }

    // 결과 출력
    printf("%d\n",c);
    for(j=0;j<c;j++){printf("%d ",r[j]);}
    free(r);
    free(f);
}