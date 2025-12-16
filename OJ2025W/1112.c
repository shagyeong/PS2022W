//1112: 진법 변환(수학, 구현, 정수론)
#include<stdio.h>
int main(void){
    int n, b; scanf("%d %d", &n, &b);
    int ans[30]; int length = 0;
    
    int sign = (n < 0 && b > 0)?0:1;
    n = (n < 0 && b > 0)?(-n):n;


    do{
        if(n % b < 0){
            ans[length++] = (n % b) - b;
            n /= b; n += 1;
        }
        else{
            ans[length++] = n % b;
            n /= b;
        }
    }while(n != 0);
    if(sign == 0){
        printf("-");
    }
    for(int i = length - 1; i >= 0; i--){
        printf("%d", ans[i]);
    }
}
