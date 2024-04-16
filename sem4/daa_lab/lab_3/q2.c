//brute force string matching
#include<stdio.h>

int main(){
	int opcount=0;
	char s[]="Hello i am srishti"; int m=18;
	char sub[]="sri";  int n=3;
	printf("%s  %s\n",s,sub);
	for (int i = 0; i < m-n+1; i++) {
		int j = 0;
		
		while (j < n && s[i+j] == sub[j]) {
			printf("%d\n",j);
			j++;
			opcount++;
		}

		if (j == n){
			// opcount--;
			printf("Match found\n");
			break;
		}
		opcount++;
		
	}
	printf("opcount is %d\n",opcount);
}