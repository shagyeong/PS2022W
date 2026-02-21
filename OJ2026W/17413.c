// S3 17413: 단어 뒤집기 2(구현,문자열,스택)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int j;
    int l;
    char* a=(char*)malloc(sizeof(char)*100001); // 원본 문자열
    char* s=(char*)malloc(sizeof(char)*100001); // stack
    int t=-1; // top of stack
    int flag=0; // '<', '>' 내부

    fgets(a,100001,stdin);
    a[strcspn(a,"\n")]='\0';
    l=(int)strlen(a);

    for(j=0;j<l;j++){
        if(flag==1){
            printf("%c",a[j]);
            if(a[j]=='>'){flag=0;}
        }
        else{
            if(a[j]=='<'){
                while(t>=0){printf("%c",s[t--]);}
                flag=1; printf("<"); continue;
            }
            if(a[j]==' '){
                while(t>=0){printf("%c",s[t--]);}
                printf(" ");
                continue;
            }
            s[++t]=a[j];
        }
    }
    while(t>=0){printf("%c",s[t--]);}

    free(a);
    free(s);
}