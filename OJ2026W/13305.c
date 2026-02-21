// S3 13305: 주유소(그리디)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    long long int j;
    long long int n; scanf("%lld",&n); n-=1;
    long long int m; // min
    long long int d=0; // distance
    long long int c=0; // cost
    long long int* a=(long long int*)malloc(sizeof(long long int)*n); // distance
    long long int* b=(long long int*)malloc(sizeof(long long int)*n); // cost
    for(j=0;j<n;j++){scanf("%lld",&a[j]);}
    for(j=0;j<n;j++){scanf("%lld",&b[j]);} scanf("%lld",&j);
    
    m=b[0];
    for(j=0;j<n;j++){
        if(b[j]<m){m=b[j];}
        c+=m*a[j];
    }
    
    printf("%lld",c);
    free(a);
    free(b);
}