//15727: 조별과제를 하려는데 조장이 사라졌다(수학, 사칙연산)
#include<stdio.h>
int main(void){
    int d; scanf("%d", &d);
    d = (d%5 == 0)?(d/5):(d/5+1);
    printf("%d", d);
}
