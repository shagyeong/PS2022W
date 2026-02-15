// S4 2164: 카드2(큐)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; scanf("%d",&n);
    int* q=(int*)malloc(sizeof(int)*(2*n+1));
    for(j=1;j<=n;j++){q[j]=j;}
    int f=1; // front of queue
    int r=n; // rear of queue
    while(f<r){
        f++;
        r++;
        q[r]=q[f++];
    }
    printf("%d",q[f]);
    free(q);
}