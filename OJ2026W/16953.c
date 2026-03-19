// S2 16953: A->B(BFS)
#include<stdio.h>
#include<stdlib.h>

struct node{
    int v;
    int d; // depth
};

int main(void){
    int a; int b; scanf("%d %d",&a,&b);
    struct node* q=(struct node*)malloc(sizeof(struct node)*50);
    struct node d;
    int f=0;
    int r=0;
    q[r  ].v=b;
    q[r++].d=1;
    while(f<r){
        d=q[f++];
        if(d.v==a){printf("%d",d.d); free(q); return 0;}
        if(d.v< a){continue;}
        if((d.v%2) ==0){q[r].v=d.v/2;     q[r++].d=d.d+1;}
        if((d.v%10)==1){q[r].v=(d.v-1)/10;q[r++].d=d.d+1;}
    }
    printf("-1");
    free(q);
    return 0;
}