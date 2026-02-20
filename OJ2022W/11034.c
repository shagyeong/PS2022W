// B3 11034: 캥거루 세마리 2(그리디)
#include<stdio.h>

int main(void){
    int a; int b; int c;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF){printf("%d\n",(b-a>c-b)?(b-a-1):(c-b-1));}
}