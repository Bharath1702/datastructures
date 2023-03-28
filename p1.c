#include<stdio.h>
#include<stdlib.h> 
int a[20];
int n,val,i,pos;
void create();
void display();
void insert(); 
void delete();
int main()
{
int choice;
while(choice)
{
printf("\n--------MENU-----------\n");
printf(" 1.CREATE\n 2.DISPLAY\n 3.INSERT\n 4.DELETE\n 5.EXIT\n");
printf("\nENTER YOUR CHOICE:\n"); 
scanf("%d",&choice);
switch(choice)
{
case 1: create(); break;
case 2: display(); break; 
case 3:insert(); break; 
case 4: delete(); break; 
case 5: exit(0); break;
default: printf("\nInvalid choice:\n"); break;
}
}
return 0;
}
 void create()
{
printf("Enter the size of the array elements:\n"); 
scanf("%d",&n);
printf("Enter the elements for the array:\n"); 
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
}
void display()
{
int i;
printf("The array elements are:\n"); 
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
}
void insert()
{
printf("Enter the position for the new element:\n");
scanf("%d",&pos);
printf("Enter the element to be inserted :\n"); scanf("%d",&val);
for(i=n-1;i>=pos;i--)
{
a[i+1]=a[i];
}
a[pos]=val; n=n+1;
}
void delete()
{
printf("Enter the position of the element to be deleted:\n"); 
scanf("%d",&pos);
val=a[pos]; 
for(i=pos;i<n-1;i++)
{
a[i]=a[i+1];
}
n=n-1;
printf("\nThe deleted element is =%d",val);
}
