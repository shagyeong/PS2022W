// B2 10174: 팰린드롬(문자열,팰린드롬)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int j;
    int _; scanf("%d",&_); char c; scanf("%c",&c);
    int f;
    char s[20]; // +2: '\0', '\n'
    int l;


    while(_-->0){
        fgets(s,20,stdin);
        l=(int)strlen(s)-1; s[l]='\0';
        f=1;
        for(j=0;j<l/2;j++){
            if     (('a'<=s[j])&&(s[j]<='z')){if((s[j]-'a'!=s[l-1-j]-'a')&&(s[j]-'a'!=s[l-1-j]-'A')){f=0; break;}}
            else if(('A'<=s[j])&&(s[j]<='Z')){if((s[j]-'A'!=s[l-1-j]-'a')&&(s[j]-'A'!=s[l-1-j]-'A')){f=0; break;}}
            else                             {if(s[j]!=s[l-1-j])                                    {f=0; break;}}
        }
        if(f==1){printf("Yes\n");}
        if(f==0){printf("No\n");}
    }
}