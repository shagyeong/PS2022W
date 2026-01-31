// R5 30000: Byte Festival()
// 0: 문자열
// 1: 정수론(콜라츠수열)
// 2: 
// 3: 
// 4: 
// 5: 
// 6: DP(피보나치수),선형대수(다항식 계수)
// 7: 
// 8: 
// 9: 
#include<stdio.h>
#include<stdlib.h>

#define _6D2 1000000007 // divisor
#define _6D3 73939133 // divisor

void _1_print(__int128 n); // 128비트 정수 출력
void _61(void); // 등차수열
void _62(void); // 등차수열, 피보나치 수열, 6차함수
void _63(void); // 이차함수, 지수함수, 육차함수

int main(void){
    int X; scanf("%d",&X);
    if(X==0){
        printf("BOJ 30000\n");
    }
    if(X==1){
        __int128 n=989345275647;
        while(1){
            _1_print(n); if(n==1){break;}
            if(n%2==0){n/=2;}
            else      {n*=3; n++;}
        }
    }
    if(X==2){return 0;}
    if(X==3){return 0;}
    if(X==4){return 0;}
    if(X==5){return 0;}
    if(X==6){
        // _61();
        // _62();
        _63();
    }
    if(X==7){return 0;}
    if(X==8){return 0;}
    if(X==9){return 0;}
}

void _1_print(__int128 n){
    char a[40];
    int i=39; a[i--]='\0';
    while(n>0){
        a[i--]=(char)((n%10)+'0');
        n/=10;
    }
    i++; printf("%s\n",&a[i]);
}
void _61(void){
    int j;
    int g; int h;
    printf("f(x) = 8, g(x) = 2x, h(x) = ?g(x)\n");
    g=2; h=3;
    for(j=0;j<30000;j++){
        printf("8 %d %d\n",g,h);
        g+=2;
        h+=3;
    }
}
void _62(void){
    int j;
    int f=305431077;
    long long int t;
    int* g=(int*)malloc(sizeof(int)*30000);
    int* h=(int*)malloc(sizeof(int)*30000);
    g[0]=1; g[1]=1;
    h[0]=1; h[1]=10; h[2]=100; h[3]=1000; h[4]=10000; h[5]=100000;

    printf("f(x) = f(x-1)+?, g(x) = ?g(x-1)+?g(x-2), h(x) = ?h(x-1)+?h(x-2)+?h(x-3)+?h(x-4)+?h(x-5)+?h(x-6)\n");
    printf("9099099909999099999 1 1\n");
    printf("305431077 1 10\n");

    for(j=2;j<6;j++){
        f=(f+30000);
        g[j]=g[j-2]+g[j-1];
        printf("%d %d %d\n",f,g[j],h[j]);
    }

    for(j=6;j<30000;j++){
        f=(f+30000)%_6D2;
        g[j]=(g[j-2]+g[j-1])%_6D2;
        t=(
            (long long int)h[j-1]*1+
            (long long int)h[j-2]*6+
            (long long int)h[j-3]*2+
            (long long int)h[j-4]*8+
            (long long int)h[j-5]*9+
            (long long int)h[j-6]*1
        );
        h[j]=(int)(t%_6D2);
        printf("%d %d %d\n",f,g[j],h[j]);
    }
}
// void _63(void){
//     int j;
//     long long int f;
//     long long int g=64788881;
//     printf("f(x) = ?x^2+?x+?, g(x) = ?^f(x), h(x) = ?x^6+?x^5+?x^4+?x^3+?x^2+?x+?\n");
//     printf("1368 64788881 40008072\n");
//     for(j=2;j<=30000;j++){
//         f=(long long int)123*j*j+456*j+789; f%=_6D3;
//         g=(f*f*f)%_6D3;
//         printf("%lld %lld %d\n",f,g,0);
//     }
//     return;
// }