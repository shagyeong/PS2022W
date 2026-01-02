// B2 5585: 거스름돈(그리디)
#include<stdio.h>

int main(void){
    short a=0;
    short m;
    scanf("%hd",&m);
    m=1000-m;
    a+=m/500; m%=500;
    a+=m/100; m%=100;
    a+=m/50;  m%=50;
    a+=m/10;  m%=10;
    a+=m/5;   m%=5;
    a+=m/1;   m%=1;
    printf("%d",a);
}