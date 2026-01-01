//27866: 문자와 문자열(구현, 문자열)
#include<stdio.h>

int main(void){
    char s[1000]; int n; scanf("%s %d", s, &n);
    printf("%c", s[n - 1]);
}