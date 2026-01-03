// G5 1717: 집합의 표현(분리 집합)
#include<stdio.h>

#define N 1000001
int p[N]; // parent

int getroot(int q);
void unify(int u,int v);

int main(void){
    int j; // loop variable
    int c; // 연산 종류: 0(unify), 1(query)
    int n; int m;
    int a; int b;
    scanf("%d %d",&n,&m);
    for(j=0;j<=n;j++){p[j]=j;}
    for(j=0;j< m;j++){
        scanf("%d %d %d",&c,&a,&b);
        if(c==0){
            if(a!=b){unify(a,b);}
        }
        else{ // printf("%d \t %d",a,b);
            if(a==b)                      {printf("YES\n");}
            else{
                if(getroot(a)==getroot(b)){printf("YES\n");}
                else                      {printf("NO\n");}
            }
        }
    }
}

int getroot(int q){
    if(p[q]==q){return q;}
    else       {return p[q]=getroot(p[q]);}
}
void unify(int u,int v){
    p[getroot(u)]=getroot(v);
}