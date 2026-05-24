#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; scanf("%d",&n);
    int* a=(int*)malloc(sizeof(int)*n+1);
    a[n/2]=0;
    for(j=1;j<=(n/2);j++){
        a[n/2-j]=(j%2==0)?j:-j;
        a[n/2+j]=(j%2==0)?-j:j;
    }
    for(j=0;j<n;j++){printf("%d ",a[j]);}
}