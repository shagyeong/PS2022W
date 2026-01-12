// P4 16975: 수열과 쿼리 21(느리게 갱신되는 세그먼트 트리)
#include<stdio.h>
long long int a[1000001]; // 원본 배열
long long int t[4000004]; // 구간합 트리
long long int p[4000004]; // lazy propagtion

void           init(int n,int s,int e);
void           lazy(int n,int s,int e);
void         update(int n,int s,int e,int l,int r,long long int v);
long long int query(int n,int s,int e,int l,int r);

int main(void){
    int j; // loop variable
    int n; int m;
    int o; int b; long long int c; long long int v;

    scanf("%d",&n);
    for(j=0;j<n;j++){scanf("%lld",&a[j]);}
    init(1,0,n-1);

    scanf("%d",&m);
    for(j=0;j<m;j++){
        scanf("%d",&o);
        if(o==1){
            scanf("%d %lld %lld",&b,&c,&v);
            update(1,0,n-1,b-1,(int)c-1,v);
        }
        else{
            scanf("%d",&b);
            printf("%lld\n",query(1,0,n-1,b-1,b-1));
        }
    }
}

void init(int n,int s,int e){
    int m; // middle
    if(s==e){t[n]=a[s]; return;}
    m=(s+e)/2;
    init(2*n,  s,  m);      // lchild
    init(2*n+1,m+1,e);      // rchild
    t[n]=t[2*n]+t[2*n+1]; // 구간합
}
void lazy(int n,int s,int e){
    if(p[n]!=0){
        t[n]+=(long long int)(e-s+1)*p[n];
        if(s!=e){
            p[2*n]  +=p[n];
            p[2*n+1]+=p[n];
        }
        p[n]=0;
    }
}
void update(int n,int s,int e,int l,int r,long long int v){
    int m; // middle
    lazy(n,s,e);
    if((l>e)||(r<s)){return;}
    if((l<=s)&&(e<=r)){
        p[n]+=v;
        lazy(n,s,e);
        return;
    }
    m=(s+e)/2;
    update(2*n,  s,  m,l,r,v);
    update(2*n+1,m+1,e,l,r,v);
    t[n]=t[2*n]+t[2*n+1];
}
long long int query(int n,int s,int e,int l,int r){
    int m; // middle
    lazy(n,s,e);
    if((l>e)||(r<s))  {return 0;}
    if((l<=s)&&(e<=r)){return t[n];}
    m=(s+e)/2;
    return query(2*n,s,m,l,r)+query(2*n+1,m+1,e,l,r);
}