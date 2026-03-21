// S3 9658: 돌 게임 4(게임이론,DP)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; scanf("%d",&n);
    int a[1001]; // 선 승리 0, 후 승리 1
    a[1]=1; // 1
    a[2]=0; // 1 - 1
    a[3]=1; // 1 - 1 - 1
    a[4]=0; // 1 - 1 - 1 - 1, 3 - 1
    a[5]=0; // 4 - 1
    for(j=6;j<=n;j++){ // 후 승리 DP
        if((a[j-1]==0)&&(a[j-3]==0)&&(a[j-4]==0)){a[j]=1;}
        else                                     {a[j]=0;}
    }
    if(a[n]==0){printf("SK");}
    else       {printf("CY");}
}