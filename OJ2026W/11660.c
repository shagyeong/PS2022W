// S1 11660: 구간 합 구하기 5(DP,누적합)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j; int k=0;
    int n; int m; scanf("%d %d",&n,&m);
    int u; int v; int w; int x;
    int r; // answer
    int** a=(int**)calloc(n+1,        sizeof(int*));
    int* _a=(int*) calloc((n+1)*(n+1),sizeof(int));
    int** s=(int**)calloc(n+1,        sizeof(int*));
    int* _s=(int*) calloc((n+1)*(n+1),sizeof(int));
    for(j=0;j<=n;j++){
        a[j]=_a+k;
        s[j]=_s+k;
        k+=(n+1);
    }
    for(j=1;j<=n;j++){for(k=1;k<=n;k++){
        scanf("%d",&a[j][k]);
        s[j][k]=s[j][k-1]+a[j][k];
    }}
    for(j=0;j<m;j++){
        r=0;
        scanf("%d %d %d %d",&u,&v,&w,&x);
        for(k=u;k<=w;k++){r+=(s[k][x]-s[k][v-1]);}
        printf("%d\n",r);
    }
    free(_a); free(a);
    free(_s); free(s);
}