// G1 10868: 최소값(세그먼트 트리)
#include<stdio.h>

int a[1000001]; // 원본 배열
int mintree[4000004]; // 최소값 세그먼트 트리

void  init_mintree(int n,int s,int e);
int query_mintree(int n,int s,int e,int l,int r);

int main(void){
    int j; // loop variable
    int n; int m;
    int u; int v;

    scanf("%d %d",&n,&m);
    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    init_mintree(1,0,n-1);

    for(j=0;j<m;j++){
        scanf("%d %d",&u,&v);
        printf("%d\n", query_mintree(1,0,n-1,u-1,(int)v-1));
    }
}

void init_mintree(int n,int s,int e){
    int m; // middle
    if(s==e){mintree[n]=a[s]; return;}
    m=(s+e)/2;
    init_mintree(2*n,  s,  m);      // lchild
    init_mintree(2*n+1,m+1,e);      // rchild
    mintree[n]=(mintree[2*n]<mintree[2*n+1])?mintree[2*n]:mintree[2*n+1]; // 최소값
}
int query_mintree(int n,int s,int e,int l,int r){
    int m; // middle
    if((l>e)||(r<s))    {return 1000000001;}
    if(((l<=s)&&(e<=r))){return mintree[n];}
    m=(s+e)/2;

    int x=query_mintree(2*n,s,m,l,r);
    int y=query_mintree(2*n+1,m+1,e,l,r);
    return (x<y)?x:y;
}