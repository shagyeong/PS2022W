// G2 4195: 친구 네트워크(해시,분리집합)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

# define N 200000

int* p; // parent
int* s; // size

int getroot(int q);
void  unify(int u,int v);


int I; // node id

struct node{
    char s[21];
    int v;
    struct node* next;
};
struct hash{
    int n; // hash size
    struct node** t;
};

int    hash(char* s);
void   init(struct hash* h,int n);
void  clean(struct hash* h);
int  insert(struct hash* h,char* s);

int main(void){
    int j;
    int t; scanf("%d",&t);
    int n;
    struct node u; u.next=NULL; // input dummy
    struct node v; v.next=NULL; // input dummy
    struct hash h;
    init(&h,N);
    p=(int*)malloc(sizeof(int)*N);
    s=(int*)malloc(sizeof(int)*N);

    while(t-->0){
        scanf("%d",&n);
        for(j=0;j<2*n;j++){
            p[j]=j;
            s[j]=1;
        }
        I=0;
        for(j=0;j<n;j++){
            scanf("%s %s",u.s,v.s);
            u.v=insert(&h,u.s);
            v.v=insert(&h,v.s);
            unify(u.v,v.v);
            printf("%d\n",s[getroot(u.v)]);

        }
        clean(&h);
    }
}

int getroot(int q){
    if(p[q]==q){return q;}
    else       {return p[q]=getroot(p[q]);}
}
void  unify(int u,int v){
    int r=getroot(u);
    int t=getroot(v);
    if(r!=t){
        p[r]=t;
        s[t]+=s[r];
    }
}
int    hash(char* s){
    int h=5381;
    while(*s!='\0'){h=((h<<5)+h)+*s++;}
    return h&0x7FFFFFFF;
}
void   init(struct hash* h,int n){
    h->n=n;
    h->t=(struct node**)calloc(n,sizeof(struct node*));
}
void  clean(struct hash* h){
    int j;
    struct node* d;
    struct node* f;
    for(j=0;j<h->n;j++){
        d=h->t[j];
        while(d!=NULL){
            f=d;
            d=d->next;
            free(f);
        }
        h->t[j]=NULL;
    }
    // free(h->t);
}
int  insert(struct hash* h,char* s){
    int v=hash(s);
    int i=v%h->n;
    struct node* d=h->t[i];
    while(d!=NULL){
        if(strcmp(d->s,s)==0){return d->v;}
        d=d->next;
    }
    struct node* n=(struct node*)malloc(sizeof(struct node));
    strcpy(n->s,s);
    n->v=I;
    n->next=h->t[i]; // chaining
    h->t[i]=n;
    return I++;
}