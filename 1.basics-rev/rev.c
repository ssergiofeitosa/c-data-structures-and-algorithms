#include <stdio.h>

typedef struct{
    int nume;
    int deno;
}racional;

void criarRacional (int num, int den, racional *rac){
    rac->nume=num;
    rac->deno=den;
}
void multiplicarRacionais (racional *r1, racional *r2, racional *res){
    res->nume=(r1->nume)* (r2->nume);
    res->deno=(r1->deno)*(r2->deno);
}
void somarRacionais (racional *r1,racional *r2, racional *r3){
    r3->deno=r1->deno * r2->deno;
    r3->nume = ((r3->deno/r1->deno)*r1->nume)+((r3->deno/r2->deno)*r2->nume) ;
    
}

int equivalencia (racional *r1, racional *r2){

}
int main(){
    racional r1,r2,r3;
    
    criarRacional(2,3,&r1);
    criarRacional(1,3,&r2);
    multiplicarRacionais(&r1,&r2,&r3);
    somarRacionais(&r1,&r2,&r3);
    printf("%d/%d \n",r3.nume, r3.deno );
    // printf("%d/%d \n", r3.nume , r3.deno);

}