// S3 9461: 파도반 수열(DP)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; scanf("%d",&n);
    int v;
    unsigned long long int* t=(unsigned long long int*)malloc(sizeof(unsigned long long int)*101);
    t[1]=1;t[2]=1;t[3]=1;t[4]=2;t[5]=2;
    t[6]=3;t[7]=4;t[8]=5;t[9]=7;t[10]=9;
    for(j=11;j<=100;j++){t[j]=t[j-5]+t[j-1];}
    for(j=0;j<n;j++){scanf("%d",&v); printf("%lld\n",t[v]);}
    free(t);
}