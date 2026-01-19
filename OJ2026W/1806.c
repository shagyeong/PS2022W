// G4 1806: 부분합(누적합,투포인터)
#include<stdio.h>

int main(void){
    int j;
    int n; int k; scanf("%d %d",&n,&k);
    int a[n]; for(j=0;j<n;j++){scanf("%d",&a[j]);}
    int f=0;      // front pointer
    int r=0;      // rear  pointer
    int s=0;      // sum
    int l=100001; // length
    
    while(1){
        if(s>=k){if((r-f)<l){l=r-f;}s-=a[f++];}
        else if(r==n){break;}
        else                       {s+=a[r++];}
    }

    if(l==100001){printf("0");}
    else         {printf("%d",l);}
}