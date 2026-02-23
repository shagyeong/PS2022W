// S1 13335: 트럭(구현,시뮤레이션,큐)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int j;
    int n; scanf("%d",&n);
    int l; scanf("%d",&l);
    int W; scanf("%d",&W);
    int bridge[l]; memset(bridge,0,sizeof(int)*l);
    int weights[n]; for(j=0;j<n;j++){scanf("%d",&weights[j]);}
    int i=0; // index of weights

    if(n==1){printf("%d",l+1); return 0;}

    int timer=1;
    int curweight=weights[i]; // 무게 총합
    bridge[l-1]  =weights[i++];

    while(1){
        timer+=1;
        curweight-=bridge[0];
        for(j=0;j<l-1;j++){bridge[j]=bridge[j+1];}
        if(curweight+weights[i]<=W){bridge[l-1]=weights[i]; curweight+=weights[i++]; if(i==n){timer+=l; break;}}
        else                       {bridge[l-1]=0;}
    }
    printf("%d",timer);
    return 0;
}