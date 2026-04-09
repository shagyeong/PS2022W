// P3 9249: 최장 공통 부분 문자열(SA,LCP,LRS)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 256 // 8비트 문자 환경
#define L 200002

char* s;
int* a; // SA
int* b; // lcp
int* i; // indexes of s
int* r; // character ranks
int* t; // temp of r
int* c; // count: 계수정렬
int l; // length of s
int m; // leng of c
int o;
int p;
int d; // location of dummy '?'

void lrs(void);
void manbermyers(void);
void kasai(void);

int main(void){
    s=(char*)malloc(sizeof(char)*L);
    scanf("%s",&s[0]);   l=strlen(s); s[l]='?'; d=l;
    scanf("%s",&s[l+1]); l=strlen(s); s[l]='\0';
    m=(l>N)?l:N;
    a=(int*)calloc(l,    sizeof(int));
    b=(int*)calloc(l,    sizeof(int));
    i=(int*)calloc(l,    sizeof(int));
    r=(int*)calloc(2*l+1,sizeof(int));
    t=(int*)calloc(2*l+1,sizeof(int));
    c=(int*)calloc(m+1,  sizeof(int));
    manbermyers();
    kasai();
    lrs();
    free(s);
    free(a);
    free(b);
    free(i);
    free(r);
    free(t);
    free(c);
}

void lrs(void){
    int j;
    m=0; // max of LCP
    p=-1; // starting point
    for(j=1;j<l;j++){
        if(((a[j]<d)&&(a[j-1]>d))||((a[j]>d)&&(a[j-1]<d))){
            if(b[j]>m){
                m=b[j];
                p=a[j];
            }
        }
    }
    printf("%d\n",m);
    for(j=0;j<m;j++){printf("%c",s[p+j]);}
}
void manbermyers(void){
    int j;
    for(j=0;j<l;j++){
        a[j]=j;
        r[j]=s[j];
    }
    for(j=0;  j< m;j++){c[j]=0;}
    for(j=0;  j< l;j++){c[r[j]]++;}
    for(j=1;  j< m;j++){c[j]+=c[j-1];}
    for(j=l-1;j>=0;j--){a[--c[r[j]]]=j;}
    for(o=1;o<l;o<<=1){
        p=0;
        for(j=l-o;j< l;j++){i[p++]=j;}
        for(j=0;  j< l;j++){if(a[j]>=o){i[p++]=a[j]-o;}}
        for(j=0;  j< m;j++){c[j]=0;}
        for(j=0;  j< l;j++){c[r[i[j]]]++;}
        for(j=1;  j< m;j++){c[j]+=c[j-1];}
        for(j=l-1;j>=0;j--){a[--c[r[i[j]]]]=i[j];}
        t[a[0]]=1;
        for(j=1;j<l;j++){t[a[j]]=t[a[j-1]]+(((r[a[j-1]]==r[a[j]])&&(r[a[j-1]+o]==r[a[j]+o]))?0:1);}
        for(j=0;j<l;j++){r[j]=t[j];}
        if(r[a[l-1]]==l){break;}
        m=l+1;
    }
}
void kasai(void){
    int j;
    int k;
    int h=0;
    b[0]=0;
    for(j=0;j<l;j++){
        k=r[j]-1;
        if(k>0){
            while((j+h<l)&&(a[k-1]+h<L)&&(s[j+h]==s[a[k-1]+h])){h++;}
            b[k]=h;
            if(h>0){h--;}
        }
    }
}