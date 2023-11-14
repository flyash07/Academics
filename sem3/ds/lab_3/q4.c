#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int d;
    int *m;
    int y;
}DOB;
typedef struct{
    int reg_no;
    char *name;
    char addr[50];
}STU_INFO;
typedef struct{
    char *clg_name;
    char uni_name[20];
}COLLEGE;
typedef struct{
    DOB *a;
    STU_INFO b;
    COLLEGE c;
}STUDENT;
void read(STUDENT *);
void display(STUDENT *);
void main(){
    STUDENT *s;
    s=(STUDENT *)malloc(sizeof(STUDENT));
    s->a=(DOB *)malloc(sizeof(DOB));
    s->a->m=(int *)malloc(sizeof(int));
    s->b.name=(char *)calloc(20,sizeof(char));
    s->c.clg_name=(char *)calloc(20,sizeof(char));
    if (s==NULL) exit(0);
    printf("Enter details of the student\n");
    read(s);
    printf("Displaying details of the student\n");
    display(s);
}
void read(STUDENT *s){
    printf("Enter dob:");
    scanf("%d%d%d",&(s->a->d),(s->a->m),&(s->a->y));
    printf("Enter reg_no:");
    scanf("%d",&(s->b.reg_no));
    printf("Enter name:");
    scanf("%s",(s->b.name));
    printf("Enter address:");
    scanf("%s",(s->b.addr));
    printf("Enter college name:");
    scanf("%s",(s->c.clg_name));
    printf("Enter university name:");
    scanf("%s",(s->c.uni_name));
}
void display(STUDENT *s){
    printf("DOB:%d/%d/%d\n",(s->a->d),*(s->a->m),(s->a->y));
    printf("reg_no:%d\n",(s->b.reg_no));
    printf("name:%s\n",(s->b.name));
    printf("Address:%s\n",(s->b.addr));
    printf("College name:%s\n",(s->c.clg_name));
    printf("University name:%s\n",(s->c.uni_name));
}
