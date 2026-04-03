// S5 1676: 팩토리얼 0의 개수()
#include<stdio.h>

int main(void){
    int j;
    int d;
    int a=0; // 2^a
    int b=0; // 5^b
    int n; scanf("%d",&n);
    for(j=2;j<=n;j+=2){d=j;while(d%2==0){d/=2; a++;}}
    for(j=5;j<=n;j+=5){d=j;while(d%5==0){d/=5; b++;}}
    printf("%d",(a<b)?a:b);
}