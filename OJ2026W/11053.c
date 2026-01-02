// S2 11053: 가장 긴 증가하는 부분 수열(LIS)
#include <stdio.h>

int main(void){
    int j; // loop variable
    int k; // loop variable
    int n; scanf("%d",&n);
    int a[n]; for(j=0;j<n;j++){scanf("%d",&a[j]);}
    int t[n];
    int l=0;  // length of LIS
    for(j=0;j<n;j++){
        t[j]=1;
        for(k=0;k<j;k++){if((a[k]<a[j])&&(t[j]<t[k]+1)){t[j]=t[k]+1;}}
        if(l<t[j]){l=t[j];}
    }
    printf("%d",l);
}