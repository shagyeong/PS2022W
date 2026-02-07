// G2 16565: N포커(DP,조합론)

// 숏코딩: 4바이트 고정폭 정답 문자열
//char* s="   0   0   0  13 624465746947698 95243306075456673939798253216685707649414515610 360905472646421 7357912853815775488377937008588612777805472 78916346898913323425811795518501743 97742827147 53620861326  52   1";__libc_start_main(){long long n=0;char b[4];read(0,b,3);for(int j=0;b[j]>47;j++){n=10*n+(b[j]-48);}char* p=s+(n-1)*4;while(*p==32){p++;}_Exit(!write(1,p,(s+4*n)-p));}main;

#include<stdio.h>
#include<stdlib.h>

#define D 10007 // divisor

int solve(int n);

int main(void){
    int n; scanf("%d",&n);
    printf("%d",solve(n));
}

int solve(int n){
    if(n==1){return 0;}
    if(n==2){return 0;}
    if(n==3){return 0;}
    int j; int k;
    int a=0; // answer
    int** c=(int**)malloc(sizeof(int*)*53); // combination
    int*  d=(int*) malloc(sizeof(int) *53*53);
    for(j=0;j<=52;j++){c[j]=d+53*j;}
    for(j=0;j<=52;j++){c[j][0]=1; c[j][j]=1;}
    for(j=1;j<=52;j++){for(k=1;k<j;k++){c[j][k]=(c[j-1][k-1]+c[j-1][k])%D;}}

    for(j=1;j<=n/4;j++){
        if(j%2==0){a-=(c[13][j]*c[52-4*j][n-4*j])%D;a+=D;a%=D;}
        else{      a+=(c[13][j]*c[52-4*j][n-4*j])%D;     a%=D;}
    }
    free(d);
    free(c);
    return a;
}
