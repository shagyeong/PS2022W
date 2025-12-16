//1158: 요세푸스 문제(구현, 자료 구조, 큐)
#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node* prev;
    struct node* next;
};
struct queue{
    int num;
    struct node* head;
};
void push(struct queue* q, int i);
void pop(struct node* n);

int main(void){
    int i, j;
    int n, k; scanf("%d %d", &n, &k);

    //큐 세팅
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->value = 1; head->prev = head; head->next = head;
    q->head = head;
    q->num = 1;
    struct node* buf = (struct node*)malloc(sizeof(struct node));
    for(i = 2; i <= n; i++){
        push(q, i);
    }

    //정답 출력
    buf = q->head->prev;
    for(j = 0; j < k; j++){
        buf = buf->next;
    }
    printf("<%d", buf->value);
    pop(buf);


    for(int i = 2; i <= n; i++){
        for(j = 0; j < k; j++){
            buf = buf->next;
        }
        printf(", %d", buf->value);
        pop(buf);
    }

    for(j = 0; j < k; j++){
        buf = buf->next;
    }
    printf(">");
}
void push(struct queue* q, int i){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value = i;
    newnode->next = q->head;
    newnode->prev = q->head->prev;
    q->head->prev->next = newnode;
    q->head->prev = newnode;
    q->num += 1;
}
void pop(struct node* n){
    n->prev->next = n->next;
    n->next->prev = n->prev;
}
