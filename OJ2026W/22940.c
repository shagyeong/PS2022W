// P5 22940: 선형 연립 방정식(선형대수,해 구성)
#include <stdio.h>

int main(void){
    long long int j; // loop variable
    long long int k; // loop variable
    long long int l; // loop variable
    long long int n;
    long long int r; // 행 교환 인덱스
    long long int t; // 행 교환 tmp
    long long int p=1; // 피벗: 오버플로우 방지
    scanf("%lld",&n);
    long long int m[n][n+1];
    long long int s[n]; // solution 열벡터
    for(j=0;j<n;j++){
        for(k=0;k<n+1;k++){
            scanf("%lld",&m[j][k]);
        }
    }

    // 전향소거법: 실수 연산 불확실성 제거
    for(j=0;j<n;j++){
        r=j;
        if(m[j][j]==0){ // 대각선 성분 확인: 행 교환 위치 설정
            r=j+1;
            for(k=j+1;k<n;k++){
                if(m[k][j]!=0){break;}
                else          {r++;}
            }
        }
        if(r!=j){    // 행교환
            for(l=0;l<=n;l++){
                t=m[j][l];
                m[j][l]=m[r][l];
                m[r][l]=t;
            }
        }
        for(k=j+1;k<n;k++){
            for(l=n;l>=j;l--){
                m[k][l]=(m[k][l]*m[j][j])-(m[j][l]*m[k][j]);
                m[k][l]/=p;
            }
        }
        p=m[j][j];
    }

    // 후방대입법
    for(j=n-1;j>=0;j--){
        s[j]=m[j][n];
        for(k=j+1;k<n;k++){s[j]-=m[j][k]*s[k];}
        s[j]=s[j]/m[j][j];
    }
    
    // 해 출력
    for(j=0;j<n;j++){printf("%lld ",s[j]);}
}