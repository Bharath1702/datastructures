#include<stdio.h>
#include<stdlib.h>

void create();
void display();
void insert_front();
void insert_rear();
void delete_front();
void delete_rear();
void stack();
void queue();
void search();
void create_secondlinkedlist();
void concat();

struct node
{
    int info;
    struct node*next;
};
struct node*start=NULL,*last=NULL,*temp;

int main()
{
int choice;
while(1){
    printf("\n--------MENU-------\n");
    printf(" 1. create\n ");
    printf(" 2. display\n");
    printf(" 3. insertfront\n ");
    printf(" 4. insertrear\n");
    printf(" 5. deletefront\n");
    printf(" 6. deleterear\n");
    printf(" 7. stack\n");
    printf(" 8. queue\n ");
    printf(" 9. search \n");
    printf("10. create secondlinkedlist\n ");
    printf(" 11. concat\n ");
    printf(" 12. exit\n");
    printf("Enter your choice\n" );
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:create();
        break;
        case 2:display();
        break;
        case 3:insert_front();
        break;
        case 4:insert_rear();
        break;
        case 5:delete_front();
        break;
        case 6:delete_rear();
        break;
        case 7:stack();
        break;
        case 8:queue();
        break;
        case 9:search();
        break;
        case 10:create_secondlinkedlist();
        break;
        case 11:concat();
        break;
        case 12:exit(0);
        default:printf("invalid choice\n");
    }
    }
    return 0;
    }
    
    void create()
    {
        struct node*newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Out of Memory\n");
            exit(0);
        }
        else
        {
            printf("enter the value:");
            scanf("%d",&newnode->info);
        }
        if(start==NULL)
        {
            temp=start=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
            temp->next=NULL;
        }
        }
    void create_secondlinkedlist ()
    {
        int info;
        struct node*newnode,*second;
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Out of Memory\n");
            exit(0);
        }
        else
        {
            printf("enter the value:");
            scanf("%d",&newnode->info);
        }
        if(second==NULL)
        {
            temp=start=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
            temp->next=NULL;
        }
    }
    
    void display()
    {
        int info;
        struct node*ptr;
        if(start==NULL)
        {
            printf("List is Empty");
            return;
        }
        else
        {
            ptr=start;
            printf("The Elements are:\n");
            while(ptr!=NULL)
            {
                printf("%d\t",ptr->info);
                ptr=ptr->next;
            }
            printf("\n");
        }
    }
void search()
{
    struct node*p;
    int key,count=0;
    printf("Enter the key\n");
    scanf("%d",&key);
    printf("Key is %d\n",key);
    if(start==NULL)
    {
        printf("No data\n");
    }
        else
        {
            p=start;
            while(p!=NULL)
            {
                printf("%d\t",p->info);
                if(key==p->info)
                {
                    count++;
                    break;
                }
                else
                p=p->next;
            }
            if(count==1)
            {
                printf("\n key found\n");
            }
            else{
                printf("\n key not found\n");
            }
        }
}
void concat()
{
    struct node*p=start,*second;
    while(p->next!=NULL)
    {
        p=p->next;
    }
     p->next=second;
}
    void insert_rear()
            {
                struct  node*cur;
                struct node*newnode;
                newnode=(struct node*)malloc(sizeof(struct node));
                if(newnode==NULL)
                {
                    printf("Out of Memory\n");
                    exit(0);
                }
                printf("Enter the value for the new node \n");
                scanf("%d",&newnode->info);
                cur=start;
                while(cur->next!=NULL)
                {
                    cur=cur->next;
                }
                cur->next=newnode;
                newnode->next=NULL;
            }
void insert_front()
{
struct node*newnode;
                newnode=(struct node*)malloc(sizeof(struct node));
                if(newnode==NULL)
                {
                    printf("Out of Memory\n");
                    exit(0);
                }
                printf("Enter the value for the new node \n");
                scanf("%d",&newnode->info);
                newnode->next=start;
                start=newnode;
}
    void delete_front()
    {
               struct  node*first;
                struct node*ptr;
               first=start;
                if(start==NULL)
                {
                    printf("List is Empty\n");
                    return;
                }
               else
               {
                   ptr=first=start;
                   ptr=ptr->next;
                   start=ptr;
                   free(first);
               }
    }
void delete_rear()
            {
                struct  node*prev;
                struct node*cur;
               while(cur->next!=NULL)
               {
                   prev=cur;
                   cur=cur->next;
               }
               prev->next=NULL;
               free(cur);
            }
void stack()
{
    int choice;
    while(1)
    {
        printf("\n-------MENU------\n");
        printf("\n1.Insert_front\n");
         printf("\n2.delete_front\n");
          printf("\n3.display\n");
           printf("\n4.exitt\n");
           printf("Enter your choice:\n");
           scanf("%d",&choice);
           switch(choice)
           {
               case 1:insert_front();
               break;
               case 2:delete_rear();
               break;
               case 3:display();
               break;
               case 4:exit(0);
               default:printf("Invalid choice\n");
               break;
           }
    }
}
    void queue()
    {
         int choice;
    while(1)
    {
        printf("\n-------MENU------\n");
        printf("\n1.insert_rear\n");
         printf("\n2.delete_front\n");
          printf("\n3.display\n");
           printf("\n4.exitt\n");
           printf("Enter your choice:\n");
           scanf("%d",&choice);
           switch(choice)
           {
               case 1:insert_rear();
               break;
               case 2:delete_rear();
               break;
               case 3:display();
               break;
               case 4:exit(0);
               default:printf("Invalid choice\n");
               break; 
           }
    }
    }
