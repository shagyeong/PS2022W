// P3 13544: 수열과 쿼리 3(세그먼트트리,병합정렬트리)
#include<stdio.h>
#include<stdlib.h>

int  a[100001]; // 원본 배열
int* t[400004]; // 병합정렬 트리, int*: 가변 길이 배열 포인터

void  init(int n,int s,int e);
int  query(int n,int s,int e,int l,int r,int q);
int  search(int* b,int n,int q); // 부분배열 이분탐색

int main(void){
    int j;
    int n; int m;
    int u; int v;
    int q; // query
    int l=0; // 문제 조건: last answer

    scanf("%d",&n);
    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    init(1,0,n-1);
    
    scanf("%d",&m);
    for(j=0;j<m;j++){
        scanf("%d %d %d",&u,&v,&q);
        u=((~u)&l)|(u&(~l));
        v=((~v)&l)|(v&(~l));
        q=((~q)&l)|(q&(~l));
        printf("%d\n",l=query(1,0,n-1,u-1,v-1,q));
    }
}

void init(int n,int s,int e){
    int m; // middle
    int i; int j; int k;
    int L; int R;
    if(s==e){
        t[n]=(int*)malloc(sizeof(int));
        t[n][0]=a[s];
        return;
    }
    m=(s+e)/2;
    init(2*n,  s,  m);
    init(2*n+1,m+1,e);
    t[n]=(int*)malloc(sizeof(int)*(e-s+1));

    // merge
    i=0;j=0;k=0;
    L=m-s+1;
    R=e-m;
    while((i<L)&&(j<R)){
        if(t[2*n][i]<t[2*n+1][j]){t[n][k++]=t[2*n]  [i++];}
        else                        {t[n][k++]=t[2*n+1][j++];}
    }
    while(i<L){t[n][k++]=t[2*n  ][i++];}
    while(j<R){t[n][k++]=t[2*n+1][j++];}
}
int query(int n,int s,int e,int l,int r,int q){
    int m; // middle
    if((l>e)||(r<s)){return 0;}
    if((l<=s)&&(e<=r)){return (e-s+1)-search(t[n],e-s+1,q);}
    m=(s+e)/2;
    return query(2*n,s,m,l,r,q)+query(2*n+1,m+1,e,l,r,q);
}
int search(int* b,int n,int q){
    int s=0;    // start
    int m;      // middle
    int e=n;    // end
    while(s<e){
        m=(s+e)/2;
        if(b[m]<=q){s=m+1;}
        else       {e=m;}
    }
    return s;
}