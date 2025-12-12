//1259: 팰린드롬수(구현, 문자열)
#include<stdio.h>

int main(void){
    //99999이하: abcde형태라 하자
    int n; scanf("%d",&n);
    char a, b, c, d, e;
    do{
        a = n / 10000;  n %= 10000;
        b = n / 1000;   n %= 1000;
        c = n / 100;    n %= 100;
        d = n / 10;     n %= 10;
        e = n;
        if(a != 0){
            switch(a == e && b == d){
                case 0: printf("no\n"); break;
                case 1: printf("yes\n");break;
            }
        }else if(b != 0){
            switch(b == e && c == d){
                case 0: printf("no\n"); break;
                case 1: printf("yes\n");break;
            }       
        }else if(c != 0){
            switch(c == e){
                case 0: printf("no\n"); break;
                case 1: printf("yes\n");break;
            }
        }else if(d != 0){
            switch(d == e){
                case 0: printf("no\n"); break;
                case 1: printf("yes\n");break;
            }
        }else{
            printf("yes\n");
        }
        scanf("%d",&n);
    }while(n != 0);
}
