// B3 2720: 세탁소 사장 동혁(그리디)
#include<stdio.h>

int main(void){
    int j;
    int t; scanf("%d",&t);
    int v;
    int q=25;
    int d=10;
    int n=5;
    for(j=0;j<t;j++){
        scanf("%d",&v);
        printf("%d ",v/q); v%=q;
        printf("%d ",v/d); v%=d;
        printf("%d ",v/n); v%=n;
        printf("%d\n",v);
    }
}