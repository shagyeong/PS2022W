// B2 15995: 잉여역수 구하기(모듈로곱셈역원)
#include<stdio.h>

int inverse(int n,int d);

int main(void){
    int n; int d; scanf("%d %d",&n,&d);
    int i=inverse(n,d);
    printf("%d",i);
}

int inverse(int n,int d){
    int a=d;
    int b=n;
    int h=0; // 이전 단계
    int i=1;
    int t;
    while(a%b!=0){
        t=h-(a/b)*i;
        h=i;
        i=t;
        t=a; a=b; b=t%b; // 유클리드 호제법
    }
    if(i<0){i+=d;}
    return i;
}