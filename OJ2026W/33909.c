// B3 33909: 알파벳 블록
#include<stdio.h>

int main(void){
    int s; int c; int o; int n; scanf("%d %d %d %d",&s,&c,&o,&n);
    printf("%d",((s+n)/3<(c+2*o)/6)?((s+n)/3):((c+2*o)/6));
}