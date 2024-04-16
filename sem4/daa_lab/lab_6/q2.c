#include <stdio.h>  
int opcount=0; 
int partition(int a[], int low, int high) {  
    int pivot = a[high];  
    int i = (low - 1);  
    int temp;
  
    for (int j = low; j <= high - 1; j++) { 
        opcount++; 
        if (a[j] < pivot) {  
            i++; 
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }  
    }
    temp=a[i+1];
    a[i+1]=a[high];
    a[high]=temp;  
    return (i + 1);  
}  
void quickSort(int arr[], int low, int high) {  
    if (low < high) {  
        int pi = partition(arr, low, high);  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  
  
  
int main() {  

    int n;
    printf("Enter size:");
    scanf("%d",&n);
    printf("Enter array:");
    int a[n];  
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    quickSort(a, 0, n - 1);  
    printf("Sorted array: \n");  
    for (int i = 0; i < n; i++)  
        printf("%d ", a[i]);  
    printf("\n");
    printf("Opcount is- %d\n",opcount);  
}  