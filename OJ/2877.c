//2877: 4와 7(수학, 구현)
#include<stdio.h>

int main(void){
    int i;
    int k; scanf("%d", &k);
    k++;
    unsigned char bin[32];
    i = 0;
    while(k != 0){
        bin[i++] = k%2;
        k >>= 1;
    }
    i -= 2;
    while(i >= 0){
        switch(bin[i--]){
            case 0: printf("4"); break;
            case 1: printf("7"); break;
        }
    }
}
