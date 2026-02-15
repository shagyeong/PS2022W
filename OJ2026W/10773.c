// S4 10773: 제로(스택)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; scanf("%d",&n);
    int* s=(int*)malloc(sizeof(int)*n);
    int v;
    int a=0; // answer
    int t=0; // top of stack
    for(j=0;j<n;j++){
        scanf("%d",&v);
        if(v!=0){s[t++]=v;}
        else    {t--;}
    }
    for(j=0;j<t;j++){a+=s[j];}
    printf("%d",a);
    free(s);
}