// S1 14889: 스타트와 링크(브루트포스,백트래킹)
#include<stdio.h>

int a[20][20];
int v[20];
int n;
int l; // 최소값
void backtrack(int d,int c); // 팀원 수, 팀원 인덱스

int main(void){
    int j; int k;
    scanf("%d",&n);
    for(j=0;j<n;j++){for(k=0;k<n;k++){
        scanf("%d",&a[j][k]);
        v[j]=0;
    }}

    l=100000;
    v[0]=1;
    backtrack(1,0);
    printf("%d",l);
}

void backtrack(int d,int c){
    int j; int k;
    int s; int f; // 양 팀 능력치    
    if(d==(n/2)){
        s=0;
        f=0;
        for(j=0;j<n;j++){for(k=0;k<n;k++){
            if((v[j]==1)&&(v[k]==1)){s+=a[j][k];}
            if((v[j]==0)&&(v[k]==0)){f+=a[j][k];}
        }}
        s=((s-f)>=0)?(s-f):(f-s);
        l=(l<s)?l:s;
        return;
    }
    for(j=c+1;j<n;j++){
        v[j]=1; backtrack(d+1,j);
        v[j]=0;
    }
}