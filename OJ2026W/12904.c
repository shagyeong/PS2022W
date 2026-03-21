// G5 12904: A와 B(구현,문자열,그리디)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int j;
    char* t=(char*)malloc(sizeof(char)*1001); // tmp: 뒤집기
    char* a=(char*)malloc(sizeof(char)*1001); scanf("%s",a);
    char* b=(char*)malloc(sizeof(char)*1001); scanf("%s",b);
    int n=(int)strlen(a); a[n]='\0';
    int m=(int)strlen(b); b[m]='\0';

    while(n<m){
        if(b[--m]=='A'){b[m]='\0'; continue;}
        else{
            for(j=0;j<m;j++){t[j]=b[(m-1)-j];}
            for(j=0;j<m;j++){b[j]=t[j];}
            b[m]='\0';
        }
    }

    if(strcmp(a,b)==0){printf("1");}
    else              {printf("0");}
    free(a);
    free(b);
}