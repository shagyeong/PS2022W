// S3 2559: 수열(누적합,투포인터,슬라이딩윈도우)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; int l; scanf("%d %d",&n,&l);
    int* a=(int*)malloc(sizeof(int)*(n+1)); a[0]=0;
    int* s=(int*)malloc(sizeof(int)*(n+1)); s[0]=0;
    int m=-10000001; // 최대값
    for(j=1;j<=n;j++){
        scanf("%d",&a[j]);
        s[j]=s[j-1]+a[j];
    }
    for(j=1;j<=n-(l-1);j++){
        m=(m>s[j+(l-1)]-s[j-1])?m:s[j+(l-1)]-s[j-1];
    }
    printf("%d",m);
    free(a);
    free(s);
}