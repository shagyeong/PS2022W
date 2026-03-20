// S2 1182: 부분수열의 합(브루트포스,백트래킹)
#include<stdio.h>

int a[20];
int n; int m;
int w; // answer
void backtrack(int d,int c); // 자릿수, 누적값

int main(void){
    int j;
    scanf("%d %d",&n,&m);
    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    w=0;
    for(j=0;j<n;j++){backtrack(j,a[j]);}
    printf("%d",w);
}

void backtrack(int d,int c){
    int j;
    if(c==m){w++;}
    for(j=d+1;j<n;j++){backtrack(j,c+a[j]);}
}