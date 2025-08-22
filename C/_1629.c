//1629: 곱셈(수학, 분할 정복을 이용한 거듭제곱)
#include<stdio.h>

int main(void){
    int i = 0; int ans;
    long long a, b, c; scanf("%lld %lld %lld", &a, &b, &c);
    
    int d = a%c;    //초기 나머지
    long long buf = a;
    do{
        buf *= a;
        ans = buf % c;
        buf = ans;
        i++;
        printf("buf: %lld\n", buf);
    }while(buf != d);
    printf("i: %d\n", i);
    
    b = b%i;
    buf = 1;
    for(i = 0; i < b; i++){
        buf *= a;
        ans = buf % c;
        buf = ans;
    }
    printf("ans: %d\n", ans);
}
