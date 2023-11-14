#include<stdio.h>
#include<stdlib.h>
int* largest(int *,int *,int *);
void display_mirror(int **,int,int);
int main(){
    int i,j,*pa,*pb,*pc,**a;
    pa=(int *)malloc(sizeof(int));
    pb=(int *)malloc(sizeof(int));
    pc=(int *)malloc(sizeof(int));
    if ((pa==NULL)||(pb==NULL)||(pc==NULL)) exit(0);
    printf("Enter three numbers:");
    scanf("%d%d%d",pa,pb,pc);
    printf("The largest number is:%d\n",*(largest(pa,pb,pc)));
    
    
    printf("Enter the dimensions of matrix A:");
    scanf("%d%d",pa,pb);
    a=(int **)calloc(*pa,sizeof(int*));
    if(a==NULL) exit(0);
    for(i=0;i<*pa;i++){
	*(a+i)=(int *) calloc(*pb,sizeof(int));
	if (*(a+i)==NULL) exit(0);
	}
    printf("Enter the elements of the matrix A:");
    for(i=0;i<*pa;i++){
	for(j=0;j<*pb;j++)
	    scanf("%d",(*(a+i)+j)); 
    }
    
    printf("Mirror image of matrix is:\n");
    display_mirror(a,*pa,*pb);
    free(pa);
    free(pb);
    free(pc);
    free(a);
}

int* largest(int *a, int *b, int *c){
    if ( *a>*b && *a>*c)
        return a;
    if (*b>*c)  return b;
    else return c;
}

void display_mirror( int **a, int m, int n){
    int i,j;
    for(i=0;i<m;i++){
       for(j=n-1;j>=0;j--)
           printf("%d\t",*(*(a+i)+j));
       printf("\n");
    }
}
