#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}NODE;
typedef NODE *linkedHeader;
//not much will change, just that the first element will not store a value, but info about the list's size and the pointer to the first element
//first node = header -> stores size of the list and a pointer to the actual first element
void createList (linkedHeader *l){
    linkedHeader new;
    new=(NODE*)malloc(sizeof(NODE));
    *l=new;
    new->next=NULL;
    new->val=0; //list's size

}
int isEmpty(linkedHeader l){
    return l->val==0; //return 1(true) if list is empty
}
int size(linkedHeader l){
    return l->val;
}
void insert(linkedHeader *l,int pos, int val){
    if (pos<1||pos>size(*l)+1){
        printf("out of bounds (ins)"); exit(1);
    }
    linkedHeader new;
    new=(NODE*)malloc(sizeof(NODE));
    //check if mem was allocated hurrdur
    if(pos==1){
        new->next=(*l)->next;
        (*l)->next=new;
    }else{
        int i;
        linkedHeader aux;
        for(aux=(*l)->next,i=0;i<pos-2;aux=aux->next,i++);
        new->next=aux->next;
        aux->next=new;
    }
    new->val=val;
    (*l)->val++;
}   
int recup (linkedHeader l, int pos){
    if (pos<1||pos>size(l)){
        printf("out of bounds (rec)"); exit(2);
    }
    linkedHeader aux;
    int i=0;
    for(aux=(l)->next;i<pos-1;aux=aux->next,i++);
    return aux->val;
}
void Remove (linkedHeader *l){

}
void destroy(linkedHeader l){

}
int main(){

}