// B1 1157: 단어 공부(문자열)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int j;
    int l;
    int c[26]; memset(c,0,sizeof(int)*26); // count
    char* s=(char*)malloc(sizeof(char)*1000001);
    int m=0; // max
    int i=0; // index of max
    int f=0; // flag
    scanf("%s",s);
    l=(int)strlen(s); s[l]='\0';
    
    for(j=0;j<l;j++){
        if(s[j]<='Z'){c[s[j]-'A']++;}
        else         {c[s[j]-'a']++;}
    }

    for(j=0;j<26;j++){
        if(m> c[j]){continue;}
        if(m< c[j]){f=0; m=c[j]; i=j; continue;}
        if(m==c[j]){f=1;}
    }
    if(f==1){printf("?");}
    else    {printf("%c",i+'A');}
}