#include<stdio.h>
#include<stdlib.h>
struct node
{
char ID[25],NAME[25],BRANCH[10],SPECIALIZATION[25];
struct node* llink;
struct node* rlink;
};
typedef struct node* NODE;
NODE first = NULL;
int count =0;
NODE create()
{
NODE enode;
enode=(NODE)malloc(sizeof(struct node));
if(enode==NULL)
{
printf("\n running out of memory");
exit(0);
}
printf("\n enter the ID  \n");
scanf("%s", &enode->ID);
printf("\n enter the name \n");
scanf("%s", &enode->NAME);
printf("\n enter the BRANCH\n");
scanf("%s", &enode->BRANCH);
printf("\n enter the specialization\n");
scanf("%s", &enode->SPECIALIZATION);
enode->llink=NULL;
enode->rlink=NULL;
count++;
return enode;
}
NODE push()
{
NODE temp;
temp=create();
if(first == NULL)
{
return temp;
}
temp->rlink=first;
first->llink=temp;
return temp;
}
NODE pop()
{
NODE temp;
if(first==NULL)
{
printf("\n Under flow");
return NULL;
}
if(first->rlink==NULL)
{
printf("\n the employee node with the snn: %s is deleted",&first->ID);
free(first);
count--;
return NULL;
}
temp=first;
first=first->rlink;
temp->rlink=NULL;
first->llink=NULL;
printf("\n the employee node with the ssn: %s is deleted", &temp->ID);
free(temp);
count--;
return first;
}
void display()
{
NODE cur;
int nodeno=1;
cur= first;
if(cur==NULL)
{
printf("\n No contents to display in DLL");
return;
}
while(cur != NULL)
{
printf("\n		ENode:		%d \n		ID:		%s \n		Name:		%s \n		Branch:		%s \n		specialization:  %s",nodeno,cur->ID,cur->NAME,cur->BRANCH, cur->SPECIALIZATION);
cur=cur->rlink;
nodeno++;
}
printf("\n \n \n \n  no of employee nodes is \n %d",&count);
}
void main()
{
int ch;
while(1)
{
printf("\n Welcome to useless stack operation");
printf("\n  1:Push\n  2:Pop\n  3:display \n  4:Exit \n ");
printf("enter your useless  option \n");
scanf("%d", &ch);
switch(ch)
{
case 1: first=push();
break;
case 2:first=pop();
break;
case 3:display();
break;
default : return;
}
}
}
