// S3 15651: N과 M 3(재귀,백트래킹)
#include<stdio.h>

int a[9];
int n;
int m;
void backtrack(int d);

int main(void){
    scanf("%d %d",&n,&m);
    backtrack(0);
}

void backtrack(int d){
    int j;
    if(d==m){for(j=0;j< m;j++){printf("%d ",a[j]);} printf("\n"); return;}
    else    {for(j=1;j<=n;j++){a[d]=j;backtrack(d+1);}}
}