// 11727: 2xn 타일링 2
#include<stdio.h>

int main(void){
    int n; scanf("%d", &n);
    int i;
    int ans[1000]; ans[0]=1; ans[1]=3;
    for(i = 2; i < n; i++){
        ans[i]=(ans[i-2]*2+ans[i-1])%10007;
    }
    printf("%d", ans[n-1]);
}
