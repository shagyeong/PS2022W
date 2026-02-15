// S5 1316: 그룹 단어 체커(문자열)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int j; int k;
    int a=0; // answer
    int l;
    int n; scanf("%d",&n);
    int vist[26];
    char s[101];
    int f; // flag
    for(j=0;j<n;j++){
        scanf("%s",s);
        l=(int)strlen(s);
        memset(vist,0,sizeof(int)*26);
        vist[s[0]-'a']=1;
        f=1;
        for(k=1;k<l;k++){
            if(vist[s[k]-'a']==0){vist[s[k]-'a']=1;}
            else{if(s[k]!=s[k-1]){f=0; break;}}
        }
        a+=f;
    }
    printf("%d",a);
}