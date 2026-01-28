// S5 9625: BABBA(DP)
#include<stdio.h>

int main(void){
    int j;
    int k; scanf("%d",&k);
    int t[2]={1,0};
    int a;
    int b;

    for(j=0;j<k;j++){
        a=t[0];
        b=t[1];
        t[0]-=a; t[0]+=b;
        t[1]+=a;
    }
    
    printf("%d %d",t[0],t[1]);
}