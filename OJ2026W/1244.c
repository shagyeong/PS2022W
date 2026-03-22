// S4 1244: 스위치 켜고 끄기(구현,시뮬레이션)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j; int k;
    int n; scanf("%d",&n);
    int* a=(int*)malloc(sizeof(int)*(n+1)); for(j=1;j<=n;j++){scanf("%d",&a[j]);}
    int m; scanf("%d",&m);
    int o; int v;
    for(j=0;j<m;j++){
        scanf("%d %d",&o,&v);
        if(o==1){for(k=v;k<=n;k+=v){a[k]^=1;}}
        if(o==2){
            a[v]^=1;
            k=1;
            while(1){
                if(((v-k)<=0)||(n<(v+k))){break;}
                if(a[v-k]!=a[v+k])     {break;}
                a[v-k]^=1;
                a[v+k]^=1;
                k++;
            }
        }
    }
    for(j=1;j<=n;j++){
        if((j%20)==0){printf("%d\n",a[j]);}
        else{printf("%d ",a[j]);}
    }
    free(a);
}