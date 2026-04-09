// S5 1427: 소트인사이드(문자열,정렬)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int dsc(const void* u,const void* v){return *((char*)v)-*((char*)u);}

int main(void){
    char s[11]; scanf("%s",s);
    int l=strlen(s);
    qsort(s,l,sizeof(char),dsc);
    printf("%s",s);
}