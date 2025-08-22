//9095: 1, 2, 3 더하기(다이나믹 프로그래밍)
#include<stdio.h>
int main(void){
    // dp
    // int i[11]={1, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0};
    // for(int j = 0; j < 8; j++){
    //     i[j+3]=i[j]+i[j+1]+i[j+2];
    // }

    int n; scanf("%d", &n);
    int m;
    loop:
        scanf("%d", &m); 
        switch(m){
            case 1: printf("1\n"); break;
            case 2: printf("2\n"); break;
            case 3: printf("4\n"); break;
            case 4: printf("7\n"); break;
            case 5: printf("13\n"); break;
            case 6: printf("24\n"); break;
            case 7: printf("44\n"); break;
            case 8: printf("81\n"); break;
            case 9: printf("149\n"); break;
            case 10: printf("274\n"); break;
            case 11: printf("504\n"); break;
        }
        if(--n>0){goto loop;}
}
