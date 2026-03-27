// G4 1091: 카드 섞기(구현,시뮬레이션)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; scanf("%d",&n);
    int c=0; // clock
    int f;   // flag

    int* a=(int*)malloc(sizeof(int)*n); for(j=0;j<n;j++){a[j]=j;} // 원본 배열: 0,1,2,...n-1
    int* t=(int*)malloc(sizeof(int)*n); // tmp
    int* p=(int*)malloc(sizeof(int)*n); for(j=0;j<n;j++){scanf("%d",&p[j]);} // 0, 1, 2로만 이루어진 분배 방법
    int* s=(int*)malloc(sizeof(int)*n); for(j=0;j<n;j++){scanf("%d",&s[j]);} // 셔플

    while(1){
        // 분배 결과 확인
        f=1;
        for(j=0;j<n;j++){if((j%3)!=p[a[j]]){f=0; break;}}
        if(f==1){printf("%d",c);goto success;}
        
        // 사이클 탐지
        if(c!=0){
            f=0;
            for(j=0;j<n;j++){if(a[j]!=j){f=1; break;}}
            if(f==0){goto fail;}
        }
        
        // 셔플
        for(j=0;j<n;j++){t[j]=a[j];}
        for(j=0;j<n;j++){a[s[j]]=t[j];}
        c++;
    }

    fail:
        printf("-1");

    success:
        free(a);
        free(t);
        free(p);
        free(s);
}