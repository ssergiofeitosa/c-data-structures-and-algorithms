#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next, *prev;
}NODE;

typedef NODE *lista;

void create (lista *l){
    *l=(NODE*)malloc(sizeof(NODE));
    (*l)->prev = (*l)->next = *l;
    (*l)->val = 0;
}

int size (lista *l){
    return (*l)->val;
}

void ins(lista *l, int pos, int val){
    if (pos<1||pos>(size(l)+1)){printf("out of bounds (ins)"); exit(1);}
    lista novo = (NODE*)malloc(sizeof(NODE));
    //check alloc
    novo->val=val;
    if((*l)->val==0){
        novo->next=*l;
        novo->prev=*l;
        (*l)->next=(*l)->prev=novo;
    }else{
        lista aux=*l;
        int i =pos;
        if(pos==(size(l))+1){
            for(;i>1;aux=aux->next,i--);
            novo->next=*l;
            novo->prev=aux;
            aux->next=novo;
            (*l)->prev=novo;
            
        }else{
            for(;i>1;aux=aux->next,i--);
            novo->next=aux->next;
            novo->prev=aux;
            aux->next->prev=novo;
            aux->next=novo;
        }
    }
    (*l)->val++;
}

int recup(lista *l,int pos){
    if (pos < 1 || pos > size(l)){
        printf("out of bounds (recup)\n");
        exit(3);
    }

    lista aux=(*l)->next;
    for(;pos>1;aux=aux->next,pos--);
    return aux->val;
}

void ret (lista *l, int pos){
    if (pos<1||pos>(size(l))){printf("out of bounds (ret)"); exit(2);}
    (*l)->val--;
    lista aux=*l;
    for(;pos>1;aux=aux->next,pos--);
    aux->prev->next=aux->next;
    aux->next->prev=aux->prev;
    free(aux);
}

void DESTRUIR(lista l){
    lista aux;
    while(l){
        aux=l;
        l=l->next;
        free(aux);
    }
}
int main(){
lista l;
    create(&l);
    ins(&l,1,2);
    ins(&l,2,4);
    ins(&l,3,6);
    DESTRUIR(l);
    printf("%d \n",recup(&l,1) );
    printf("%d \n",recup(&l,2) );

    // printf("%d %d \n", l->next->val, l->next->next->val);
}