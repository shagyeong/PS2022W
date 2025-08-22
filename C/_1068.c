//1068: 트리(그래프 이론, 그래프 탐색, 트리, 깊이 우선 탐색)
#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node* lchild;
    struct node* rchild;
};
struct tree{
    int num;
    struct node* root;
};
int insert(struct tree* T, int p, int i);
struct node* __getparent(struct tree* T, struct node* R, int p);
void printree(struct tree* T);

int main(void){
    int e;
    //트리 세팅
    struct tree* T = (struct tree*)malloc(sizeof(struct tree));
    struct node* R = (struct node*)malloc(sizeof(struct node));
    R->value = 0;
    //원소 삽입
    int n; scanf("%d", &n);
    int p; scanf("%d", &p);
    for(int i = 1; i < n; i++){
        scanf("%d", &p);
        if((e = insert(T, p, i)) != 0){
            printf("e: %d\n", e);
        }
    }
    printree(T);
}
int insert(struct tree* T, int p, int i){
    struct node* parent = (struct node*)malloc(sizeof(struct node));
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value = i;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    if((parent = __getparent(T, T->root, p)) == NULL){
        printf("insert: cannot find parent\n");
        return -1;
    }
    if(parent->lchild == NULL){
        printf("insert: leftchild\n");
        parent->lchild = newnode;
        return 0;
    }
    if(parent->rchild == NULL){
        printf("insert: rightchild\n");
        parent->rchild = newnode;
        return 0;
    }
    printf("insert: parent already have children\n");
    return -2;
}
struct node* __getparent(struct tree* T, struct node* R, int p){
    if(p == R->value){
        return R;
    }
    if(R->lchild != NULL){
        return __getparent(T, R->lchild, p);
    }
    if(R->rchild != NULL){
        return __getparent(T, R->rchild, p);
    }
    return NULL;
}
void printree(struct tree* T){

}
