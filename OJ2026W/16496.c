// P5 16496: 큰 수 만들기(정렬,문자열)
#include<stdio.h>
#include<string.h>
#include<stdlib.h> // qsort()

int compare(const void* u,const void* v); // qsort()

int main(void){
    unsigned int j;   // loop variable
    unsigned int n;
    scanf("%d",&n);
    char* a[n];
    for(j=0;j<n;j++){
        a[j]=(char*)malloc(sizeof(char)*11); // 11: 10+1, 10^9,'\0'
        scanf("%s",a[j]);
    }

    qsort(&a[0],n,sizeof(char*),compare);
    if(*(a[0])=='0'){ // 오름차순 정렬 후 번째 원소 0: 모든 원소 0, 문제 조건: 수는 0으로 시작하지 않음
        printf("0");
        return 0;
    }
    else{
        for(j=0;j<n;j++){printf("%s",a[j]);}
        return 0;
    }
}

int compare(const void* u,const void* v){
    char a[22]; // uv꼴로 이어붙인 형태
    char b[22]; // vu꼴로 이어붙인 형태
    sprintf(a,"%s%s",*((char**)u),*((char**)v));
    sprintf(b,"%s%s",*((char**)v),*((char**)u));
    return strcmp(b,a);
}