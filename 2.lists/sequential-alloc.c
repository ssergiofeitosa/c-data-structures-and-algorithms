#include <stdio.h>
#define max 4

typedef struct{
 int N; //number of elemnts
 int val[max]; 
}LIST;

void createList (LIST *l){
    l->N=0;
};
int isEmpty (LIST *l){
    return l->N==0;
};
int size (LIST *l){
    return l->N;
};
void insert (LIST *l, int val, int pos){
    // int value = val;
    // int position=pos;
    l->val[pos-1]=val;
    l->N++;

};
int recup (LIST *l, int pos){
    if(1>pos||pos>l->N){
        printf("INVALID INDEX");
        return 0;
    }
    return l->val[pos-1];   
}
void remove (LIST *l, int pos){
    if(1>pos||pos>l->N){
        printf("INVALID INDEX");
        return;}
    int i;
    
    for(i=pos-1;i<l->N;i++){
        l->val[i]=l->val[i+1];
    }           
};

int main(){
    LIST l;
    createList(&l);
    insert(&l,1,1);
    insert(&l,2,2);
    insert(&l,3,3);
    insert(&l,4,4);
    // printf("%d", l.val[3]);
    remove(&l,4);
    printf("%d",recup(&l,4));
    

}