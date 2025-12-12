//2750: 수 정렬하기(구현, 정렬)
#include<stdio.h>
int main(void){
    int i; int j; int buf;
    int n; scanf("%d", &n);
    int integers[n];
    for(i = 0; i < n; i++){
        scanf("%d", &integers[i]);
    }
    //선택 정렬
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(integers[j] < integers[i]){
                buf = integers[j];
                integers[j] = integers[i];
                integers[i] = buf;
            }
        }

    }
    for(i = 0; i < n; i++){
        printf("%d\n", integers[i]);
    }
}
