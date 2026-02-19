// G4 17404: RGB거리 2(DP)
#include<stdio.h>
#include<stdlib.h>

#define INF 1000001

int dp(int* a,int* t,int n);

int main(void){
    int j;
    int n; scanf("%d",&n);
    int m; // min
    int c; // cost
    int* a=(int*)malloc(sizeof(int)*3*n); // 원본 배열
    int* t=(int*)malloc(sizeof(int)*3*n);

    for(j=0;j<=3*n-3;j+=3){scanf("%d %d %d",&a[j],&a[j+1],&a[j+2]);}
    t[0]=a[0]; t[1]=INF;  t[2]=INF;  c=dp(a,t,n); m=c;
    t[0]=INF;  t[1]=a[1]; t[2]=INF;  c=dp(a,t,n); m=(m<c)?m:c;
    t[0]=INF;  t[1]=INF;  t[2]=a[2]; c=dp(a,t,n); m=(m<c)?m:c;

    printf("%d",m);
    free(a);
    free(t);
}

int dp(int* a,int* t,int n){
    int j;
    for(j=3;j<=3*n-3;j+=3){
        t[j  ]=(t[j-2]<t[j-1])?(a[j  ]+t[j-2]):(a[j  ]+t[j-1]);
        t[j+1]=(t[j-3]<t[j-1])?(a[j+1]+t[j-3]):(a[j+1]+t[j-1]);
        t[j+2]=(t[j-3]<t[j-2])?(a[j+2]+t[j-3]):(a[j+2]+t[j-2]);
    }
    j-=3;
    if(t[0]!=INF){return (t[j+1]<t[j+2])?t[j+1]:t[j+2];}
    if(t[1]!=INF){return (t[j]  <t[j+2])?t[j]:  t[j+2];}
    if(t[2]!=INF){return (t[j]  <t[j+1])?t[j]:  t[j+1];}
}
