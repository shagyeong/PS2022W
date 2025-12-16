//1344: 축구(수학, 다이나믹 프로그래밍, 조합론, 확률론)
#include<stdio.h>

int main(void){
    int i, j, k;

    double ans;
    double ans_a = 0;   double buf_a;
    double ans_b = 0;   double buf_b;


    double a; scanf("%lf", &a);
    double b; scanf("%lf", &b);
    double ac = 100 - a;
    double bc = 100 - b;
    ac /= 100; a/= 100;
    bc /= 100; b/= 100;
    
    int goal[12] = {0, 1, 4, 6, 8, 9, 10, 12, 14, 15, 16, 18};
    for(i = 0; i < 12; i++){
        buf_a = 1; buf_b = 1;
        //Combination
        j = 18;
        while(j > 18 - goal[i]){
            buf_a *= j;
            buf_a /= j - (18 -goal[i]);
            j--;
        }buf_b = buf_a;
        k = 0;
        while(k < goal[i]){
            buf_a *= a;
            buf_b *= b;
            k++;
        }
        while(k < 18){
            buf_a *= ac;
            buf_b *= bc;
            k++;
        }
        ans_a += buf_a;
        ans_b += buf_b;
    }
    ans = ans_a * ans_b;
    printf("%lf", 1 - ans);
}
