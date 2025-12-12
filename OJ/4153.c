//4153: 직각삼각형(수학, 기하학, 피타고라스 정리)
#include<stdio.h>

int main(void){
    int x, y, z; scanf("%d %d %d", &x, &y, &z);
    while(x != 0 || y != 0 || z != 0){
        x *= x; y *= y; z*= z;
        if(x + y == z || y + z == x || z + x == y){
            printf("right\n");
        }
        else{
            printf("wrong\n");
        }
        scanf("%d %d %d", &x, &y, &z);
    }
}
