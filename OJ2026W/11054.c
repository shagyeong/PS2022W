// G4 11054: 가장 긴 바이토닉 부분 수열(LIS,DP)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; scanf("%d",&n);
    int max;
    int* a=  (int*)malloc(sizeof(int)*n);
    int* t=  (int*)malloc(sizeof(int)*n);
    int* lis=(int*)malloc(sizeof(int)*n);
    int* lds=(int*)malloc(sizeof(int)*n);

    int s;
    int l; int m; int r;
    int i;

    for(j=0;j<n;j++){scanf("%d",&a[j]);}

    s=0;
    for(j=0;j<n;j++){
        l=0; r=s-1;
        i=-1;
        while(l<=r){
            m=(l+r)/2;
            if(a[j]<=t[m]){r=m-1; i=m;}
            else          {l=m+1;}
        }
        if(i==-1){t[s++]=a[j]; lis[j]=s;}
        else     {t[i]=  a[j]; lis[j]=i+1;}
    }

    s=0;
    for(j=n-1;j>=0;j--){
        l=0; r=s-1;
        i=-1;
        while(l<=r){
            m=(l+r)/2;
            if(a[j]<=t[m]){r=m-1; i=m;}
            else          {l=m+1;}
        }
        if(i==-1){t[s++]=a[j]; lds[j]=s;}
        else     {t[i]=  a[j]; lds[j]=i+1;}
    }

    max=lis[0]+lds[0];
    for(j=1;j<n;j++){max=(max>lis[j]+lds[j])?(max):(lis[j]+lds[j]);}
    printf("%d",max-1);
    free(a);
    free(t);
    free(lis);
    free(lds);
}