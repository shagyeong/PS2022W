#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int j; int k;
    int n; scanf("%d",&n);
    int m=0; // 정답열(char* u) 오프셋
    int l=0; // 문자 덩어리 개수
    char* s=(char*)malloc(sizeof(char)*(n+1)); scanf("%s",s); s[n]='\0';
    char* u=(char*)malloc(sizeof(char)*(n+1)); // 정답열
    char* a=(char*)malloc(sizeof(char)*(n+1)); // 문자 덩어리 축소
    int*  b=(int*) calloc((n+1),(sizeof(int))); // 문자 덩어리별 문자 개수
    
    a[l]=s[0];
    b[l]++;

    for(j=1;j<n;j++){
        if(s[j]==s[j-1]){b[l]++;}
        else{a[++l]=s[j];b[l]++;}
    }

    for(j=0;j<l;j++){ // j<=l이 아닌 이유 j==l은 마지막 덩어리 무조건 줄임
        if(a[j]<a[j+1]){ // 뒤 덩어리보다 사전순으로 앞섬: 유지
            for(k=0;k<b[j];k++){u[m++]=a[j];}
        }
        else{
            u[m++]=a[j];
        }
    }

    // 마지막 덩어리 무조건 축소
    u[m++]=a[l]; u[m]='\0';
    printf("%s",u);

    free(s);
    free(u);
}