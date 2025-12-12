//2161: 카드 1(구현, 자료 구조, 큐)
#include<stdio.h>
#include<stdlib.h>
struct card{
    unsigned short value;
    struct card* prev;
    struct card* next;
};
struct deck{
    struct card* top;
};
void push(struct deck* d, unsigned short i);
unsigned short pop(struct deck* d);

int main(void){
    unsigned short n; scanf("%hd", &n);
    struct card* t = (struct card*)malloc(sizeof(struct card));
    struct deck* d = (struct deck*)malloc(sizeof(struct deck));
    t->value = 0; t->prev = t; t->next = t;
    d->top = t;
    for(unsigned short i = 1; i <= n; i++){
        push(d, i);
    }
    for(int i = 1; i <= n; i++){
        printf("%hd ", pop(d));
        push(d, pop(d));
    }
}
void push(struct deck* d, unsigned short i){
    struct card* newcard = (struct card*)malloc(sizeof(struct card));
    newcard->value = i;
    newcard->prev = d->top->prev;
    newcard->next = d->top;
    d->top->prev->next = newcard;
    d->top->prev = newcard;
}
unsigned short pop(struct deck* d){
    unsigned short i = d->top->next->value;
    d->top->next->next->prev = d->top;
    d->top->next = d->top->next->next;
    return i;
}
