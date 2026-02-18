// S4 1158: 요세푸스 문제(큐)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j; int k;
    int n; int m; scanf("%d %d",&n,&m);
    int* q=(int*)malloc(sizeof(int)*n);
    int f=0;   // front of queue
    int r=n-1; // rear of queue
    for(j=0;j<n;j++){q[j]=j+1;}

    printf("<");
    for(j=0;j<n;j++){
        for(k=0;k<m-1;k++){r+=1; r%=n; q[r]=q[f]; f+=1; f%=n;}
        printf("%d",q[f]); f+=1; f%=n;
        if(j!=n-1){printf(", ");}
    }
    printf(">");

    free(q);
}