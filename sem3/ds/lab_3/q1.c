#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int cr;
    int ci;
}com;
void add (com *,com *,com *);
void subtract(com *,com *,com *);
void multiply(com *,com *,com *);
void main(){
    com *pa,*pb,*pc;
    int n;
    printf("Enter real and imaginary part of complex number A:");
    pa=(com *)malloc(sizeof(com));
    if(pa==NULL) exit(0);
    scanf("%d%d",&(pa->cr),&(pa->ci));
    printf("Enter real and imaginary part of complex number B:");
    pb=(com *)malloc(sizeof(com));
    if(pb==NULL) exit(0);
    scanf("%d%d",&(pb->cr),&(pb->ci));
    pc=(com *)malloc(sizeof(int));
    if(pa==NULL) exit(0);
    add(pa,pb,pc);
    printf("Sum of A and B is:%d+%di\n",pc->cr,pc->ci);
    subtract(pa,pb,pc);
    printf("Difference of A and B is:%d+%di\n",pc->cr,pc->ci);
    multiply(pa,pb,pc);
    printf("Product of A and B is:%d+%di\n",pc->cr,pc->ci);
    free(pa);
    free(pb);
    free(pc);
}

void add (com *pa,com *pb,com *pc){
    pc->cr=pa->cr+pb->cr;
    pc->ci=pa->ci+pb->ci;
    return;
}

void subtract(com *pa,com *pb,com *pc){
    pc->cr=(pa->cr)-(pb->cr);
    pc->ci=(pa->ci)-(pb->ci);
    return;
}
void multiply(com *pa,com *pb,com *pc){
    pc->cr=(pa->cr)*(pb->cr) - (pa->ci)*(pb->ci);
    pc->ci=(pa->cr)*(pb->ci) + (pa->ci)*(pb->cr);
    return;
}
