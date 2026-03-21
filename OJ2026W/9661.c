// G2 9661: 돌 게임 7(게임이론)
#include<stdio.h>

int main(void){
    long long int n; scanf("%lld",&n);
    int a[5]; // 선 승리 0, 후 승리 1
    a[1]=0; // 1
    a[2]=1; // 1 - 1
    a[3]=0; // 1 - 2
    a[4]=0; // 1 - 3, 4
    a[0]=1; // 4 - 1, 1 - 4
    if(a[n%5]==0){printf("SK");}
    else         {printf("CY");}
}