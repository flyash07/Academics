#include<stdio.h>
#include<stdlib.h>
typedef struct {
    char name[30];
    struct dob {
        int d;
        int m;
        int y;
    }birth;
    struct address {
        char house_no[10];
        int zip;
        char state[20];
    }addr;
}employee;
void read (employee *);
void display (employee *);
void main(){
    int N;
    employee *e;
    printf("Enter the number of employees:");
    scanf("%d",&N);
    e=(employee *)calloc(N,sizeof(employee));
    if (e==NULL) exit(0);
    for(int i=0;i<N;i++){
        printf("Enter details of employee %d:",i+1);
        read(e+i);
    }
    printf("The details of %d employees are:\n",N);
    for(int i=0;i<N;i++){
        printf("Details of Employee %d:\n",i+1);
        display(e+i);
    }
}
void read(employee *e){
    printf("Enter name:");
    scanf("%s",(e->name));
    printf("Enter dob:");
    scanf("%d%d%d",&(e->birth.d),&(e->birth.m),&(e->birth.y));
    printf("Enter address:");
    scanf("%s",(e->addr.house_no));
    scanf("%d",&(e->addr.zip));
    scanf("%s",(e->addr.state));
    return;    
}
void display(employee *e){
    printf("Name:%s\n",e->name);
    printf("DOB:%d/%d/%d\n",(e->birth.d),(e->birth.m),(e->birth.y));
    printf("Address:%s,%d,%s\n",(e->addr.house_no),(e->addr.zip),(e->addr.state));
    return;
}

