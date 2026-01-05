// G5 2467: 용액(투포인터)
#include<stdio.h>

int abs(int i){return (i>0)?i:-i;}

int main(void){
    int j; // loop variable
    int l; // left
    int r; // right
    int u; // 정답 위치(left)
    int v; // 정답 위치(right)
    int m; // min: 최소값
    int s; // sum
    int n;scanf("%d",&n);
    int a[n];
    for(j=0;j<n;j++){scanf("%d",&a[j]);}

    l=0; r=n-1;
    u=l; v=r;
    m=abs(a[l]+a[r]);

    while(l<r){
        s=a[l]+a[r];
        if(m>abs(s)){
            m=abs(s);
            u=l;
            v=r;
        }
        if     (s<0){l++;}
        else if(s>0){r--;}
        else        {break;}
    }
    printf("%d %d",a[u],a[v]);
}

// 염기성 -1 ~ -1 000 000 000
// 산성 1 ~ 1 000 000 000
// int 사용

// 혼합 용액: 두 용액의 합
// "0에 가장 가까운" 용액을 만들고자 한다

// 용액수 N 2 ~ 100 000
// 용액: 오름차순으로 입력됨
// 여러 가지일 경우 아무거나 출력
// 출력: 오름차순 출력