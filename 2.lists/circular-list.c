#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
}NODE;
typedef NODE *circularList;

void create (circularList *l){
    *l=NULL;  //aponta para final da lista
}

int tam (circularList l){
    if(!l){return 0;};
    circularList aux =l->next; //aux recebe elemento 1
    int i=1;
    while(aux!=l){
        aux=aux->next;
        i++;
    }
    return i;
}
//IMPLEMENTACAO LINDER
// void ins (circularList *l, int pos, int val){
//     if (pos<1||pos>tam(*l)+1){printf("out of bounds (ins)");exit(1);}
//     circularList novo=(NODE*)malloc(sizeof(NODE));
//     //casos: ins no inicio vazio, ins no final, ins outras pos
//     novo->val=val;
//     int size = tam(*l);
//     if((*l)==NULL){
//         novo->next=novo;
//         *l=novo;
//     }else{
//         circularList aux=*l;
//         if(pos==size+1){ //ins novo ultimo elemento
//             (*l)=novo;
//         }else
//         for(;pos>1;aux=aux->next, pos--);
//         novo->next=aux->next;
//         aux->next=novo;
//     }
// }

void ins (circularList *l, int pos, int val){
    if (pos<1||pos>tam(*l)+1){printf("out of bounds (ins)");exit(1);}
    circularList novo=(NODE*)malloc(sizeof(NODE));
    //casos: ins no inicio vazio, ins no final, ins outras pos
    novo->val=val;
    int size = tam(*l);
    if(!(*l)){ // se lista vazia
        novo->next=novo;
        *l=novo;
    }else if(pos==1){ //inserindo no inicio
        novo->next=(*l)->next;
        (*l)->next=novo;
    }else{
        circularList aux=*l;
        if(pos==tam(*l)+1){ //ins nov ultimo nodo
            novo->next=aux->next;
            aux->next=novo;
            *l=novo;
        }else{ //inserir demais pos
            for(;pos>1;aux=aux->next,pos--);
            novo->next=aux->next;
            aux->next=novo;
        }

    }
}

int recup (circularList l, int pos){
    if (pos<1||pos>tam(l)){printf("out of bounds (rec)");exit(2);}
    for(;pos>0;pos--,l=l->next);
    return l->val;
}

void rem (circularList *l, int pos){
    int size =tam (*l);
    if (pos<1||pos>size){printf("out of bounds (rem)");exit(3);}
    //remover unico, remover ultimo, else
    if(size==1){
        free (*l);
        *l=NULL;
    }else{
        circularList rem, aux=*l;
        int i = pos;
        for(;i>1;aux=aux->next,i--); //para no nó anterior, pq começa a contar a partir do ultimo(*l),
        rem=aux->next;
        aux->next=rem->next;
        if(size==pos) { 
            *l=aux;}
        free(rem);
    }
}

void obliterar (circularList l){
    circularList aux=l->next;
    while(l){
        aux=l;
        l=l->next;
        free(aux);
    }
}

int main (){
    circularList l;
    create(&l);
    ins(&l,1,2);
    ins(&l,2,4);
    ins(&l,3,6);
    obliterar(l);
    printf("%d , %d", recup(l,2), recup(l,1));
    // printf("%d", l->val);
}