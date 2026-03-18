// S3 33911: 특별상 눈치게임(브루트포스)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j; int k; int l; int m; // loop variable
    int* a=(int*)calloc(101,sizeof(int));
    int b=0; // answer
    int f; // flag
    int n; scanf("%d",&n);
    int u; int v; int w;
    for(j=0;j<n;j++){scanf("%d %d %d",&u,&v,&w); a[u]++; a[v]++; a[w]++;}

    for(j=1;  j<=98; j++){
    for(k=j+1;k<=99; k++){
    for(l=k+1;l<=100;l++){
        f=0;
        a[j]++; a[k]++; a[l]++;
        if(a[l]==1){for(m=l+1;m<=100;m++){if(a[m]==1){goto escape;}} if(m==101){f=1; goto escape;}}
        if(a[k]==1){for(m=k+1;m<=100;m++){if(a[m]==1){goto escape;}} if(m==101){f=1; goto escape;}}
        if(a[j]==1){for(m=j+1;m<=100;m++){if(a[m]==1){goto escape;}} if(m==101){f=1; goto escape;}}
        escape:
        b+=f;
        a[j]--; a[k]--; a[l]--;
    }}}
    printf("%d",b);
    free(a);
}