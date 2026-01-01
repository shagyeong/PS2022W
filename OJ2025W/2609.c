//2069: 최대공약수와 최소공배수(수학, 정수론, 유클리드 호제법)
#include<stdio.h>

int main(void){
    unsigned int a, b, c, d, e; scanf("%d %d", &a, &b);
    if(a < b){c = a; a = b; b = c;} //b > a인 상태를 유지
    c = a; d = b;
    while(c % d != 0){
        e = c;
        c = d;
        d = e % d;
    }
    printf("%d\n", d);
    printf("%d\n", a * b / d);
}
