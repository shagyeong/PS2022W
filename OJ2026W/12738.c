// G2 12738: 가장 긴 증가하는 부분 수열 3(LIS,이분탐색)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; scanf("%d",&n);
    int* a=(int*)malloc(sizeof(int)*n);
    int* t=(int*)malloc(sizeof(int)*n);
    int s=0; // length of LIS
    int l; int m; int r; // 이분탐색
    int i;
    for(j=0;j<n;j++){scanf("%d",&a[j]);}

    for(j=0;j<n;j++){
        l=0;
        r=s-1;
        i=-1;
        while(l<=r){
            m=(l+r)/2;
            if(a[j]<=t[m]){r=m-1; i=m;}
            else          {l=m+1;}
        }
        if(i==-1){t[s++]=a[j];}
        else     {t[i]=  a[j];}
    }
    printf("%d",s);
    free(a);
    free(t);
}