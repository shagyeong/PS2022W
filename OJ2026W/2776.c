// S4 2776: 암기왕(이분탐색)
#include<stdio.h>
#include<stdlib.h>

int asc(const void* u,const void* v){
    if(*((int*)u)<*((int*)v)){return -1;}
    if(*((int*)u)>*((int*)v)){return  1;}
    return 0;
}

int main(void){
    int j;
    int _; scanf("%d",&_);
    int* a;
    int n; int q;
    int u;
    int i;
    int l; int m; int r;
    while(_-->0){
        scanf("%d",&n);
        a=(int*)malloc(sizeof(int)*n);
        for(j=0;j<n;j++){scanf("%d",&a[j]);}
        qsort(a,n,sizeof(int),asc);
    
        scanf("%d",&q);
        for(j=0;j<q;j++){
            scanf("%d",&u);
            i=-1;
            l=0; r=n-1;
            while(l<=r){
                m=l+(r-l)/2;
                if(a[m]==u){i=m; break;}
                if(a[m]> u){r=m-1;}
                if(a[m]< u){l=m+1;}
            }
            if(i==-1){printf("0\n");}
            else     {printf("1\n");}
        }
        free(a);
    }
}


// int search(int* a,int n,int q){
//     int s=0;   // start
//     int m;     // middle
//     int e=n-1; // end
//     while(s<=e){
//         m=s+(e-s)/2;
//         if(a[m]==q){return m;}
//         if(a[m]> q){e=m-1;}
//         if(a[m]< q){s=m+1;}
//     }
//     return -1;
// }