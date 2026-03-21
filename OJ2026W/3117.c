// G1 3117: YouTube(희소배열)
#include<stdio.h>
#include<stdlib.h>

#define L 31 // log2 N

int n;
int m;
int l;
int*  stud;
int** pare; // [N][L]
int* _pare;

int   query(int u);
void sparse(void);
void   init(void);
void  clean(void);

int main(void){
    int j;
    scanf("%d %d %d",&n,&m,&l); init();
    for(j=0;j<n ;j++){scanf("%d",&stud[j]);}
    for(j=1;j<=m;j++){scanf("%d",&pare[j][0]);}
    sparse();

    l-=1;
    for(j=0;j<n;j++){printf("%d ",query(stud[j]));}
    clean();
}

int   query(int u){
    int j;
    for(j=0;j<L;j++){if(((l>>j)&1)==1){u=pare[u][j];}}
    return u;
}
void sparse(void){
    int j; int k;
    for(j=1;j< L;j++){
    for(k=1;k<=m;k++){
        pare[k][j]=pare[pare[k][j-1]][j-1];
    }}
}
void   init(void){
    int j; int k=0;
    stud=(int*)malloc(sizeof(int)*(n));
    pare=(int**)calloc(m+1,    sizeof(int*));
    _pare=(int*)calloc((m+1)*L,sizeof(int));
    for(j=0;j<=m;j++){pare[j]=_pare+k; k+=L;}
}
void  clean(void){
    free(stud);
    free(_pare);
    free(pare);
}

// // G1 17435: 합성함수와 쿼리(희소배열)
// #include<stdio.h>
// #include<stdlib.h>

// #define L 20 // log2 N

// int m;
// int q;
// int** pare; // [N][L]
// int* _pare;

// int   query(int d,int u);
// void sparse(void);
// void   init(void);
// void  clean(void);

// int main(void){
//     int j;
//     int n; int x;
//     scanf("%d",&m); init();
//     for(j=1;j<=m;j++){scanf("%d",&pare[j][0]);}
//     sparse();

//     scanf("%d",&q);
//     for(j=0;j<q;j++){
//         scanf("%d %d",&n,&x);
//         printf("%d\n",query(n,x));
//     }
//     clean();
// }

// int   query(int d,int u){
//     int j;
//     for(j=0;j<L;j++){if(((d>>j)&1)==1){u=pare[u][j];}}
//     return u;
// }
// void sparse(void){
//     int j; int k;
//     for(j=1;j< L;j++){
//     for(k=1;k<=m;k++){
//         pare[k][j]=pare[pare[k][j-1]][j-1];
//     }}
// }
// void   init(void){
//     int j; int k=0;
//     pare=(int**)calloc(m+1,sizeof(int*));
//     _pare=(int*)calloc((m+1)*L,sizeof(int));
//     for(j=0;j<m+1;j++){pare[j]=_pare+k; k+=L;}
// }
// void  clean(void){
//     free(_pare);
//     free(pare);
// }