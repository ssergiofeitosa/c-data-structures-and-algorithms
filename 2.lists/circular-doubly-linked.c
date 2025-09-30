#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next, *prev;
}NODE;

typedef NODE *lista;

void create (lista *l){
    *l=NULL;
}

int size (lista l){
    if(!l) return 0;
    lista aux=l->prev;
    int i=1;
    while(l!=aux){
        i++;
        l=l->next;
    }
    return i;
}

void ins (lista *l, int pos, int val){
    if (pos<1||pos>size(*l)+1){printf("out of bounds (ins)");exit(1);}
    lista novo=(NODE*)malloc(sizeof(NODE));
    novo->val=val;
    if(*l==NULL){//se for vazia
        novo->next=novo->prev=novo;
        *l=novo;
    }else{
        lista aux=*l;
        if(pos==1){//se for no inicio
            novo->next=*l;
            novo->prev=(*l)->prev;
            (*l)->prev->next=novo;
            (*l)->prev=novo;
            *l=novo;
        }else{
            
            if(pos==size(*l)+1){ // novo ultimo
                lista old_last = (*l)->prev;
                novo->next=aux;
                novo->prev=old_last;
                old_last->next=novo;
                (*l)->prev=novo;

            }
            else{
                lista aux = *l;
                for(;pos>2;aux=aux->next,pos--);
                novo->next=aux->next;
                novo->prev=aux;
                aux->next->prev=novo;
                aux->next=novo; 
            }
        }
    }
}

int recup (lista l,int pos){
    if (pos<1||pos>size(l)){printf("out of bounds (rec)");exit(2);}
    for(;pos>1;l=l->next,pos--); //para no nó de recuperação
    return l->val;
}

void ret(lista *l, int pos){
    if (pos<1||pos>size(*l)){printf("out of bounds (ret)");exit(3);}
    //case first; case last; case middle; 
    lista rem=*l, aux=(*l)->prev;
    if(pos==1){
        aux->next=rem->next;
        rem->next->prev=aux;
        *l=rem->next;
        free(rem);
    }else{
        if(pos==size(*l)){
            rem=(*l)->prev;
            aux=rem->prev;
            aux->next=rem->next;
            rem->next->prev=aux;
            free(rem);
        }else{
            aux=*l;
            for(;pos>1;aux=aux->next,pos--);
            rem=aux;
            aux->prev->next=rem->next;
            rem->next->prev=rem->prev;
            free(rem);
        }
    }
}

void destroy(lista l){}

int main(){
    lista l;
    create(&l);
    ins(&l,1,2);
    ins(&l,2,4);
    ins(&l,3,6);
    // ret(&l,1);
    printf("%d , %d", recup(l,1), recup(l,3));
}
