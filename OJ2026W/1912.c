// S2 1912: 연속합(DP)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; scanf("%d",&n);
    int* t=(int*)malloc(sizeof(int)*n);
    int v;
    int m;
    scanf("%d",&v); t[0]=m=v;
    for(j=1;j<n;j++){
        scanf("%d",&v);
        t[j]=(v>t[j-1]+v)?v:t[j-1]+v;
        if(m<t[j]){m=t[j];}
    }
    printf("%d",m);
    free(t);
}