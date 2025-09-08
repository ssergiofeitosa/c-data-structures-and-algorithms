#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}NODE;
typedef NODE *circularList;

void createList(circularList *l){
    *l=NULL;
   
}

int size (circularList l){
    if(!l){return 0;}
    circularList start;
    start=l->next;
    int i;
    for(i=1;start!=l;start=start->next,i++);
    return i;
}

void insert (circularList *l, int pos, int value){
    if (pos<1||pos>size(*l)+1){
        printf("out of bounds (ins)");exit(1);
    }
    circularList new;
    new=(NODE*)malloc(sizeof(NODE));
    //hurr duur check if mem was really allocated hurdurrrr
    new->val=value;
    if(!(*l)){
        new->next=new;
        *l=new;
    }
    else{
        if(pos==size(*l)+1){//insertion on end
            circularList aux=*l;
            new->next=aux->next;
            aux->next=new;
            *l=new;
        }else{//insert on "middle"
            circularList aux=(*l)->next;
            int i=0;
            for(;i<pos-2;aux=aux->next,i++);//stops right before inserted node
            new->next=aux->next;
            aux->next=new;
        }
    }
}

int recup(circularList l, int pos){
    if (pos<1||pos>size(l)){
        printf("out of bounds (rec)");exit(2);
    }
    circularList aux=l->next;
    for(int i=0;i<pos-1;aux=aux->next,pos++);    
    return aux->val;
}

void ret(circularList *l,int pos){
    if (pos<1||pos>size(*l)){
        printf("out of bounds (ret)");exit(3);
    }
    if(size(*l)==1){//if list has only 1 element
        free(*l);
        *l=NULL;return;
    }else{
        circularList aux=(*l)->next,rem;
        int i=0;
                for(;i<pos-1;aux=aux->next,i++);
                rem=aux->next;
                aux->next=rem->next;
                free(rem);
        }
    }


void destroy(){

}

int main(){
    circularList l;
    createList(&l);
    insert(&l,1,2);
    insert(&l,2,4);
    insert(&l,3,6);
    printf("%d \n", recup(l,1));
    printf("%d \n", recup(l,2));
    printf("%d \n", recup(l,3));
    ret(&l,1);
    printf("\n %d \n", recup(l,1));
    printf("%d \n", recup(l,2));
    printf("%d \n", recup(l,3));
}