// B2 2231: 분해합(브루트포스)
#include<stdio.h>

int main(void){
    int j; int k;
    int n; scanf("%d",&n);
    int m;
    for(j=1;j<=n;j++){
        k=j;
        m=k;
        m+=(k/1000000); k%=1000000;
        m+=(k/100000);  k%=100000;
        m+=(k/10000);   k%=10000;
        m+=(k/1000);    k%=1000;
        m+=(k/100);     k%=100;
        m+=(k/10);      k%=10;
        m+=k;
        if(m==n){printf("%d",j); return 0;}
    }
    printf("0");
    return 0;    
}