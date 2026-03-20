// G4 9663: N-Queen(브루트포스,백트래킹)
#include<stdio.h>
#include<stdlib.h>

int n;
int a;
int* c;
int* r; // 우상향 대각선
int* l; // 좌상향 대각선

void backtrack(int d);
void init(int n);
void clean(void);

int main(void){
    scanf("%d",&n); init(n);
    backtrack(0);
    printf("%d",a); clean();
}

void backtrack(int d){
    if(d==n){a+=1; return;}
    int j;
    for(j=0;j<n;j++){
        if((c[j]==1)||(r[d+j]==1)||(l[d-j+n-1]==1)){continue;}
        c[j]=r[d+j]=l[d-j+n-1]=1; backtrack(d+1);
        c[j]=r[d+j]=l[d-j+n-1]=0;
    }
}
void init(int n){
    c=(int*)calloc(n,sizeof(int));
    r=(int*)calloc(n*2,sizeof(int));
    l=(int*)calloc(n*2,sizeof(int));
}
void clean(void){
    free(c);
    free(r);
    free(l);
}