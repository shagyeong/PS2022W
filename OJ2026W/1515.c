// S2 1515: 수 이어쓰기(구현,문자열,브루트포스,그리디)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int j;
    int n=1;
    int i=0; // index of s
    int l; // length of s
    char* a=(char*)malloc(sizeof(char)*3001);
    char* s=(char*)malloc(sizeof(char)*3001); scanf("%s",s);
    l=(int)strlen(s);

    while(i<l){
        sprintf(a,"%d",n++);
        for(j=0;a[j]!='\0';j++){
            if(a[j]==s[i]){if(++i==l){break;}}
            else          {continue;}
        }
    }
    printf("%d",n-1);
    free(a);
    free(s);
}