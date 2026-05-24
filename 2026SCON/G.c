#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int j; int k;
    int t; // 신뢰도
    int c; // credit
    int s; // 긴급 패치 누적 비용
    int n; int b; scanf("%d %d",&n,&b);
    int* a=(int*)malloc(sizeof(int)*n);
    for(j=0;j<n;j++){scanf("%d",&a[j]);}

    int l=0;
    int m;
    int r=2100000000;

    while(l<r){
        m=l+(r-l)/2;
         // 신뢰도 이분탐색
        printf("%d\n", m);
        s=0;
        c=0; // 문제 조건: credit 초기값 0
        for(j=0;j<n;j++){
            if(a[j]>=m){c++;}
            else       {c--;}

            if(c<0){ // 긴급 패치
                s+=(m-a[j]);
                c++;
            }
        }

        if(s>b) {r=m;}
        if(s<=b){l=m+1; t=m;}
    }

    printf("%d\n",t);
}