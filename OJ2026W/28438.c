// S3 28438: 행련 연산(구현)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j; int k=0;
    int n; scanf("%d",&n);
    int m; scanf("%d",&m);
    int q; scanf("%d",&q);
    int o; int u; int v;

    int* r=(int*)calloc(n,sizeof(int));
    int* c=(int*)calloc(m,sizeof(int));

    for(j=0;j<q;j++){
        scanf("%d %d %d",&o,&u,&v); u-=1;
        if(o==1){r[u]+=v;}
        else    {c[u]+=v;}
    }
    for(j=0;j<n;j++){for(k=0;k<m;k++){printf("%d ",r[j]+c[k]);}printf("\n");}
    free(r);
    free(c);
}