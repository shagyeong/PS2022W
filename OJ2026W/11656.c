// S4: 11656 접미사 배열(문자열,접미사배열)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare(const void* u,const void* v){return strcmp(*((char**)u),*((char**)v));}

int main(void){
    int j;
    int k;
    char s[1000]; scanf("%s",s);
    int   l=(int)(strlen(s));
    char* a[l];

    for(j=0;j<l;j++){
        a[j]=(char*)malloc(sizeof(char)*(l-j+1));
        for(k=j;k<l;k++){a[j][k-j]=s[k];}
        a[j][l-j]='\0';
    }

    qsort(&a[0],l,sizeof(char*),compare);
    for(j=0;j<l;j++){printf("%s\n",a[j]);}
}