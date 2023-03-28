#include<stdio.h>
#include<stdlib.h>
struct node
{
         char ID[25],name[25],branch[10],specialization[25];
         struct node *llink;
         struct node *rlink;
};
typedef struct node* NODE;
NODE first = NULL;
int count=0;

NODE create()
{
          NODE enode;
          enode = (NODE)malloc(sizeof(struct node));
          if( enode== NULL)
          {
                    printf("\nRunning out of memory");
                    exit(0);
           }
           printf("\nEnter the ID, Name, Branch, Area of specialization : \n");
           scanf("%s %s %s %s", enode->ID, enode->name, enode->branch, enode->specialization);
           enode->llink=NULL;
           enode->rlink=NULL;
           count++;
           return enode;
}

NODE insert()
{
          NODE cur, temp;
          temp = create();

          if(first == NULL)
          {
                    return temp;
          }
         cur= first;
         while(cur->rlink!=NULL)
        {
                  cur = cur->rlink;
         }
         cur->rlink = temp;
         temp->llink = cur;
          return first;
}
NODE delete()
{
         NODE temp;
         if(first == NULL)
         {
                   printf("\nDoubly Linked List is empty");
                   return NULL;
         }
         if(first->rlink== NULL)
        {
                  printf("\nThe employee node with the ssn:%s is deleted", first->ID);
                 free(first);
                 count--;
                  return NULL;
         }
         temp = first;
         first = first->rlink;
         temp->rlink = NULL;
         first->llink = NULL;
         printf("\nThe employee node with the ssn:%s is deleted",temp->ID);
         free(temp);
         count--;
         return first;
}
void display()
{
          NODE cur;
          int nodeno=1;
          cur = first;
          if(cur == NULL)
                      printf("\nNo Contents to display in DLL");
          while(cur!=NULL)
         {
        printf("\nENode:%d||ID:%s|Name:%s|Branch:%s|specialization:%s",nodeno,cur->ID,cur->name,cur->branch, cur->specialization);
                   cur = cur->rlink;
                    nodeno++;
         }
          printf("\nNo of employee nodes is %d",count);
}

void main()
{
       int ch;
       while(1)
      {
              printf("\nQueue Operation");   	
              printf("\n1:Insert\n2:Delete\n3:Display\n4:Exit \n");
              scanf("%d", &ch);
              switch(ch)
             {
                   case 1: first=insert();
                               break;
                   case 2: first=delete();
                              break;
                    case 3: display();
                               break;
                   default : return;
           }
     }
}
