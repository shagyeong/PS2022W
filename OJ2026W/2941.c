// S5 2941: 크로아티아 알파벳(구현,문자열)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int o=0; // offset
    int a=0; // answer
    int l;
    char* s=(char*)malloc(sizeof(char)*101);
    scanf("%s",s); l=(int)strlen(s); s[l]='\0';
    while(o<l){
        if(s[o]=='c'){
            if(s[o+1]=='='){o+=2; a++; continue;}
            if(s[o+1]=='-'){o+=2; a++; continue;}
        }
        else if(s[o]=='d'){
            if(s[o+1]=='-'){o+=2; a++; continue;}
            if((o+2<l)&&(s[o+1]=='z')&&(s[o+2]=='=')){o+=3; a++; continue;}
        }
        else if(s[o]=='l'){if(s[o+1]=='j'){o+=2; a++; continue;}}
        else if(s[o]=='n'){if(s[o+1]=='j'){o+=2; a++; continue;}}
        else if(s[o]=='s'){if(s[o+1]=='='){o+=2; a++; continue;}}
        else if(s[o]=='z'){if(s[o+1]=='='){o+=2; a++; continue;}}

        o++;
        a++;
    }
    printf("%d",a);
}