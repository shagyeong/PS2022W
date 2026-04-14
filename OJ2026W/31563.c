// S2 31563: 수열 회전과 쿼리(누적합)
// 환형누적합
// 1 우측으로 밀기: 포인터 좌측으로
// 2 좌측으로 밀기: 포인터 우측으로
// 3 누적합
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; int m; scanf("%d %d",&n,&m);
    int o; int u; int v;
    int p=0;
    long long int* a=(long long int*)calloc(2*n+1,sizeof(long long int));
    long long int* s=(long long int*)calloc(2*n+1,sizeof(long long int));
    for(j=1;j<=  n;j++){scanf("%d",&v);a[j]=v;a[j+n]=v;}
    for(j=1;j<=2*n;j++){s[j]=s[j-1]+a[j];}

    for(j=0;j<m;j++){
        scanf("%d",&o);
        if     (o==1){scanf("%d",&u); p-=u; if(p>=n){p%=n;}else if(p<=-n){p=-((-p)%n);}}
        else if(o==2){scanf("%d",&u); p+=u; if(p>=n){p%=n;}else if(p<=-n){p=-((-p)%n);}}
        else if(o==3){
            scanf("%d %d",&u,&v);
            u+=p;
            v+=p;
            if     (u<0){u+=n;}
            else if(u>n){u%=n;}
            if     (v<0){v+=n;}
            else if(v>n){v%=n;}
            if(u==0){u=n;}
            if(u<=v){printf("%lld\n",s[v]  -s[u-1]);}
            else    {printf("%lld\n",s[v+n]-s[u-1]);}
        }
    }
    free(a);
    free(s);
}