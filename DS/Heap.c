//1927: 최소 힙(자료 구조, 우선순위 큐)
//시간 초과: 트리로 구현
#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node* next;
};
struct queue{
    int num;
    struct node* head;
};
void push(struct queue* q, int i);
void pop(struct queue* q);

int main(void){
    //큐 세팅
    struct node* h = (struct node*)malloc(sizeof(struct node));
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    h->value = 0; h->next = NULL;
    q->num = 0;
    q->head = h;
    //정답 출력
    int n; scanf("%d", &n);
    int inst;
    for(int i = 0; i < n; i++){
        scanf("%d", &inst);
        if(inst == 0){pop(q);}
        else{push(q, inst);}
    }
}
void push(struct queue* q, int i){
    struct node* buf = (struct node*)malloc(sizeof(struct node));
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value = i;
    newnode->next = NULL;

    buf = q->head;
    while(buf -> next != NULL){
        if(i >= buf->next->value){
            buf = buf->next;
        }
        else{
            break;
        }
    }
    newnode->next = buf->next;
    buf->next = newnode;
    q->num += 1;
}
void pop(struct queue* q){
    if(q->num == 0){printf("0\n");}
    else{
        printf("%d\n", q->head->next->value);
        q->head->next = q->head->next->next;
        q->num -= 1;
    }
}
