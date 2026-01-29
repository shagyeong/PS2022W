// P3 3830: 교수님은 기다리지 않는다(분리집합)
#include<stdio.h>

#define N 100001

int p[N]; // parent
long long int d[N]; // difference

void init(int n);
int getroot(int q);
void  unify(int u,int v,int w);

int main(void){
    int j;
    int n; int m;
    char o;
    int u; int v; int w;
    while(1){
        scanf("%d %d",&n,&m);
        if((n==0)&&(m==0)){break;}
        init(n);

        for(j=0;j<m;j++){
            scanf(" %c",&o);
            if(o=='!'){
                scanf("%d %d %d",&u,&v,&w);
                unify(u,v,w);
            }
            else{
                scanf("%d %d",&u,&v);
                if(getroot(u)!=getroot(v)){printf("UNKNOWN\n");}
                else                      {printf("%lld\n",d[v]-d[u]);}
            }
        }
    }
}

void init(int n){
    int j;
    for(j=0;j<=n;j++){
        p[j]=j;
        d[j]=0;
    }
}
int getroot(int q){
    if(p[q]==q){return q;}
    int r=getroot(p[q]); // root
    d[q]+=d[p[q]];
    return p[q]=r;
}
void unify(int u,int v,int w){
    int x=getroot(u);
    int y=getroot(v);
    if(x!=y){
        p[x]=y;
        d[x]=(long long int)d[v]-d[u]-w;
    }
}