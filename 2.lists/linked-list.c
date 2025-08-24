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
       return 0 ;
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

int recover (linkedList l, int pos){ //returns the value in a set position
    if(pos<1||pos>size(l)){
        printf("out of bounds(recover)");exit(3) ;
    }
    int i=0;
    linkedList aux;
    for(aux=l;i<pos-1;aux=aux->next,i++);
    return aux->val;
}

void Remove (linkedList *l, int pos){
    if(pos<1||pos>size(*l)){
      printf("out of bounds(remove)");exit(4); 
    }
    //cases: first position or not
    int i=0;
    linkedList remove;
    if(pos==1){
        remove=*l;
        *l=remove->next;
        free(remove);
    }else{
        linkedList remove;
        for(remove=*l;i<pos-2;remove=remove->next,i++);
        free(remove);
    }
}

void destroy (linkedList *l){}

// void insertRec(linkedList *l, int pos, int value){
//     if(pos<1||pos>size(*l)+1){
//        printf("insert error: out of bounds \n"); exit(2);}    
// }
 
int main(){
    linkedList l;
    createList(&l);
    insert(&l,1,1);
    insert(&l,2,2);
    insert(&l,3,3);
    printf("%d \n", l->val);
    printf("%d \n", l->next->val);
    printf("%d \n", l->next->next->val);
    printf("%d \n",recover(l,2));
}