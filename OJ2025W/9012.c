// S4 9012: 괄호(스택)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int j; int k;
    int n; scanf("%d",&n);
    int t; // top of stack
    int l;   // length of string
    char s[51]; // string

    for(j=0;j<n;j++){
        scanf("%s",s);
        l=(int)strlen(s);
        t=0;
        for(k=0;k<l;k++){
            if(s[k]=='('){t++;}
            else{if(--t<0){t=-1; break;}}
        }
        if(t==0){printf("YES\n");}
        else    {printf("NO\n");}
    }
}