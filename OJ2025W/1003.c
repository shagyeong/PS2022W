//1003: 피보나치 함수(다이나믹 프로그래밍)
#include<stdio.h>

int main(void){
    int fib[41][2];
    fib[0][0] = 1; fib[0][1] = 0;
    fib[1][0] = 0; fib[1][1] = 1;
    for(int i = 2; i <= 40; i++){
        fib[i][0] = fib[i - 2][0] + fib[i - 1][0];
        fib[i][1] = fib[i - 2][1] + fib[i - 1][1];
    }
    int n; scanf("%d", &n);
    int t;
    for(int i = 0; i < n; i++){
        scanf("%d", &t);
        printf("%d %d\n", fib[t][0], fib[t][1]);
    }
}
