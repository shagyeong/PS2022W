// B1 14626: ISBN(브루트포스)
#include<stdio.h>

int main(void){
    int j;
    char s[14]; scanf("%s",s);
    int w; // 가중치
    int d=0;
    for(j=0;j<=12;j+=2){if(s[j]=='*'){w=1; continue;} d+=(s[j]-'0');     d%=10;}
    for(j=1;j<=11;j+=2){if(s[j]=='*'){w=3; continue;} d+=(3*(s[j]-'0')); d%=10;}
    for(j=0;j<=9;j++){if(((d+j*w)%10)==0){break;}}
    printf("%d",j);
}