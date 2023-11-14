//program to sort odd and even numbers into separate stacks
#include<stdio.h>
#include<stdlib.h>
typedef struct{
   int tos;
   int a[20];
}stack;
int pop(stack *s){
   if(s->tos==-1){
       printf("stack underflow\n");
       return -1;
   }
   else return s->a[(s->tos)--];

}
void push(stack *s,int t){
   if(s->tos==19){
       printf("Stack overflow\n");
       return;
   }
   else s->a[++(s->tos)]=t;
   return;
}
void sort(int *a,int n){
   stack *odd=(stack *)malloc(n*sizeof(int));
   stack *even=(stack *)malloc(n*sizeof(int));
   odd->tos=-1;
   even->tos=-1;
   for(int i=0;i<n;i++){
      if (*(a+i)==0){
         printf("0 neither odd nor even\n");
         continue;
      }
      if(*(a+i)%2==0)
         push(even,*(a+i));
      else push(odd,*(a+i));
   }
}
int main(){
   int n,a[20];
   printf("Enter number of elements:");
   scanf("%d",&n);
   printf("Enter elements of array:");
   for(int i=0;i<n;i++)
      scanf("%d",&a[i]);
   sort(a,n);
   printf("sorted\n");   
}
