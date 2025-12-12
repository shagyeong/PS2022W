//1929: 소수 구하기(수학, 정수론, 소수 판정, 에라토스테네스의 체)
#include<stdio.h>
void sieve(int min, int max);
int main(void){
    int min, max; scanf("%d %d", &min, &max);
    sieve(min, max);
}
void sieve(int min, int max){
    //sieve 세팅
    int prime[max + 1]; for(int i = 0; i < max + 1; i++){prime[i] = i;}
    prime[0] = 0;//소수가 아닌 수는 0으로 표기
    prime[1] = 0;
    //거르기
    int cur = 2;
    int ind;
    while(cur <= max){
        ind = cur;
        while(ind + cur <= max){
            ind += cur;
            prime[ind] = 0;
        }
        cur++;
        while(prime[cur] == 0){
            cur++;
        }
    }
    for(int i = min; i<= max; i++){
        if(prime[i] != 0){printf("%d\n", prime[i]);}
    }
}
