// S5 34704: 크기가 4인 박스(그리디)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; scanf("%d",&n);
    int v;
    int a[5];
    int w=0; // answer
    for(j=0;j<=4;j++){a[j]=0;}
    for(j=0;j< n;j++){scanf("%d",&v); a[v]++;}
    w+=a[4];
    w+=a[3];
    if(a[2]%2==0){w+=a[2]/2;}
    else         {w+=(a[2]/2+1); a[1]-=2; if(a[1]<0){a[1]=0;}}
    a[1]-=a[3];
    if(a[1]<0){a[1]=0;}

    if(a[1]%4==0){w+=a[1]/4;}
    else         {w+=(a[1]/4+1);}
    printf("%d",w);
}