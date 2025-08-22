//11050: 이항 계수 1(수학, 구현, 조합론)
#include<stdio.h>
int main(void){
    int n, k; scanf("%d %d", &n, &k);
    int ans = 1;
    for(int i = 0; i <k; i++){ans *= n - i;}
    for(int i = 1; i <= k; i++){ans /= i;}
    printf("%d", ans);
}