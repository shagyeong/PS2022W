// S1 1149: RGB거리(DP)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int r; int g; int b;
    int n; scanf("%d",&n);
    int m; // min
    int* t=(int*)malloc(sizeof(int)*3*n);
    scanf("%d %d %d",&t[0],&t[1],&t[2]);
    for(j=3;j<=3*n-3;j+=3){
        scanf("%d %d %d",&r,&g,&b);
        t[j  ]=(t[j-2]<t[j-1])?(r+t[j-2]):(r+t[j-1]);
        t[j+1]=(t[j-3]<t[j-1])?(g+t[j-3]):(g+t[j-1]);
        t[j+2]=(t[j-3]<t[j-2])?(b+t[j-3]):(b+t[j-2]);
    }

    n=3*n-3;
    m=t[n];
    m=(m<t[n+1])?m:t[n+1];
    m=(m<t[n+2])?m:t[n+2];
    printf("%d",m);
    free(t);
}