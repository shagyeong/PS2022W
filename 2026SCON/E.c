#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; scanf("%d",&n);
    char* s=(char*)malloc(sizeof(char)*(n+1)); scanf("%s",s); s[n]='\0';
    char* a=(char*)malloc(sizeof(char)*(n+1)); a[n]='\0'; // 0101...
    char* b=(char*)malloc(sizeof(char)*(n+1)); b[n]='\0'; // 1010...
    for(j=0;j<n;j+=2){a[j]='0'; b[j]='1';}
    for(j=1;j<n;j+=2){a[j]='1'; b[j]='0';}


    int f=0; // 일치 0, 불일치 1
    int num_a=0;
    int num_b=0;

    for(j=0;j<n;j++){
        if(s[j]!=a[j]){
            if(f==0){f=1; num_a+=1;}
            else{continue;}
        }
        else{f=0;}
    }
    for(j=0;j<n;j++){
        if(s[j]!=a[j]){
            if(f==0){f=1; num_b+=1;}
            else{continue;}
        }
        else{f=0;}
    }

    printf("%d",(num_a<num_b)?num_a:num_b);

    free(s);
    free(a);
    free(b);
}