#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}NODE;
typedef NODE *circularList;
//*l will point to last element
void create (circularList *l){
    *l=NULL;
}

int tam (circularList l){
    circularList aux;
    if(!l){return 0;}; 
    aux=l->next; 
    int i=1;
    while(l!=aux){
        aux=aux->next;
        i++;
    }
    return i;
}

void ins (circularList *l, int pos, int val){
    if(pos<1||pos>tam(*l)+1){printf("out of bounds");exit(1);}
    circularList novo=(NODE*)malloc(sizeof(NODE));
    novo->val=val;
    if(*l==NULL){ //if its empty
        novo->next=novo;
        *l=novo;
    }else{
        circularList aux=*l;//aux points to end of list
        if(pos==tam(*l)+1){//if insert on end
            *l=novo; //new node will point to end
        }else{
            for(;pos>1;aux=aux->next,pos--);  //runs throught list and stops before(aux) position of insertion
        }
        novo->next=aux->next;
        aux->next=novo;
    }
}

int recup (circularList l, int pos){
    if(pos<1||pos>tam(l)){printf("out of bounds(rec)");exit(2);}
    circularList aux=l->next;
    for(;pos>1;aux=aux->next,pos--);
    return aux->val;
}

void removeNode  (circularList *l, int pos){
    int size=tam(*l);
    if(pos<1||pos>size){printf("out of bounds(rem)");exit(3);}
    circularList rem,aux;
    
    if(size==1){
        free(*l);
        *l=NULL;
    }else{
        int i;
        for(aux=*l,i=pos;i>1;aux=aux->next,i--);
        rem=aux->next;
        aux->next=rem->next;
        if(pos==size){
            *l=aux;
        }
    }
    free(rem);
}




int main(){
    circularList l;
    create(&l);
    ins(&l,1,2);
    ins(&l,2,4);
    ins(&l,3,6);
    removeNode(&l,3);
    printf("%d",recup(l,3));
    
}