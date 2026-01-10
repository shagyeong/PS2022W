// G1 2263: 트리의 순회(DFS,분할정복,재귀)
#include<stdio.h>
#include<stdlib.h>

struct tree{
    int  n; // number of item
    int* i; // indorder: 중위 순회 결과
    int* l; // location: 중위 순회 결과 인덱스
    int* p; // postorder: 후위 순회 결과
};

void dfs(struct tree* t,int is,int ie,int ps,int pe);

int main(void){
    int j;
    int n; scanf("%d",&n);
    struct tree t;
    t.n=n;
    int i[n+1]; i[0]=0; t.i=&i[0];
    int l[n+1]; l[0]=0; t.l=&l[0];
    int p[n+1]; p[0]=0; t.p=&p[0];
    for(j=1;j<=n;j++){scanf("%d",&t.i[j]); t.l[t.i[j]]=j;}
    for(j=1;j<=n;j++){scanf("%d",&t.p[j]);}
    dfs(&t,1,n,1,n);
}

void dfs(struct tree* t,int is,int ie,int ps,int pe){
    if(is>ie){return;}
    int r=t->p[pe];
    int l=t->l[r];
    printf("%d ",r);
    dfs(t,is, l-1,ps,       ps+(l-is)-1);
    dfs(t,l+1, ie,ps+(l-is),pe-1);
}