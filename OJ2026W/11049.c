// G3 11049: 행렬곱셈순서(DP)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j; int k; int l;
    int n; scanf("%d",&n);
    int** t=(int**)malloc(sizeof(int*)*n);
    int*  d=(int*) malloc(sizeof(int) *n*n);
    int*  r=(int*) malloc(sizeof(int)*n);
    int*  c=(int*) malloc(sizeof(int)*n);
    k=0;
    for(j=0;j<n;j++){
        scanf("%d %d",&r[j],&c[j]);
        t[j]=d+k; k+=n;
    }
    for(j=0;j<n;j++){for(k=0;k<n;k++){t[j][k]=0;}}

    for(j=1;  j< n;j++){
    for(k=j-1;k>=0;k--){
        t[k][j]=t[k][k]+t[k+1][j]+r[k]*c[k]*c[j];
    for(l=k+1;l<j;l++){
        t[k][j]=(t[k][j]<t[k][l]+t[l+1][j]+r[k]*c[l]*c[j])?t[k][j]:t[k][l]+t[l+1][j]+r[k]*c[l]*c[j];
    }}}

    printf("%d\n", t[0][n-1]);
    free(r);
    free(c);
    free(d);
    free(t);
}