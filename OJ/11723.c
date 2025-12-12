//11723: 집합(구현, 비트마스킹)
#include<stdio.h>
#include<string.h>

int main(void){
    int m; scanf("%d", &m);
    int S = 0;
    int arg;
    int mask;
    char inst[10];
    
    for(int i = 0; i < m; i++){
        scanf("%s", inst);
        if(strcmp(inst, "add") == 0){
            scanf("%d", &arg);
            mask = 1; mask <<= (arg - 1);
            S |= mask;
        }
        else if(strcmp(inst, "remove") == 0){
            scanf("%d", &arg);
            mask = 1; mask <<= (arg - 1);
            mask = 0b11111111111111111111 - mask;
            S &= mask;
        }
        else if(strcmp(inst, "check") == 0){
            scanf("%d", &arg);
            mask = 1; mask <<= (arg - 1);
            printf("%d\n", (S > (S ^ mask))); //토글 0->1 : 존재하지 않음
        }
        else if(strcmp(inst, "toggle") == 0){
            scanf("%d", &arg);
            mask = 1; mask <<= (arg - 1);
            S ^= mask;
        }
        else if(strcmp(inst, "all") == 0){
            S = 0b11111111111111111111;
        }
        else if(strcmp(inst, "empty") == 0){
            S = 0;
        }
    }
}
