// S5 14916: 거스름돈(DP,그리디)
// 그리디: 상수시간
// DP: 선형시간
#include<stdio.h>
#include<stdlib.h>

#define INF 100001

int main(void){
    int j;
    int n; scanf("%d",&n);
    if(n<=5){
        if(n==1){printf("-1");}
        if(n==2){printf( "1");}
        if(n==3){printf("-1");}
        if(n==4){printf( "2");}
        if(n==5){printf( "1");}
    }
    else{
        // 테이블 초기화
        int* t=(int*)malloc(sizeof(int)*(n+1));
        for(j=0;j<=n;j++){t[j]=INF;}
        t[0]=0;
     // t[1]=INF;
        t[2]=1;
     // t[3]=INF;
        t[4]=2;
        t[5]=1;

        // 점화식
        for(j=6;j<=n;j++){t[j]=(t[j-2]<t[j-5])?(t[j-2]+1):(t[j-5]+1);}

        // 결과 출력
        printf("%d",t[n]);
    }
}