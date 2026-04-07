// P2 17844: 복붙하기(해시,라빈-카프,매개변수탐색)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 31 // 소문자 알파벳 환경
#define L 200001
#define D1 1000003 // hash divisor
#define D2 1000000007 // hash divisor: double hash

struct node{
    int v; // 원본 문자열 시작 위치
    int h2; // D2를 사용한 두 번째 해시
    int next;
};

char* s;
int* adjs;
struct node* pool;
int p;
int n;

long long int* h1s;
long long int* h2s;
long long int* u1s;
long long int* u2s;

void hash_init(int m); // precompute
int insert(int h1,int h2,int v,int m); // rolling hash값, 원본 문자열 시작 위치, 패턴 길이
int roll(char* s,int m); // rolling hash

int main(void){
    int a=-1; // answer
    int l=1;
    int m;
    int r;
    s=(char*)malloc(sizeof(char)*(L));
    scanf("%s",s);
    r=n=(int)strlen(s); s[n]='\0';
    adjs=(int*)calloc(D1,sizeof(int));
    pool=(struct node*)calloc(L,sizeof(struct node));
    
    r/=2; // disjoint
    hash_init(r); // precompute
    while(l<=r){
        p=0;
        memset(adjs,-1,sizeof(int)*D1);
        m=(l+r)/2;
        if(roll(s,m)==1){l=m+1; a=m;}
        else            {r=m-1;}
    }

    printf("%d",a);
    free(s);
    free(adjs);
    free(pool);
    free(h1s);
    free(h2s);
    free(u1s);
    free(u2s);
}

void hash_init(int m){
    int j;
    h1s=(long long int*)malloc(sizeof(long long int)*(m+1));
    h2s=(long long int*)malloc(sizeof(long long int)*(m+1));
    u1s=(long long int*)malloc(sizeof(long long int)*(m+1));
    u2s=(long long int*)malloc(sizeof(long long int)*(m+1));
    h1s[0]=1;
    h2s[0]=1;
    u1s[0]=0;
    u2s[0]=0;
    for(j=1;j<=m-1;j++){
        h1s[j]=h1s[j-1]*N; h1s[j]%=D1;
        h2s[j]=h2s[j-1]*N; h2s[j]%=D2;
    }
    for(j=1;j<=m;j++){
        u1s[j]=(u1s[j-1]*N+s[j-1])%D1;
        u2s[j]=(u2s[j-1]*N+s[j-1])%D2;
    }
}
int roll(char* s,int m){
    int j;
    long long int h1=h1s[m-1];
    long long int h2=h2s[m-1];
    long long int u1=u1s[m];
    long long int u2=u2s[m];

    for(j=0;j<=n-m;j++){
        if(insert(u1,u2,j,m)==1){return 1;}
        if(j<n-m){
            u1=(N*(u1-s[j]*h1)+s[j+m])%D1; if(u1<0){u1+=D1;}
            u2=(N*(u2-s[j]*h2)+s[j+m])%D2; if(u2<0){u2+=D2;}
        }
    }
    return -1;
}
int insert(int h1,int h2,int v,int m){
    int d=adjs[h1];
    while(d!=-1){
        if(pool[d].h2==h2){
            if(pool[d].v+m<=v){return 1;}
            else              {return -1;}
        }
        d=pool[d].next;
    }
    pool[p].v=v;
    pool[p].h2=h2;
    pool[p].next=adjs[h1];
    adjs[h1]=p++;
    return -1;
}