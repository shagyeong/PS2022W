//28127: 숫자탑과 쿼리(수학, 이분 탐색, 사칙연산)
#include<stdio.h>

int main(void){
    int i, j, k;
    int a, d, x;

    int q = 1;  //n층의 첫 번째 수

    int n; scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d %d %d", &a, &d, &x);
        if(x <= a){
            printf("%d %d\n", 1, x);
        }
        else{
            j = 1; q = 0;
            while(x >= q){
                j++;
                q = a*(j-1) + d*(j-1)*(j-2)/2 + 1;
                
            }
            j--; q = a*(j-1) + d*(j-1)*(j-2)/2 + 1;
            printf("%d %d\n", j, x - q + 1);
        }
    }
}
//n층의 첫번째 수
//1층: 1
//n층: an + dn(n - 1) / 2