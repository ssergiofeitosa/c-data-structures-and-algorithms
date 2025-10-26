#include <stdio.h>
#include <stdlib.h>
typedef struct nodo {
    int val;
    struct nodo *next;
}NODO;
typedef struct{
    NODO *start, *end;
}DESCRITOR;
typedef DESCRITOR *queue;

void createQ(queue *f){
    *f=(DESCRITOR*)malloc(sizeof(DESCRITOR));
    (*f)->start=NULL;
    (*f)->end=NULL;
}

void insert (queue *f, int val){
    NODO *novo;
    novo=(NODO*)malloc(sizeof(NODO));
    if(!novo){printf("error allocating mem(ins)");exit(1);}
    novo->val=val;
    novo->next=NULL;
    if(!(*f)->start){//IF ITS EMPTY
        (*f)->start=novo;
    }else{
        (*f)->end->next=novo;
    }
    (*f)->end=novo;
}

int isEmptyQ (queue f){
    return f->start==NULL;
}

int  cons (queue f){
    if(!(f)){printf("empty queue");exit(1);}

    return (f)->end->val;
}

void ret (queue *f){
    if(!(*f)){printf("empty queue");exit(1);}

    NODO *ret=(*f)->start;
    (*f)->start=(*f)->start->next;
    if(!(*f)->start){
        (*f)->end=NULL;
    }
    free(ret);
}
int cons_ret(queue *f){
    if(!(*f)){printf("empty queue");exit(1);}
    NODO *ret=(*f)->start;
    (*f)->start=(*f)->start->next;
    if(!(*f)->start){
        (*f)->end=NULL;
    }
    int c = ret->val;
    free(ret);
    return c;
}
typedef struct node{
    int val;
    struct node *father,*left,*right;
}NODE;
typedef NODE *tree; //binary tree

void maketree(tree *t, int val){
    *t=(NODE*)malloc(sizeof(NODE));
    (*t)->father=NULL;
    (*t)->left=(*t)->right=NULL;
    (*t)->val=val;
}

void setleft (tree t, int val){
    t->left=(tree)malloc(sizeof(NODE));
    t->left->val=val;
    t->left->left=NULL;
    t->left->right=NULL;
    t->left->father=t;
}
void setright (tree t, int val){
    t->right=(tree)malloc(sizeof(NODE));
    t->right->val=val;
    t->right->left=NULL;
    t->right->right=NULL;
    t->right->father=t;
}

int info (tree t){
    return t->val;
}
//functions below returns tree nodes
tree left (tree t){
    return t->left;
}
tree right (tree t){
    return t->right;
}
tree father (tree t){
    return t->father;
}

int isleft(tree t){
    NODE *q = t->father;
    if(q->left==t){
        return 1;}
    else return 0;

}
int isright(tree t){
    if(t->father){
        return (!isleft(t));}
    
}
tree brother (tree t){
    if(t->father){
       if(isleft(t)){ //verifies if node is the left of father
            return t->father->right ? t->father->right : NULL; 
       }else{
            return t->father->left ? t->father->left : NULL;
       } 
    } 
    return NULL;
}

void bfs (tree t){
    if(!t){printf("empty tree");exit(1);}
    queue q;
    createQ(&q);
    if(t){
        insert(q,t); //insere raizd a arvore na fila
    }
    while (!isEmptyQ(q)){ //enquanto houver nós na fila
        if(left(cons(q))){ //verifica se tem filho à esquerda
            ins(q,left(cons(q)));         //se sim, coloca esse nó na fila         [ o nó é o left(cons(q))]
        }
        if(right(cons(q))){ //verifica se tem filho à direita
            ins(q,right(cons(q)));  //se sim, coloca ele na fila
        }
        ret(q);
    }

}
int main(){
    tree t;
    maketree(&t,1);
    printf("%d", t->val);
}