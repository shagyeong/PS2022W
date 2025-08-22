//1016: 제곱 ㄴㄴ 수(수학, 정수론, 소수 판정, 에라토스테네스의 체)
#include<stdio.h>
#include<math.h>
void sieve(int min, int max);

int main(void){
    //입력 값 세팅
    int min, max; scanf("%d %d", &min, &max);
    sieve(min, max);
}
void sieve(int min, int max){
    int i, j;
    int count = 0;  //정답

    //자연수 배열 세팅
    int MAX;    //소수 범위
    float sqr = sqrtf((float)max); MAX = (int)sqr + 2;
    int natural[MAX];   //natrual: 자연수 배열
    for(i = 0; i < MAX; i++){natural[i] = i;}
    natural[0] = 0; natural[1] = 0;
    
    //거르기
    int NUM = 0;        //소수 개수
    int cur; int ind;   //현재 소수, 인덱스 버퍼
    cur = 2;
    while(cur < MAX){
        ind = cur;
        while(ind + cur < MAX){
            ind += cur;
            natural[ind] = 0;
        }
        NUM++; cur++;
        while(natural[cur] == 0){
            cur++;
        }
    }

    //소수(제곱) 배열 세팅
    int prime[NUM];    
    i = 0; j = 0;
    while(i < NUM){
        if(natural[j] == 0){
            j++;
        }
        else{
            prime[i] = natural[j] * natural[j];
            i++; j++;
        }
    }

    for(i = 0; i < NUM; i++){
        printf("%d ", prime[i]);
    }printf("\n");

    //정답 출력
    for(i = min; i <= max; i++){
        j = 0;
        while(prime[j] <= i){
            if(i % prime[j] == 0){
                count--;
                break;
            }
            j++;
        }
        count++;
    }
    printf("%d", count);
}
