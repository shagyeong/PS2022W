//1322: X와 K(수학, 비트마스킹)
#include<stdio.h>

int main(void){
    int i, j;
    int x, k; scanf("%d %d", &x, &k);
    long long answer = 0;
    long long weight = 1;

    char m = 0; //x 1 개수
    char mark[64]; for(i = 0; i < 64; i++){mark[i] = 0;}
    char ans[64]; for(i = 0; i < 64; i++){ans[i] = 0;}
    
    i = 0;
    while(x != 0){
        if(x%2 == 1){mark[i] = 1;}
        i++; x >>= 1;
    }

    i = 0;
    while(k != 0){
        if(mark[i] == 1){i++;}
        else{ans[i++] = k % 2; k >>= 1;}
    }

    for(i = 0; i < 64; i++){
        answer += weight * ans[i];
        weight <<= 1;
    }
    printf("%lld", answer);
}
