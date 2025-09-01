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

int main(){}