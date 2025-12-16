//1978: 소수 찾기(수학, 정수론, 소수 판정)
#include<stdio.h>
#define MAX 1001
void sieve(short natural[], short max);

int main(void){
    //소수 배열 세팅
    short prime[MAX]; for(short i = 0; i < MAX; i++){prime[i] = i;}
    sieve(prime, MAX - 1);
    short count = 0;
    short arg;
    short n; scanf("%hd", &n);
    for(short i = 1; i <= n; i++){
        scanf("%hd", &arg);
        count += prime[arg];
    }
    printf("%hd", count);
}
void sieve(short natural[], short max){
    natural[0] = 0; natural[1] = 0;
    
    short cur = 2;
    short ind;
    
    
    while(cur <= max){
        ind = cur;
        while(ind + cur <= max){
            ind += cur;
            natural[ind] = 0;
        }
        natural[cur] = 1;  //개수 세기
        cur++;
        while(natural[cur] == 0){
            cur++;
        }
    }
}
