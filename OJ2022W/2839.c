// S4 2839: 설탕 배달(DP,그리디)
#include<stdio.h>
#include<stdlib.h>

#define INF 5000

int main(void){
    int j;
    int n; scanf("%d",&n);
    if(n<=7){
        // if(n==1){printf("-1");} // 3 <=N<=5000
        // if(n==2){printf("-1");} // 3 <=N<=5000
        if(n==3){printf( "1");}
        if(n==4){printf("-1");}
        if(n==5){printf( "1");}
        if(n==6){printf( "2");}
        if(n==7){printf("-1");}
    }
    else{
        // 테이블 초기화
        int* t=(int*)malloc(sizeof(int)*(n+1));
        for(j=0;j<=n;j++){t[j]=INF;}
        t[0]=0;
     // t[1]=INF; t[2]=INF;
        t[3]=1;
     // t[4]=INF;
        t[5]=1; t[6]=2;
     // t[7]=INF;

        // 점화식
        for(j=8;j<=n;j++){t[j]=(t[j-3]<t[j-5])?(t[j-3]+1):(t[j-5]+1);}

        // 결과 출력
        printf("%d",t[n]);
    }
}