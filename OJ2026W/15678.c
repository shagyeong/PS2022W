// P5 15678: 연세워터파크(DP,데크최대값트릭)
#include<stdio.h>
#include<stdlib.h>

struct node{
    long long int v;
    int i;
};

int main(void){
    int j;
    int n; int l; scanf("%d %d",&n,&l);
    long long int v;
    long long int m; // answer(max)
    long long int* a=(long long int*)malloc(sizeof(long long int)*n); for(j=0;j<n;j++){scanf("%lld",&a[j]);}
    struct node* d=(struct node*)malloc(sizeof(struct node)*n);
    int f=0;
    int r=0;
    d[r  ].v=a[0]; m=a[0];
    d[r++].i=0;
    for(j=1;j<n;j++){
        v=(a[j]>d[f].v+a[j])?a[j]:d[f].v+a[j];
        if(m<v){m=v;} // 최대값 갱신
        while((f<r)&&(v>=d[r-1].v)){r--;}
        d[r].v=v; d[r++].i=j;
        if(d[f].i<=j-l){f++;}
    }
    printf("%lld",m);
}