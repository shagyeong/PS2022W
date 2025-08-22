//2015: 수들의 합(자료 구조, 누적 합, 해시를 사용한 집합과 맵, 트리를 사용한 집합과 맵)
#include<stdio.h>

int main(void){
    int sum;
    int count = 0;
    int i, j, h;
    int n; int k; scanf("%d %d", &n, &k);
    int arr[n];
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j + i < n; j++){
            sum = 0;
            for(h = j; h <= j + i; h++){
                sum += arr[h];
            }
            if(k == sum){count++;}
        }
    }
    printf("%d", count);
}
