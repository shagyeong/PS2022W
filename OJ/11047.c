//11047: 동전 0(그리디 알고리즘)
#include<stdio.h>

int main(void){
    int ans = 0;
    int i;
    int n, k; scanf("%d %d", &n, &k);
    int value[n]; for(i = n - 1; i >= 0; i--){scanf("%d", &value[i]);}
    for(i = 0; i < n; i++){
        if(k == 0){break;}
        if(value[i] <= k){
            ans += k / value[i];
            k %= value[i];
        }
    }
    printf("%d", ans);
}
