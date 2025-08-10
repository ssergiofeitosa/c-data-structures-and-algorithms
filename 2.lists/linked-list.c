#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}NODE;
typedef NODE *linkedList;

void createList(linkedList *l){
    *l=NULL;
}

int size (linkedList l){
    if(l==NULL){
        printf("list is empty \n");return 0;
    }else{
        int i;
        for(i=0;l!=NULL;i++,l=l->next);
        return i;
    }
}

void insert (linkedList *l, int pos, int value){
    //is pos valid? is there memory to store another element?  inserting on start or elsewhere?
    if(pos<1||pos>size(*l)+1){
        printf("insert error: out of bounds \n"); exit(1);
    }
    linkedList new;
    new = (NODE*)malloc(sizeof(NODE));
    if(!new){printf("error in allocating mem for new node");exit(2);}
    new->val=value;
    if(pos==1){
        new->next=*l;
        *l=new;}
     else{
         linkedList aux;
         int i;
         for(i=1,aux=*l;i<pos-1;aux=aux->next,i++);
         new->next=aux->next;
         aux->next=new;
     }
}

int main(){
    linkedList l;
    createList(&l);
    insert(&l,1,1);
    insert(&l,1,2);
    insert(&l,3,3);
    insert(&l,4,4);
    printf("%d", l->val);
    printf("%d", l->next->val);
    printf("%d", l->next->next->val);
    printf("%d", l->next->next->next->val);    
    // printf("%d",size(l));
}