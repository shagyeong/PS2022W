// G2 12015: 가장 긴 증가하는 부분 수열 2(LIS,이분 탐색)
#include <stdio.h>

int main(void){
    int j; // loop variable
    int n; scanf("%d",&n);
    int a[n]; for(j=0;j<n;j++){scanf("%d",&a[j]);}
    int t[n];
    int s=0;  // length of LIS
    int l; // left
    int m; // middle
    int r; // right
    int i; // location

    for(j=0;j<n;j++){
        l=0;
        r=s-1;
        i=-1;
        while(l<=r){
            m=(l+r)/2;
            if(t[m]<a[j]){l=m+1;}
            else         {i=m;r=m-1;}
        }
        if(i==-1){t[s++]=a[j];}
        else     {t[i]=a[j];}
    }
    printf("%d",s);
}