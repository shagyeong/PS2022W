//1069: 집으로(애드 혹, 기하학, 많은 조건 분기)
#include<stdio.h>
#include<math.h>

int main(void){
    double ans;
    int x, y, d, t; scanf("%d %d %d %d", &x, &y, &d, &t);
    double dist = sqrt(x * x + y * y);
    double jump = (double)d/ (double)t;
    
    
    if(jump <= 1){
        ans = dist;
        printf("%f", ans);
    }
    else{
        //몫 세팅
        int q = (int)(dist / (double)d);
        if((double)q * d > dist){q -= 1;}
        //지나치지 않은 경우
        double r1 = dist - (double)(q * d);
        double t1 = (double)(q * t) + r1;
        //지나친 경우
        double r2 = (double)((q + 1) * d) - dist;
        double t2 = (double)((q + 1) * t) + r2;
        ans = (t1<t2)?t1:t2;
        printf("%.16f", ans);
    }
}
