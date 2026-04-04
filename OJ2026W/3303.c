// P3 3303: 가장 긴 문자열(해시,라빈-카프,매개변수탐색)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 26 // 소문자 알파벳 환경
#define D 1000007 // hash divisor

struct node{
    int v; // 원본 문자열 시작 위치
    struct node* next;
};

char* s;
struct node** hash;

void reset(void);
int insert(int h,int v,int m); // rolling hash값, 원본 문자열 시작 위치, 패턴 길이
int roll(char* s,int m); // rolling hash

int main(void){
    int n; scanf("%d",&n);
    int a=0; // answer
    int l=1;
    int m;
    int r=n;
    s=(char*)malloc(sizeof(char)*(n+1)); scanf("%s",s); s[n]='\0';
    hash=(struct node**)calloc(D,sizeof(struct node*));    

    while(l<=r){
        m=(l+r)/2;
        if(roll(s,m)==1){l=m+1; a=m;}
        else            {r=m-1;}
        reset();
    }
    printf("%d",a);
    free(s);
    free(hash);
}

int roll(char* s,int m){
    int j;
    int n=(int)strlen(s);

    long long int h=1;
    long long int u=0;

    for(j=0;j<m-1;j++){h*=N;h%=D;}
    for(j=0;j<m;  j++){u=(u*N+s[j])%D;}

    for(j=0;j<=n-m;j++){
        if(insert(u,j,m)==1){return 1;}
        if(j<n-m){
            u=(N*(u-s[j]*h)+s[j+m])%D;
            if(u<0){u+=D;}
        }
    }
    return -1;
}
void reset(void){
    int j;
    struct node* d;
    struct node* f;
    for(j=0;j<D;j++){
        d=hash[j];
        while(d!=NULL){
            f=d;
            d=d->next;
            free(f);
        }
        hash[j]=NULL;
    }
}
int insert(int h,int v,int m){
    int j;
    int f;
    struct node* d=hash[h];
    while(d!=NULL){
        f=1;
        for(j=0;j<m;j++){if(s[d->v+j]!=s[v+j]){f=0; break;}}
        if(f==1){return 1;}
        d=d->next;
    }
    d=(struct node*)malloc(sizeof(struct node));
    d->v=v;
    d->next=hash[h];
    hash[h]=d;
    return -1;
}