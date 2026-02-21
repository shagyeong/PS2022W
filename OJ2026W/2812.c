// G3 2812: 크게 만들기(그리디,스택)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; int m; scanf("%d %d",&n,&m);
    int l=n-m; // length
    char* a=(char*)malloc(sizeof(char)*(n+1)); // 원본 문자열
    char* s=(char*)malloc(sizeof(char)*(n+1)); // stack
    int t=0;                                   // top of stack
    scanf("%s",a);

    for(j=0;j<n;j++){
        if(t==0)     {s[t++]=a[j]; continue;}
        if(a[j]<=s[t-1]){s[t++]=a[j]; continue;}
        while((t>0)&&(m>0)){
            if(a[j]>s[t-1]){t--; m--;}
            else        {break;}
        }
        s[t++]=a[j];
    }
    s[l]='\0';
    printf("%s",s);
    free(s);
    free(a);
}