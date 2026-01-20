// G2 10775: 공항(그리디,분리집합)
#include<stdio.h>

#define N 100001
int p[N]; // parent

int getroot(int q);
void  unify(int u,int v);

int main(void){
    int j;
    int g; int a; scanf("%d %d",&g,&a);
    int r;   // root
    int c=0; // answer
    for(j=0;j<=g;j++){p[j]=j;}

    for(j=0;j<a;j++){
        scanf("%d",&g);
        r=getroot(g);
        if(r==0){break;}
        unify(r,r-1);
        c+=1;
    }

    printf("%d",c);
}

int getroot(int q){
    if(p[q]==q){return q;}
    else       {return p[q]=getroot(p[q]);}
}
void unify(int u,int v){
    p[getroot(u)]=getroot(v);
}