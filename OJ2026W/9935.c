// G4 9935: 문자열 폭발(문자열,스택)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define L 1000001
#define Q 37

int main(void){
    int j;
    int k;
    char* a=(char*)malloc(sizeof(char)*L); scanf("%s",a);
    char* q=(char*)malloc(sizeof(char)*Q); scanf("%s",q);
    char* s=(char*)malloc(sizeof(char)*L);
    int n=strlen(a);
    int m=strlen(q);
    int t=-1; // top of stack
    int f; // explosion flag

    for(j=0;j<n;j++){
        s[++t]=a[j];
        if(t+1>=m){
            f=1;
            for(k=0;k<m;k++){if(q[k]!=s[(t+1-m)+k]){f=0;break;}}
            if(f==1){t-=m;} // explostion
        }
    }
    if(t==-1){printf("FRULA");}
    else     {s[t+1]='\0'; printf("%s",s);}
    free(a);
    free(q);
    free(s);
}