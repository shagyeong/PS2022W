// G4 20040: 사이클 게임(분리 집합)
#include<stdio.h>

#define N 500000
int p[N]; // parent

int getroot(int q);
void unify(int u,int v);

int main(void){
    int j; // loop variable
    int n;
    int e;
    int u;
    int v;
    scanf("%d %d",&n,&e);
    for(j=0;j<n;j++){
        p[j]=j;
    }
    for(j=0;j<e;j++){
        scanf("%d %d",&u,&v);
        if(getroot(u)==getroot(v)){
            printf("%d",j+1);
            return 0;
        }
        unify(u,v);
    }
    printf("0");
    return 0;
}

int getroot(int q){
    if(p[q]==q){return q;}
    else       {return p[q]=getroot(p[q]);}
}
void unify(int u,int v){
    p[getroot(u)]=getroot(v);
}