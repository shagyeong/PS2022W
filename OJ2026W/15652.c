// S3 15652: N과 M (4)(재귀,백트래킹)
#include<stdio.h>

int a[9];
int n;
int m;
void backtrack(int d,int s);

int main(void){
    scanf("%d %d",&n,&m);
    backtrack(0,2);
}

void backtrack(int d,int s){
    int j;
    if(d==m){for(j=0;  j< m;j++){printf("%d ",a[j]);} printf("\n");}
    else    {for(j=s-1;j<=n;j++){a[d]=j; backtrack(d+1,j+1);}}
}