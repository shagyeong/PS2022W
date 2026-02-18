// G4 14002: 가장 긴 증가하는 부분 수열 4(LIS)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; scanf("%d",&n);
    int* a=(int*)malloc(sizeof(int)*n);
    int* b;
    int* t=(int*)malloc(sizeof(int)*n);
    int* p=(int*)malloc(sizeof(int)*n);
    int s=0; // length of LIS
    int l; int m; int r;
    int i;
    int e;
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
        if(i==-1){p[j]=s; t[s++]=a[j];}
        else     {p[j]=i; t[i]  =a[j];}
    }
    b=(int*)malloc(sizeof(int)*s);
    e=s-1;
    for(j=n-1;j>=0;j--){if(p[j]==e){b[e--]=a[j];}}
    printf("%d\n",s);
    for(j=0;j<s;j++){printf("%d ",b[j]);}
    free(a); free(b);
    free(t); free(p);
}