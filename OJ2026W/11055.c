// S2 11055: 가장 큰 증가하는 부분 수열(MSIS)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j; int k;
    int n; scanf("%d",&n);
    int* a=(int*)malloc(sizeof(int)*n);
    int* t=(int*)malloc(sizeof(int)*n);
    int m; // answer: 최대값
    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    for(j=0;j<n;j++){
        t[j]=a[j];
        for(k=0;k<j;k++){
            if(a[k]<a[j]){
                t[j]=(t[j]>t[k]+a[j])?(t[j]):(t[k]+a[j]);
            }
        }
    }
    m=t[0]; for(j=1;j<n;j++){if(m<t[j]){m=t[j];}}
    printf("%d",m);
    free(a);
    free(t);
}