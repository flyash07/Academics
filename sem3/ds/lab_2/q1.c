#include <stdio.h>
void Reverse(int *,int );
int main(){
    int a[50],n,i;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    printf("Enter the elements of the array:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    Reverse(a,n);
    printf("The reversed array is:\n");
    for(i=0;i<n;i++)
       printf("%d\t",a[i]);
    printf("\n");
}

void Reverse(int *a, int n){
    int i,temp;
    for(i=0;i<n/2;i++){
        temp=*(a+i);
        *(a+i)=*(a+n-i-1);
        *(a+n-i-1)=temp;
    }
}
