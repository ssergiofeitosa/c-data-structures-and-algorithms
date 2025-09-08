#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next, *prev;
}NODE;

typedef NODE *doubleLinked;

void create (doubleLinked *l){
    *l=NULL;
}

int size(doubleLinked l){
    int i;
    for(i=0;l!=NULL;l=l->next,i++);
    return i;
}

int insert(doubleLinked *l, int pos, int val){
    if (pos<1||pos>size(*l)+1){
        printf ("out of bounds ins");exit(1);
    }
    doubleLinked new;
    new = (NODE*)malloc(sizeof(NODE));
    new->val=val;
    if(pos==1){ 
        new->prev=NULL; //novo primeiro aponta para null
        new->next=*l; //proximo do novo é o antigo primeiro
        *l=new; //inicio da lista agora aponta para o novo nó
        if((*l)->next){ //se existir um segundo elemento, ele aponta para o elemento anterior (o primeiro)
            (*l)->next->prev=new;
        }
    }else{
        doubleLinked aux=*l;
        int i=0;
        for(;i<pos-2;aux=aux->next,i++);
        new->next=aux->next; 
        new->prev=aux;      
        aux->next=new;
        if(new->next){
            new->next->prev=new;
        }
    }
}

int recup(doubleLinked l, int pos){
    if (pos<1||pos>size(l)){
            printf ("out of bounds recup");exit(2);
        }
    for(;pos>1;l=l->next,pos--);
    return l->val;            
}

int Remove(doubleLinked *l,int pos){

}

int destroy(doubleLinked l){

}

int main(){
    doubleLinked l;
    create(&l);
    insert(&l,1,2);
    insert(&l,2,4);
    insert(&l,2,5);    
    insert(&l,3,6);
    printf("%d \n", recup(l,1));
    printf("%d \n", recup(l,2));
    printf("%d \n", recup(l,3));
    printf("%d \n", recup(l,4));
}