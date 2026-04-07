// B2 13235: 팰린드롬(문자열,팰린드롬)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int j;
    char s[21]; scanf("%s",s);
    int l=(int)strlen(s);
    for(j=0;j<l/2;j++){if(s[j]!=s[l-1-j]){printf("false"); return 0;}}
    printf("true");
    return 0;
}