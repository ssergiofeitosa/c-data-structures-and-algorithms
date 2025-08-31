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
void Remove (linkedHeader *l,int pos){
    if(pos<1||pos>size(*l)){
        printf("out of bounds (rem)"); exit(3);
    }
    linkedHeader aux,rem;
    if(pos==1){
        rem=(*l)->next;
        (*l)->next=rem->next;
        free(rem);
    }else{
        int i;
        for(i=0,aux=(*l)->next;i<pos-2;aux=aux->next,i++);
        rem=aux->next;
        aux->next=rem->next;
        free(rem);
    }
    (*l)->val--;

}
void destroy(linkedHeader *l){
    if(!l){printf("list empty/null");}
    linkedHeader rem;
    while(l){
        rem=(*l);
        free(rem);
        *l=(*l)->next;
    }
}
int main(){
    linkedHeader l;
    createList(&l);
    insert(&l,1,2);
    insert(&l,2,4);
    insert(&l,3,6);
    // Remove(&l,2);
    destroy(&l);
    printf("%d \n", recup(l,1));
    printf("%d \n", recup(l,2));
    printf("%d \n", recup(l,3));
}