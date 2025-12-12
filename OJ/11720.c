//11720: 숫자의 합(수학, 구현, 문자열)
#include<stdio.h>
int main(void){
    int i;
    int n; scanf("%d", &n);
    int ans = 0; char c;
    //'둘째 줄에' 입력되어 개행 문자 입력횟수를 고려해야 함
    for(i = 0; i <= n; i++){
        scanf("%c", &c);
        switch(c){
            case '0':ans += 0; break;
            case '1':ans += 1; break;
            case '2':ans += 2; break;
            case '3':ans += 3; break;
            case '4':ans += 4; break;
            case '5':ans += 5; break;
            case '6':ans += 6; break;
            case '7':ans += 7; break;
            case '8':ans += 8; break;
            case '9':ans += 9; break;
        }
    }
    printf("%d", ans);
}
