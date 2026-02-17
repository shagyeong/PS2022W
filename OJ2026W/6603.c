// S2 6603: 로또(조합론,재귀,백트래킹)
#include<stdio.h>

int n;
int m;
int a[12]; // 원본 배열
int t[12];
void backtrack(int d,int s);

int main(void){
    int j=-1; // -1: 최초 진입시 줄바꿈 안함
    m=6;
    while(1){
        scanf("%d",&n); if(n==0){break;}
        if(j!=-1){printf("\n");}
        for(j=0;j<n;j++){scanf("%d",&a[j]);}
        backtrack(0,0);
    }
}

void backtrack(int d,int s){
    int j;
    if(d==m){for(j=0;j<m;j++){printf("%d ",t[j]);}printf("\n");}
    else    {for(j=s;j<n;j++){t[d]=a[j]; backtrack(d+1,j+1);}}
}
