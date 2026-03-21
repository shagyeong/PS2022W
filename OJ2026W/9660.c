// G5 9660: 돌 게임 6(게임이론)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    long long int n; scanf("%lld",&n);
    int a[7]; // 선 승리 0, 후 승리 1
    a[1]=0;
    a[2]=1;
    a[3]=0;
    a[4]=0;
    a[5]=0; // 3 - 1 - 1
    a[6]=0; // 4 - 1 - 1
    a[7]=1; // 1 - 4 - 1 - 1, 3 - 4, 4 - 3
    if(a[n%7]==0){printf("SK");}
    else         {printf("CY");}
}