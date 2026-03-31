// P4 1305: 광고(KMP)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* fail(char* q,int l);

int main(void){
    int l; scanf("%d",&l);
    char* q=(char*)malloc(sizeof(char)*(l+1));
    int* f;

    scanf("%s",q); q[l]='\0';
    f=fail(q,l);

    printf("%d",l-f[l-1]);
    free(q);
    free(f);
}

int* fail(char* q,int l){
    int j;
    int k=0;
    int* f=(int*)calloc(l,sizeof(int));
    for(j=1;j<l;j++){
        while((k>0)&&(q[j]!=q[k])){k=f[k-1];}
        if(q[j]==q[k]){f[j]=++k;}
    }
    return f;
}