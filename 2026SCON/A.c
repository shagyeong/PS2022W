#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int j; // loop variable
    int n; scanf("%d",&n);
    char* s=(char*)malloc(sizeof(char)*(n+1)); scanf("%s",s); s[n]='\0';
    int m; scanf("%d",&m);
    char* t=(char*)malloc(sizeof(char)*(m+1)); scanf("%s",t); t[m]='\0';
    int* times=(int*)calloc(26,sizeof(int)); // 알파벳 등장횟수

    for(j=0;j<n;j++){times[s[j]-'A']+=1;}
    for(j=0;j<m;j++){times[t[j]-'A']+=1;}
    if((times['I'-'A']>=1)&&(times['C'-'A']>=2)&&(times['P'-'A']>=1)){printf("m4us happy\n");}
    else{printf("m4us sad\n");}
    free(s);
    free(t);
}