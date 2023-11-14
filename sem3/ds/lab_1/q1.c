#include<stdio.h>
int main(){

    int t[50];
    int flag=0,i,j,k,m;
    printf("Enter number of elements in the array:\n");
    scanf("%d",&m);
    printf("Enter the elements:");
    for(i=0;i<m;i++){
        scanf("%d",&t[i]);
    }
	for (i=0;i<m-2;i++){
	    for(j=i+1;j<m-1;j++){
	        for(k=j+1;k<m;k++){
	            if ((t[i]+t[j]+t[k])==0){
	                printf("%d,%d,%d\n",t[i],t[j],t[k]);
	                flag=1;
	            }


	       }
	   }
	}
	if (flag==0)
        printf("None found\n");
    else 
        return 0;
}