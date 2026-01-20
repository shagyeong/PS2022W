// P5 14003: 가장 긴 증가하는 부분 수열 5(LIS)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j; // loop variable
    int n; scanf("%d",&n);
    int* a=(int*)malloc(sizeof(int)*n);
    int* t=(int*)malloc(sizeof(int)*n);
    int s=0;
    int l; int m; int r;

    int* p=(int*)malloc(sizeof(int)*n);
    int* q=(int*)malloc(sizeof(int)*n);
    int i; int e;

    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    for(j=0;j<n;j++){
        l=0;
        r=s-1;
        i=-1;
        while(l<=r){
            m=(l+r)/2;
            if(t[m]<a[j]){l=m+1;}
            else         {r=m-1; i=m;}
        }
        if(i==-1){p[j]=s; t[s++]=a[j];}
        else     {p[j]=i; t[i  ]=a[j];}
    }

    e=s-1;
    for(j=n-1;j>=0;j--){
        if(p[j]==e){q[e--]=a[j];}
    }

    printf("%d\n",s);
    for(j=0;j<s;j++){printf("%d ",q[j]);}
}