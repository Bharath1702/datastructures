#include<stdio.h>
#include<stdlib.h>
void create();
void crtscnd();
void display();
void inst_frt();
void deletefrt();
struct node
{
int info;
struct node *link;
};
struct node *start = NULL, *second = NULL, *temp;
int main()
{
int choice;
while(1)
{
printf("\n welcome, Choose one from menu");
printf("\n 1.create \n 2.create second \n 3.display \n 4.insert front \n 5.delete front");
scanf("%d",&choice);
switch(choice)
{
case 1:create();
break;
case 2:crtscnd();
break;
case 3:display();
break;
case 4:inst_frt();
break;
case 5:deletefrt();
break;
}
}
return 0;
}
void create()
{
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
if(newnode==NULL)
{
printf("out of memory");
exit(0);
}
printf("enter the value for the node :- ");
scanf("%d",&newnode->info);
if (start==NULL)
{
temp=start=newnode;
}
else
{
temp->link=newnode;
temp=newnode;
temp->link=NULL;
}
}
void crtscnd()
{
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
if (newnode==NULL)
{
printf("out of memory ");
exit(0);
}
printf("enter the value for the node");
scanf("%d",&newnode->info);
struct node* secondnd;
if (secondnd==NULL)
{
temp=secondnd=newnode;
}
else
{
temp->link=secondnd;
temp=secondnd;
temp->link=NULL;
}
}
void display()
{
struct node* ptr;
if(start==NULL)
{
printf("list is empty");
return;
}
else
{
ptr=start;
printf("the elements are :- \n \n \n \n");
while(ptr !=NULL)
{
printf("%d",&ptr->info);
ptr=ptr->link;
}
}
}
void inst_frt()
{
struct node* instnode;
instnode=(struct node*)malloc(sizeof(struct node));
if (instnode==NULL)
{
printf("out of memory");
}
if (instnode != NULL)
{
printf("enter the value to be inserted in front");
scanf("%d",&instnode->info);
instnode->link=start;
start=instnode;
}
}
void deletefrt()
{
struct node* dfnode;
struct node* ptr;
dfnode=start;
if (start==NULL)
{
printf("the node is empty");
return;
}
else
{
ptr=dfnode=start;
ptr=ptr->link;
start=ptr;
free(dfnode);
}
}
