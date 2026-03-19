// S3 11659: 구간 합 구하기 4(누적합)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; int m; scanf("%d %d",&n,&m);
    int u; int v;
    int* a=(int*)malloc(sizeof(int)*(n+1)); a[0]=0;
    int* s=(int*)malloc(sizeof(int)*(n+1)); s[0]=0;
    for(j=1;j<=n;j++){scanf("%d",&a[j]); s[j]=s[j-1]+a[j];}
    for(j=0;j< m;j++){scanf("%d %d",&u,&v); printf("%d\n",s[v]-s[u-1]);}
    free(a);
    free(s);
}