// P3 13264: 접미사 배열 2(접미사배열,맨버-마이어스)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* g;
int  o; // offset
char s[100000];

int compare(const void* u,const void* v);
void mm(int l, int* a); // Manber-Myers

int main(void){
    int j;
    scanf("%s",s);
    int l=(int)(strlen(s));
    int* a=(int*)malloc(sizeof(int)*l);
    mm(l,a);
    for(j=0;j<l;j++){printf("%d\n",a[j]);}
}

int compare(const void* u,const void* v){
    if(g[*((int*)u)]!=g[*((int*)v)]){return g[*((int*)u)]-g[*((int*)v)];}
    return g[*((int*)u)+o]-g[*((int*)v)+o];
}
void mm(int l,int* a){
    int  j; // loop variable
    int* t=(int*)calloc(l*2+1,sizeof(int));
    g     =(int*)calloc(l*2+1,sizeof(int));
    for(j=0;j<l;j++){
        a[j]=j;
        g[j]=s[j];
    }
    for(o=1;o<l;o<<=1){
        qsort(a,l,sizeof(int),compare);
        t[a[0]]=1;
        for(j=1;j<l;j++){t[a[j]]=t[a[j-1]]+(compare(&a[j-1],&a[j])?1:0);}
        for(j=0;j<l;j++){g[j]=t[j];}
        if(g[a[l-1]]==l){break;}
    }
}