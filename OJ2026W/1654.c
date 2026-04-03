// S2 1654: 랜선 자르기(이분탐색,매개변수탐색)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    long long int j;
    long long int n; long long int k; scanf("%lld %lld",&n,&k);
    long long int l=1; // left
    long long int m; // middle
    long long int r; // right
    long long int c; // count
    long long int w; // answr
    long long int* a=(long long int*)malloc(sizeof(long long int)*n);
    scanf("%lld",&a[0]); r=a[0];
    for(j=1;j<n;j++){scanf("%lld",&a[j]); if(r<a[j]){r=a[j];}}

    while(l<=r){
        m=(l+r)/2;
        c=0; for(j=0;j<n;j++){c+=a[j]/m;}
        if(c>=k){l=m+1; w=m;}
        else    {r=m-1;}
    }
    printf("%lld",w);
}