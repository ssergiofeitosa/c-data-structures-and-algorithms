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
    //cases: first position; other positions
    int i=0;
    linkedList remove;
    if(pos==1){
        remove=*l;
        *l=remove->next;
        free(remove);
    }else{
        linkedList aux;
        for(aux=*l;i<pos-2;aux=aux->next,i++); //percorre até posição anterior ao nó de remoção
        remove=aux->next;
        aux->next=remove->next;
        free(remove);
    }
    return;}

void destroy (linkedList *l){
    if(!l){printf("list doesnt exist");exit(5);}
    linkedList aux;
    // for(*l;*l!=NULL;aux=aux->next){
    //     aux=*l;
    //     *l=(*l)->next;
    //     free(*l);
    // } OR
    while(*l){
        aux=*l;
        *l=(*l)->next;
        free(aux);
    }
}

int tamRec(linkedList l){
   if(!l){return 0;}
   else{
    return  1+tamRec(l->next);
   }
}

int recupRec(linkedList l, int pos){
    if(pos<1||pos>tamRec(l)){
        printf("out of bounds ");exit(6);
    }else{
        if(pos==1){return l->val;}
        else{
            return recupRec(l->next,pos-1);
        }
    }
}

// void insertRec(linkedList *l, int pos, int value){
//     if(pos<1||pos>size(*l)+1){
//        printf("insert error: out of bounds \n"); exit(2);}    
// }
   void destroyRec(){}
int main(){
    linkedList l;
    createList(&l);
    insert(&l,1,1);
    insert(&l,2,2);
    insert(&l,3,3);
    printf("%d \n", tamRec(l));
    // destroy(&l);
    printf("%d \n", l->val);
    printf("%d \n", l->next->val);
    printf("%d \n", l->next->next->val);
    // printf("%d \n",recupRec(l,1));
}