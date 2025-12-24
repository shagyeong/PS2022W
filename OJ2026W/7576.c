// 7576: 토마토(격자그래프, BFS)
#include<stdio.h>

// 방문 상태
# define F 0
# define T 1


int a[1001][1001];  // 창고
int v[1001][1001];  // 방문 상태
int row[1001*1001]; // row queue
int col[1001*1001]; // col queue


int main(void){
    int ans=0;
    int j; int k;   // loop variable
    int n; int m;   // matirx size
    int t=0;        // total number of tomato
    int t_ripe=0;   // 입력 상태에서 익은 토마토 개수
    int t_prev=0;   // 이전 단계에서 익은 토마토 개수: 변화 없으면 루프 탈출
    int b;          // value buffer
    int q=0;        // q 엘리먼트 개수: dequeue 횟수 제한으로 일수 파악
    int q_prev=0;
    int s=0;        // linear queue: start
    int e=0;        // linear queue: end
    int r; int c;   // row, column buffer

    scanf("%d %d",&m,&n);
    // int a[n][m];  // 창고
    // int v[n][m];  // 방문 상태
    // int row[n*m]; // row queue
    // int col[n*m]; // col queue

    for(j=0;j<n;j++){
        for(k=0;k<m;k++){
            scanf("%d",&b);
            a[j][k]=b;
            v[j][k]=F;
            if(b==0){
                t+=1;
            }
            if(b==1){
                t+=1; t_ripe+=1;
                v[j][k]=T;
                row[e]=  j; // enqueue
                col[e++]=k; // enqueue
                q+=1;       // enqueue
                q_prev+=1;
            }
        }
    }

    t_prev=t_ripe;
    while(1){
        ans+=1;
        q=q_prev;
        q_prev=0;
        for(j=0;j<q;j++){
            r=row[s];   //dequeue
            c=col[s++]; //dequeue
            if(r-1>=0){
                if((v[r-1][c]==F)&&(a[r-1][c]==0)){
                    v[r-1][c]=T;
                    a[r-1][c]=1; t_ripe+=1; // 토마토 익음
                    row[e]=r-1; // enqueue
                    col[e++]=c; // enqueue
                    q_prev+=1;  // enqueue
                }
            }
            if(r+1<n){
               if((v[r+1][c]==F)&&(a[r+1][c]==0)){
                    v[r+1][c]=T;
                    a[r+1][c]=1; t_ripe+=1;
                    row[e]=r+1;
                    col[e++]=c;
                    q_prev+=1;
                }
            }
            if(c-1>=0){
               if((v[r][c-1]==F)&&(a[r][c-1]==0)){
                    v[r][c-1]=T;
                    a[r][c-1]=1; t_ripe+=1;
                    row[e]=  r;
                    col[e++]=c-1;
                    q_prev+=1;
                }
            }
            if(c+1<m){
               if((v[r][c+1]==F)&&(a[r][c+1]==0)){
                    v[r][c+1]=T;
                    a[r][c+1]=1; t_ripe+=1;
                    row[e]=  r;
                    col[e++]=c+1;
                    q_prev+=1;
                }
            }
        }
        if(t_ripe==t_prev){ans-=1; break;} // 더 이상 익을 토마토가 없었음
        else{t_prev=t_ripe;} // continue
    }

    if(t_ripe==t){printf("%d",ans);}
    else{         printf("-1");}
}