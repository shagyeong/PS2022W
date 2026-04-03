// S4 4949: 균형잡힌 세상(스택)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define L 102

int main(void){
    int j;
    char a[L]; // 원본 문자열
    char s[L]; // 스택
    int l;
    int t; // top of stack
    int f; // 출력 플래그
    while(1){
        fgets(a,L,stdin);
        l=(int)strlen(a); l--; a[l]='\0';
        if((l==1)&&(a[0]=='.')){break;}
        f=0;
        t=-1;
        for(j=0;j<l;j++){
            if     (a[j]=='('){s[++t]='(';}
            else if(a[j]=='['){s[++t]='[';}
            else if(a[j]==')'){if((t==-1)||(s[t]=='[')){printf("no\n"); f=1; break;}else{t--;}}
            else if(a[j]==']'){if((t==-1)||(s[t]=='(')){printf("no\n"); f=1; break;}else{t--;}}
            else{continue;}
        }
        if(f==1){continue;}
        else{
            if(t==-1){printf("yes\n");}
            else     {printf("no\n");}
        }
    }
}