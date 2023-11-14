#include "dllistfunctions.h"








int main(){
    printf("1. Input polynomial  2.Subtract  3.Multiply  4.Exit");
    int inp;
    while(1){
        printf("Choice:");
        scanf("%d",&inp);
        if (inp==1){
            node *a =create();
            node *b = create(b);

        }
        else if(inp==2){
            node * sub=subtract();
            display(sub->next);

        }
        else if(inp==3){
            node * mul=multiply();
            display(mul->next);


        }
        else exit(0);
    }
}