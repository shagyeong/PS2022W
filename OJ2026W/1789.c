// S5 1789: 수들의 합(그리디)
#include<stdio.h>

int main(void){
    unsigned int n; scanf("%u",&n);
    unsigned int m=0;
    unsigned int a=0; // answer: 횟수
    unsigned int i=1;
    while(1){
        if(m+i      ==n)             {a+=1; break;}
        if(m+i+(i+1)==n)             {a+=2; break;}
        if(m+i+(i+1)> n||m+i+(i+1)<m){a+=1; break;} // unsigned 오버플로우 탈출
        m+=i;
        i+=1;
        a+=1;
    }
    printf("%u",a);
}