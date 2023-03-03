#include<stdio.h>
#include<stdlib.h>
struct node
{
struct node *lchild;
int data;
struct node *rchild;
};
typedef struct node* NODE;
NODE root=NULL;
NODE create_node()
{
NODE ptr;
ptr=(NODE)malloc(sizeof(struct node));
if(ptr==NULL)
{
printf("Insufficient memory\n");
exit(0);
}
else
{
printf("Enter data:: ");
scanf("%d",&ptr->data);
ptr->lchild=ptr->rchild=NULL;}
return ptr;
}
NODE create_bst(NODE root)
{
NODE ptr, temp, p;
ptr=create_node();
if(root==NULL)
{
root=ptr;
return root;
}
p=NULL;
temp=root;
while(temp!=NULL)
{
p=temp;
if(ptr->data==temp->data)
{
printf("Duplicate items are not allowed\n\n");
free(ptr);
return root;
}
if(ptr->data<temp->data)
temp=temp->lchild;
else
temp=temp->rchild;
}
if(ptr->data<temp->data)
{
temp=temp->lchild;
}
else
{
temp=temp->rchild;
}
if(ptr->data<p->data)
p->lchild=ptr;
else
p->rchild=ptr;
return root;
}
void inorder(NODE t)
{
if(t!=NULL)
{
inorder(t->lchild);
printf("%d\t",t->data);
inorder(t->rchild);
}
}
void preorder(NODE t)
{
if(t!=NULL)
{
printf("%d\t",t->data);
preorder(t->lchild);
preorder(t->rchild);
}
}
void postorder(NODE t)
{
if(t!=NULL)
{
postorder(t->lchild);
postorder(t->rchild);
printf("%d\t",t->data);
}
}
void traverse(NODE root)
{
if(root==NULL)
printf("Empty tree\n\n");
else
{
printf("\n\nPreorder traversal:\t");
preorder(root);
printf("\n\nInorder traversal:\t");
inorder(root);printf("\n\nPostorder traversal:\t");
postorder(root);
}
}
void main()
{
int ch,n,i;
for(;;)
{
printf("\n\nOPERATIONS ON BST\n\n");
printf("\n\n1:CREATE BST \n2:TRAVERSE BST\n3:EXIT\n\n");
printf("Enter your choice::");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter number of elements in BST::");
scanf("%d",&n);
for(i=0;i<n;i++)
root=create_bst(root);
break;
case 2: traverse(root);
break;
default: exit(0);
}
}
}
