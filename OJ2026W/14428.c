// G1 14428: 수열과 쿼리 16(세그먼트트리)
#include<stdio.h>
#include<stdlib.h>

struct node{
    int i; // index
    int v; // value
};

int*         a; // 원본 배열
struct node* t; // 최소값 세그먼트 트리

void         init(int n,int s,int e);
void       update(int n,int s,int e,int i,int v);
struct node query(int n,int s,int e,int l,int r);

int main(void){
    int j; // loop variable
    int n; int m;
    int o; int u; int v;

    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    t=(struct node*)malloc(sizeof(struct node)*n*4);
    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    init(1,0,n-1);

    scanf("%d",&m);
    for(j=0;j<m;j++){
        scanf("%d %d %d",&o,&u,&v);
        if(o==1){update(1,0,n-1,u-1,v); a[u-1]=v;}
        else{printf("%d\n",query(1,0,n-1,u-1,v-1).i+1);} // +1: 0부터 시작하는 원본 배열
    }
}

void         init(int n,int s,int e){
    int m; // middle
    if(s==e){
        t[n].i=s;
        t[n].v=a[s];
        return;
    }
    m=(s+e)/2;
    init(2*n,  s,  m);      // lchild
    init(2*n+1,m+1,e);      // rchild
    t[n].i=(t[2*n].v<=t[2*n+1].v)?t[2*n].i:t[2*n+1].i;
    t[n].v=(t[2*n].v<=t[2*n+1].v)?t[2*n].v:t[2*n+1].v;
}
void       update(int n,int s,int e,int i,int v){
    int m; // middle
    if((i<s)||(i>e))  {return;}
    if(s==e){t[n].v=v; return;}
    m=(s+e)/2;
    update(2*n,  s,  m,i,v);
    update(2*n+1,m+1,e,i,v);
    t[n].i=(t[2*n].v<=t[2*n+1].v)?t[2*n].i:t[2*n+1].i;
    t[n].v=(t[2*n].v<=t[2*n+1].v)?t[2*n].v:t[2*n+1].v;
}
struct node query(int n,int s,int e,int l,int r){
    int m; // middle
    struct node i={-1,1000000001}; // inf
    if((l>e)||(r<s))    {return i;}
    if(((l<=s)&&(e<=r))){return t[n];}
    m=(s+e)/2;

    struct node x=query(2*n,  s,  m,l,r);
    struct node y=query(2*n+1,m+1,e,l,r);
    return (x.v<=y.v)?x:y;
}