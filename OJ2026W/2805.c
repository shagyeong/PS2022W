// S2 2805: 나무 자르기(이분 탐색)
#include<stdio.h>

int main(void){
    long long b;  // 나무 획득량 버퍼
    int s=0;  // start
    int h;  // height(middle에 대응)
    int e=0;// end, 나무 최대 높이 저장
    int j;  // loop variable
    int n; int m; scanf("%d %d",&n,&m);
    int a[n];
    for(j=0;j<n;j++){scanf("%d",&a[j]);if(a[j]>e){e=a[j];}}

    while(s<=e){
        h=s+(e-s)/2;
        b=0;
        for(j=0;j<n;j++){b+=(a[j]>h)?a[j]-h:0;}
        if(b>=m){s=h+1;}
        else    {e=h-1;}
    }
    printf("%d",e);
}