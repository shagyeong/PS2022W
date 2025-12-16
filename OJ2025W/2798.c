//2798: 블랙잭(브루트포스 알고리즘)
#include<stdio.h>
int main(void){
    int i, j, k;
    int n, m; scanf("%d %d", &n, &m);
    int arr[n]; for(i = 0; i < n; i++){scanf("%d", &arr[i]);}
    
    int buf; int ans = 0;

    for(i = 0; i < n - 2; i++){
        for(j = i + 1; j < n - 1; j++){
            for(k = j + 1; k < n; k++){
                buf = arr[i] + arr[j] + arr[k];
                ans = (buf <= m && buf >= ans)?buf:ans;
            }
        }
    }
    printf("%d", ans);   
}
