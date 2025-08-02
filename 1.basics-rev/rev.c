#include <stdio.h>
#include <stdbool.h>
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

bool equivalencia (racional *r1, racional *r2){
    return r1->nume*r2->deno == r2->nume*r1->deno;
}

void reduzirRacional (racional *r, racional *res){
    int a,b,r;
    float q;
    if(r->nume>r->deno){
        a=r->nume;
        b=r->deno;
    }else a=r->deno;b=r->nume;
    while(b){
        r=a%b;
        a=b;
        b=r;
    }
    res->nume=r->nume/a;    
    res->deno=r->deno/a;

}
int main(){
    racional r1,r2,r3;
    
    criarRacional(3,6,&r1);
    criarRacional(1,3,&r2);
    multiplicarRacionais(&r1,&r2,&r3);
    somarRacionais(&r1,&r2,&r3);

    // printf("%d", equivalencia(&r1,&r2));
    // printf("%d/%d \n",r3.nume, r3.deno );
    // printf("%d/%d \n", r3.nume , r3.deno);

}