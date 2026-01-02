// G4 1532: 동전 교환(그리디, 많은 조건 분기)
#include<stdio.h>

int exchange(int g,int s,int b,int G,int S,int B);

int main(void){
    int g; int s; int b;
    int G; int S; int B;
    scanf("%d %d %d",&g,&s,&b);
    scanf("%d %d %d",&G,&S,&B);
    printf("%d",exchange(g,s,b,G,S,B));
}

int exchange(int g,int s,int b,int G,int S,int B){
    int a=0; // answer(교환 횟수)
    if(g<G){
        while((g<G)&&(s>=11)){a+=1;g+=1;s-=11;}
        while((g<G)&&(b>=11)){a+=1;s+=1;b-=11;if(s>=11){a+=1;g+=1;s-=11;}}
        if(g<G){return -1;}
    }
    if(s<S){
        while((s<S)&&(g>G)){  a+=1;s+=9;g-=1;}
        while((s<S)&&(b>=11)){a+=1;s+=1;b-=11;}
        if(s<S){return -1;}
    }
    if(b<B){
        while((b<B)&&(s>S)){a+=1; b+=9; s-=1;}
        while((b<B)&&(g>G)){a+=1;       s+=9; g-=1; while((b<B)&&(s>S)){a+=1; b+=9; s-=1;}}
        if(b<B){return -1;}
    }
    return a;
}