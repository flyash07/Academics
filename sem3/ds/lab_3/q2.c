#include<stdio.h>
#include<stdlib.h>
typedef struct {
    char name[30];
    int roll_no;
    float cgpa;
}student;
void read(student *);
void display(student *);
void read(student *);
void sort(student *,int);
void main(){
    student *s;
    int n;
    s=(student *)malloc(sizeof(student));
    if(s==NULL) exit(0);
    read(s);
    display(s);
    printf("Enter the number of students:");
    scanf("%d",&n);
    s=(student *)realloc(s,n*sizeof(student));
    for(int i=0;i<n;i++)
        read(s+i);
    sort(s,n);
    for(int i=0;i<n;i++)
        display(s+i);
}
void read(student * s){
    printf("Enter the name of student:");
    scanf("%s",s->name);
    printf("Enter the roll number of student:");
    scanf("%d",&(s->roll_no));
    printf("Enter the cgpa of student:");
    scanf("%f",&(s->cgpa));
    return;
}
void display(student *s){
    printf("Name:%s\n",s->name);
    printf("Roll number:%d\n",s->roll_no);
    printf("cgpa:%.2f\n",s->cgpa);
    return;
}
void sort(student *s,int n){
    student temp,small;
    int min,j;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if (((s+j)->roll_no)<((s+min)->roll_no))
                min=j;
                
        }
        if(min!=i){
            temp=*(s+min);
            *(s+min)=*(s+i);
            *(s+i)=temp;
        }
        
    }
    
}
