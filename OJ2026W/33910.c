// S5 33910: 합의 최소(그리디)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; scanf("%d",&n);
    int* a=(int*)malloc(sizeof(int)*n); for(j=0;j<n;j++){scanf("%d",&a[j]);}
    long long int w=a[n-1]; // answer
    int m=a[n-1]; // min

    for(j=n-2;j>=0;j--){
        if(a[j]<m){w+=a[j]; m=a[j];}
        else      {w+=m;}
    }
    printf("%lld",w);
    free(a);
}