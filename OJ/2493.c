//2493: 탑(자료 구조, 스택)
#include<stdio.h>
#include<stdlib.h>
struct node{
    int index;
    int value;
    struct node* next;
};
struct stack{
    struct node* head;
};
void push(struct stack* s, int i, int v);   //index, value
void pop(struct stack* s);

int main(void){
    int i;
    
    //송신기 세팅
    int n; scanf("%d", &n);
    int tower[n + 1][2];
    for(i = 1; i <= n; i++){tower[i][0] = i;scanf("%d", &tower[i][1]);}

    //스택 세팅
    struct node* h = (struct node*)malloc(sizeof(struct node));
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    h->index = tower[1][0]; h->value = tower[1][1]; h->next = NULL;
    s->head = h;

    //버퍼
    int height; int ind;
    struct node* buf = (struct node*)malloc(sizeof(struct node));

    //정답 출력
    printf("0 ");
    i = 2;
    while(i <= n){
        ind = tower[i][0];
        height = tower[i][1];
        buf = s->head;
        while(buf != NULL){
            if(height > buf->value){
                buf = buf->next;
                pop(s);
            }
            else{
                break;
            }
        }
        //루프 탈출시 버퍼가 NULL: 수신하지 못함
        if(buf == NULL){
            printf("0 ");
            push(s, ind, height);
        }
        else{
            printf("%d ", buf->index);
            push(s, ind, height);
        }
        i++;
    }
}
void push(struct stack* s, int i, int v){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->index = i;
    newnode->value = v;
    newnode->next = s->head;
    s->head = newnode;
}
void pop(struct stack* s){
    s->head = s->head->next;
}
