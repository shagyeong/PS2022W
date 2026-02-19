// G2 1256: 사전(DP,조합론)
#include<stdio.h>
#include<stdlib.h>

#define INF 1000000001

int main(void){
    int j;
    int k=0;
    int i=0;
    int n; scanf("%d",&n);
    int m; scanf("%d",&m);
    int q; scanf("%d",&q);
    int l=n+m;
    char* s=   (char*)malloc(sizeof(char)*(l+1)); s[l]='\0';
    int** comb=(int**)malloc(sizeof(int*)*(l+1));
    int*  data=(int*) malloc(sizeof(int) *(l+1)*(l+1));
    for(j=0;j<=l;j++){comb[j]=data+k; k+=(l+1);}
    comb[0][0]=1;
    for(j=1;j<=l;j++){
        comb[j][0]=1;
        comb[j][j]=1;
        for(k=1;k<j;k++){
            if(comb[j-1][k-1]+comb[j-1][k]<=INF){comb[j][k]=comb[j-1][k-1]+comb[j-1][k];}
            else                                {comb[j][k]=INF;}
        }
    }

    if(comb[l][m]<q){printf("-1");}
    else{
        while(i<l){
            if(n>0){
                if(q<=comb[n+m-1][m]){s[i++]='a';                    n--;}
                else                 {s[i++]='z'; q-=comb[n+m-1][m]; m--;}
            }
            else                     {s[i++]='z';                    m--;}
        }
        printf("%s",s);
    }

    free(data);
    free(comb);
    free(s);
}