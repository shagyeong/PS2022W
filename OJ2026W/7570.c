// G2 7570: 줄세우기(DP)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; scanf("%d",&n);
    int v;
    int m=0; // max
    int* t=(int*)calloc(n+1,sizeof(int));
    for(j=0;j<n;j++){
        scanf("%d",&v);
        t[v]=t[v-1]+1;
        m=(m>t[v])?m:t[v];
    }
    printf("%d",n-m);
    free(t);
}