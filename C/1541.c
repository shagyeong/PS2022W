//1541: 잃어버린 괄호(수학, 그리디 알고리즘, 문자열, 파싱)
#include<stdio.h>
#include<string.h>

int main(void){
    int ans = 0;    // answer
    int t = 0;      // term: 각 상수항
    int p = 0;      // parenthesis: 괄호 내 값 버퍼
    int w = 1;      // weight: power of 10
    char s[50]; scanf("%s", s);
    size_t i = strlen(s);

    loop:
        switch(s[--i]){
            case 48: t+=(w*0); w*=10; break;
            case 49: t+=(w*1); w*=10; break;
            case 50: t+=(w*2); w*=10; break;
            case 51: t+=(w*3); w*=10; break;
            case 52: t+=(w*4); w*=10; break;
            case 53: t+=(w*5); w*=10; break;
            case 54: t+=(w*6); w*=10; break;
            case 55: t+=(w*7); w*=10; break;
            case 56: t+=(w*8); w*=10; break;
            case 57: t+=(w*9); w*=10; break;
            
            case 43:    // '+'
                p += t;
                t = 0;      // 상수항 초기화
                w = 1;        // 가중치 초기화
                break;
            case 45:    // '-'
                p += t;
                ans -= p;
                p = 0;
                t = 0;
                w = 1;
                break;
        }
        if(i > 0){goto loop;}
    // 첫 번째 항: '+' 생략
    p += t;
    ans += p;
    printf("%d\n", ans);
}
