// G4 34709: 트리 펴기(트리,애드혹)
#include<stdio.h>

int main(void){
    int a=0; // answer
    int j; // loop variable
    int u; int v;
    int n; scanf("%d",&n);
    int d[n+1]; for(j=0;j<=n;j++){d[j]=0;} // degree
    for(j=0;j<n-1;j++){
        scanf("%d %d",&u,&v);
        d[u]+=1;
        d[v]+=1;
    }
    for(j=1;j<=n;j++){if(d[j]==1){a++;}}
    printf("%d",a-2);
}