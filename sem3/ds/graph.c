#include<stdio.h>
#include<stdlib.h>


void create(int **a){
    int m=5; //or user input 
    for(int i=0;i<m;i++){
        *(a+i)=(int *)calloc(m,sizeof(int));
    }
}

void create_edge(int ** a, int i, int j){
    a[i][j]=1;
    a[j][i]=1;
}

void display(int **a){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%d\t",*(*(a+i)+j));
        }
        printf("\n");
    }
}

int main(){
    int **mat=(int **)calloc(1,sizeof(int *));
    create(mat);
    display(mat);
    create_edge(mat,3,4);
    display(mat);

}
