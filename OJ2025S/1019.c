// 1019: 책 페이지(수학, 구현)
#include<stdio.h>

int main(void){
    int ans = 0;
    
    int i[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int j = 0;

    int w = 1;  // weight: power of 10
    int d;       // n의 각 자릿수
    int n; scanf("%d", &n);

    // 0으로 시작할 수 없음: 별도 처리
    loop0:
        d = n / w % 10;
        ans += (n / (w * 10)) * w;
        if(0 < d){ans += w;}
        else if(0 == d){ans += (n % w) + 1;}
        // else: 0 > d -> ans += 0
        ans -= w;   // 000...00 형태 차감
        if((w *= 10) * 10 <= n){goto loop0;}    // 최상위 자릿수 처리 없음
        printf("%d ", ans);

    w = 1; ans = 0;

    assign:
    loop:
        d = n / w % 10;
        ans += (n / (w * 10)) * w;
        if(i[j] < d){ans += w;}
        else if(i[j] == d){ans += (n % w) + 1;}
        // else: i[j] > d -> ans += 0
        if((w *= 10) <= n){goto loop;}
        printf("%d ", ans);
        if(++j < 9){ans = 0; w = 1; goto assign;}
}
