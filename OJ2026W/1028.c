// P5 1028: 다이아몬드 광산(DP)
#include<stdio.h>

int main(void){
    int n=0; // answer
    int l;   // length
    int j; int k;
    int r; int c; scanf("%d %d",&r,&c);

    // 테이블 초기화
    int a[r][c];
    int u[r][c];
    int d[r][c];
    for(j=0;j<r;j++){
    for(k=0;k<c;k++){
        scanf("%1d",&a[j][k]);
        u[j][k]=0;
        d[j][k]=0;
    }}

    // 점화식
    for(j=0;j<r;j++){
    for(k=0;k<c;k++){
        if(a[j][k]==1){
            u[j][k]=((j>0)&&(k>0  ))?u[j-1][k-1]+1:1;
            d[j][k]=((j>0)&&(k<c-1))?d[j-1][k+1]+1:1;
        }
    }}
    for(j=0;j<r;j++){
    for(k=0;k<c;k++){
        if(a[j][k]==1){
            l=(u[j][k]<d[j][k])?u[j][k]:d[j][k];
            l+=1;
            while((--l)>n){
                if((d[j-(l-1)][k-(l-1)]>=l)&&(u[j-(l-1)][k+(l-1)]>=l)){
                    n=l;
                    break;
                }
            }
        }
    }}

    // 결과 출력
    printf("%d",n);
}