// G4 27172: 수 나누기 게임(정수론)
#include <stdio.h>

int a[1000001]; // 입력 카드
int p[1000001]; // 카드 존재 마크
int s[1000001]; // 점수

int main(void){
    int j; int k;
    int n; scanf("%d",&n);
    int m=0; // max: 입력 카드 최대값
    int c;   // current card

    for(j=1;j<=n;j++){
        scanf("%d",&a[j]);
        p[a[j]]=1;
        m=(a[j]>m)?a[j]:m;
    }

    for(j=1;j<=n;j++){
        c=a[j];
        for(k=2*c;k<=m;k=k+c){
        if(p[k]){
            s[c]+=1;
            s[k]-=1;
        }}
    }

    for(j=1;j<=n;j++){printf("%d ",s[a[j]]);}
}