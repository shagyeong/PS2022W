//30802: 웰컴 키트(수학, 구현, 사칙연산)
#include<stdio.h>

int main(void){
    int n; scanf("%d", &n);
    int a, b, c, d, e, f; scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    int t, p; scanf("%d %d", &t, &p);
    int ans = 0;
    ans = (a % t == 0)?(ans + a / t):(ans + a / t + 1);
    ans = (b % t == 0)?(ans + b / t):(ans + b / t + 1);
    ans = (c % t == 0)?(ans + c / t):(ans + c / t + 1);
    ans = (d % t == 0)?(ans + d / t):(ans + d / t + 1);
    ans = (e % t == 0)?(ans + e / t):(ans + e / t + 1);
    ans = (f % t == 0)?(ans + f / t):(ans + f / t + 1);
    printf("%d\n", ans);
    printf("%d %d\n", n/p, n%p);
}