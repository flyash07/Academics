#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int horspool(char * sen, int m, int * suffix,char * word, int n){
	int i = n- 1; // index in sen
	while (i < m) {
        	int k = 0;
        	while (k < n && word[n - 1 - k] == sen[i - k])
           		++k;
      		if (k == n)
            		return i - n + 1; // pattern found
        	else
            		i += suffix[sen[i]];
	}
	return -1; // pattern not found
}

int main(){
	char sen[50];
	char word[10];
	printf("Enter a senstance:");
	scanf("%[^\n]s",sen);
	printf("Enter a word:");
	scanf("%s",word);
	int m=strlen(sen);
	int n=strlen(word);
	for (int i = 0; i < 256; ++i)
        suffix[i] = n;
	for(int i=0;i<n-1;i++)
		suffix[word[i]]=n-i-1;
	int x =horspool(sen,m,suffix,word,n);
	if(x==-1)
		printf("Not found\n");
	else 
		printf("Subtring found at index %d\n",x);
}
