#include<stdio.h>
#include<stdlib.h>
int Smallest(int *, int);
int main(){
    int *p,n,i;
    printf("Enter the length of the array:");
    scanf("%d",&n);
    p=(int *)calloc(n,sizeof(int));
    if (p==NULL){
        printf("Memory not allocated,exiting\n");
        exit(0);
    }
    printf("Enter the elements of the array:");
    for(i=0;i<n;i++)
        scanf("%d",p+i);
    printf("The smallest element in the array is:%d\n",Smallest(p,n));  
    free(p);  
}
int Smallest(int *p, int n){
    int i,s;
    s=*p;
    for(i=1;i<n;i++){
        if (s>*(p+i))
            s=*(p+i);
    }
    return s;
}
