// S3 1904: 01타일(DP)
#include<stdio.h>
#include<stdlib.h>

#define D 15746 // divisor

int main(void){
    int j;
    int n; scanf("%d",&n);
    if(n==1){printf("1"); return 0;}
    if(n==2){printf("2"); return 0;}
    int* t=(int*)malloc(sizeof(int)*(n+1));
    
    t[1]=1;
    t[2]=2;
    for(j=3;j<=n;j++){t[j]=(t[j-2]+t[j-1])%D;}
    printf("%d",t[n]);
    free(t);
    return 0;
}