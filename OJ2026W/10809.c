// B2 10809: 알파벳 찾기(문자열)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    char  j;
    char* a=(char*)malloc(sizeof(char)*('a'+26));
    char* s=(char*)malloc(sizeof(char)*101); scanf("%s",s);
    char  l=(char)strlen(s);
    for(j='a';j<='z';j++){a[j]=-1;}
    for(j=0;  j<l;   j++){if(a[s[j]]==-1){a[s[j]]=j;}}
    for(j='a';j<='z';j++){printf("%d ",a[j]);}
    free(a);
    free(s);
}