// G5 2294: 동전 2(DP)
#include<stdio.h>
#include<stdlib.h>

#define INF 10001

int main(void){
    int j; int k;
    int n; int m; scanf("%d %d",&n,&m);
    int* a=(int*)malloc(sizeof(int)*n); // coins
    int* t=(int*)malloc(sizeof(int)*(m+1));
    for(j=0;j<n ;j++){scanf("%d",&a[j]);}
    for(j=0;j<=m;j++){t[j]=INF;}
    t[0]=0;

    for(j=0;j<n;j++){
        if(a[j]>m){continue;}
        for(k=a[j];k<=m;k++){
            if(t[k-a[j]]!=INF){
                t[k]=(t[k]<t[k-a[j]]+1)?(t[k]):(t[k-a[j]]+1);
            }
        }
    }

    if(t[m]==INF){printf("-1");}
    else         {printf("%d",t[m]);}
    free(a);
    free(t);
}