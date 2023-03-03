#include<stdio.h>
#include<stdlib.h>
struct node
{
struct node *lchild;
int data;
struct node *rchild;
};
typedef struct node* NODE;
NODE root = NULL;
NODE create_node(int a[],int i)
{
NODE ptr=(NODE)malloc(sizeof(struct node));
if(ptr==NULL)
{
printf("insufficient memory");
exit(0);
}
else 
{
ptr->data=a[i];
ptr->lchild=ptr->rchild=NULL;
}
return ptr;
}
NODE insert_levelorder(NODE root,int a[],int i, int n)
{
NODE ptr;
if (i<=n)
{
ptr=create_node(a,i);
root=ptr;
if(i==1)
{
printf("\n Root of the binary tree create using level order is : \n %d \n",root->data);
}
root->lchild=insert_levelorder(root->lchild,a,2*i,n);
root->rchild=insert_levelorder(root->rchild,a,2*i+1,n);
}
return root;
}
void inorder(NODE t)
{
if(t!=NULL)
{
inorder(t->lchild);
printf("%d \t",t->data);
inorder(t->rchild);
}
}
int main()
{
int a[20],i,n;
printf("Enter the number of you want in BIN tree elements");
scanf("%d",&n);
printf("enter the elements in te array , from this array binary tree constructed \n");
for (i=1;i<=n;i++)
{
scanf("%d",&a[i]);
root = insert_levelorder(root,a,i,n);
printf("\n constructed binary tree in level order is \n ");
inorder(root);
}
}
