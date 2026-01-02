// G2 1398: 동전 문제(DP, 그리디)
#include<stdio.h>

unsigned long long int change(unsigned long long int p);

int main(void){
    unsigned short j; // loop variable
    unsigned short n; // number of test case
    unsigned long long int p; // price
    scanf("%hu",&n);
    for(j=0;j<n;j++){
        scanf("%llu",&p);
        printf("%llu\n",change(p));
    }
}

unsigned long long int change(unsigned long long int p){
    unsigned long long int a=0;   // answer(동전 개수)
    unsigned char Q[100]={
        0,1,2,3,4,5,6,7,8,9,
        1,2,3,4,5,6,7,8,9,10,
        2,3,4,5,6,1,2,3,4,5,
        3,4,5,6,7,2,3,4,5,6,
        4,5,6,7,8,3,4,5,6,7,
        2,3,4,5,6,4,5,6,7,8,
        3,4,5,6,7,5,6,7,8,9,
        4,5,6,7,8,3,4,5,6,7,
        5,6,7,8,9,4,5,6,7,8,
        6,7,8,9,10,5,6,7,8,9
    };
    while(p>0){
        a+=Q[p%100];
        p/=100;
    }
    return a;
}

// DP 테이블
// unsigned short j; // loop variable
// unsigned short v; // value dummy
// unsigned short l; // quotient dummy 1
// unsigned short r; // quotient dummy 2
    
// unsigned char q[100];
// q[0]=0; q[1]=1; q[2]=2; q[3]=3; q[4]=4;
// q[5]=5; q[6]=6; q[7]=7; q[8]=8; q[9]=9;
// q[10]=1;q[11]=2;q[12]=3;q[13]=4;q[14]=5;
// q[15]=6;q[16]=7;q[17]=8;q[18]=9;q[19]=10;
// q[20]=2;q[21]=3;q[22]=4;q[23]=5;q[24]=6;
// for(j=25;j<=95;j+=5){
//     // 동전 25 사용 횟수 q
//     v=j; l=0;
//     l+=v/25; v%=25;
//     l+=v/10; v%=10;
//     l+=v;
//     // 동전 25 사용 횟수 q-1
//     v=j; r=0;
//     r+=(v/25)-1; v-=25*r;
//     r+=v/10;     v%=10;
//     r+=v;
    
//     q[j]=(l<r)?l:r;
//     q[j+1]=q[j]+1; // 동전 1 사용
//     q[j+2]=q[j]+2;
//     q[j+3]=q[j]+3;
//     q[j+4]=q[j]+4;
// }