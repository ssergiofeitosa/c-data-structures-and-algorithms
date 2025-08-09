#include <stdio.h>
#include <stdlib.h>
#define max 10000

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
    if(pos<1||pos>l->N+1){
        printf("insert error");
        return;
    }
    int i;
    for(i=l->N;i>=pos;i--){
        l->val[i]=l->val[i-1];
    }
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
void removeNode (LIST *l, int pos){
    if(1>pos||pos>l->N){
        printf("INVALID INDEX");
        return ;}
    int i;
    l->N--;
    for(i=pos-1;i<l->N;i++){
        l->val[i]=l->val[i+1];
    }           
};

int contains(LIST *l, int value){//verifies if a number is contained in the list
    int i,j;
    for(j=0;j<l->N;j++){
        if(l->val[j]==value){return 1;}
    }
    return 0;
};
int isOrdenate(LIST *l){//verifies if the list is ordenate
    int i;

    for(i=0;i<l->N-1;i++){
        if(l->val[i]>l->val[i+1]){ return 0;}
    }
    return 1;
}; 
void generateList(LIST *l, int floor, int ceiling){
    int tam=ceiling-floor;
    if(ceiling-floor>max){
        printf("invalid interval");exit(1);}
    else{
        int i;
        for(i=0;tam>i-1;i++){
            l->val[i]=floor+i;
            printf("%d \n",l->val[i]);
        }
    }
};


int main(){
    LIST l;
    createList(&l);
    // insert(&l,1,1);
    // insert(&l,2,2);
    // insert(&l,3,3);
    // insert(&l,4,4);
    generateList(&l,1,120);
    // printf("%d", l.val[3]);
    // printf("%d",recup(&l,4));
    // if(contains(&l,2)){
    //     printf("\n esta contido");
    // }else{printf("\n nao esta contido");}
    // if(isOrdenate(&l)){
    //     printf("\n esta ordenada");
    // }else {printf("\n nao esta ordenada");}
    

}