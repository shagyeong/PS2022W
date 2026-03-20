// S1 14888: 연산자 끼워넣기(브루트포스,백트래킹)
#include<stdio.h>

int a[11];
int b[4];
int n;
int h; // 최대값
int l; // 최소값
void backtrack(int d,int c); // 자릿수, 누적값

int main(void){
    int j;
    scanf("%d",&n);
    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    for(j=0;j<4;j++){scanf("%d",&b[j]);}
    h=-1000000001;
    l= 1000000001;
    backtrack(0,a[0]);
    printf("%d\n",h);
    printf("%d\n",l);
}

void backtrack(int d,int c){
    if(d==n-1){
        h=(h>c)?h:c;
        l=(l<c)?l:c;
        return;
    }
    if(b[0]>0){b[0]-=1; backtrack(d+1,c+a[d+1]); b[0]+=1;}
    if(b[1]>0){b[1]-=1; backtrack(d+1,c-a[d+1]); b[1]+=1;}
    if(b[2]>0){b[2]-=1; backtrack(d+1,c*a[d+1]); b[2]+=1;}
    if(b[3]>0){b[3]-=1; backtrack(d+1,c/a[d+1]); b[3]+=1;}
}