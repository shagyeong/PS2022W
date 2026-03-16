// S2 33912: N거리 건너기()
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; int m; scanf("%d %d",&n,&m);
    int v;
    int* a=(int*)malloc(sizeof(int)*(n+1));
    int t;
    long long int cw=-1;
    long long int ccw=-1;
    for(j=0;j<n;j++){
        scanf("%d",&v);
        a[v]=j;
    }

    for(j=1;j<m;j++){
        cw+=1;
        t=cw%n;
        if     (t<a[j]){cw+=(a[j]-t);}
        else if(t>a[j]){cw+=(n-(t-a[j]));}
    }
    for(j=n;j>=m;j--){
        ccw+=1;
        t=ccw%n;
        if     (t<a[j]){ccw+=(a[j]-t);}
        else if(t>a[j]){ccw+=(n-(t-a[j]));}
    }
    if(cw==ccw){printf("EQ");}
    if(cw< ccw){printf("CW");}
    if(cw> ccw){printf("CCW");}
    free(a);
}