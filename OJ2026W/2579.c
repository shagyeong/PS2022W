// S3 2579: 계단 오르기(DP)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; scanf("%d",&n);
    int* a=(int*)malloc(sizeof(int)*n);
    int* t=(int*)malloc(sizeof(int)*n);
    for(j=0;j<n;j++){
        scanf("%d",&a[j]);
        t[j]=0;
    }
    if(n==1){printf("%d",a[0]);      free(a); free(t); return 0;}
    if(n==2){printf("%d",a[0]+a[1]); free(a); free(t); return 0;}
    t[0]=a[0];
    t[1]=a[0]+a[1];
    t[2]=(a[0]+a[2]>a[1]+a[2])?(a[0]+a[2]):(a[1]+a[2]);
    for(j=3;j<n;j++){t[j]=(t[j-2]>t[j-3]+a[j-1])?(a[j]+t[j-2]):(a[j]+t[j-3]+a[j-1]);}
    printf("%d",t[n-1]);
    free(a);
    free(t);
    return 0;
}