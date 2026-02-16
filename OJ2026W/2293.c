// G4 2293: 동전 1(DP)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j; int k;
    int n; int m; scanf("%d %d",&n,&m);
    int c; // coin
    int* t=(int*)calloc(m+1,sizeof(int));
    t[0]=1;
    for(j=0;j<n;j++){
        scanf("%d",&c);
        for(k=c;k<=m;k++){t[k]=t[k]+t[k-c];}
    }
    printf("%d",t[m]);
    free(t);
}