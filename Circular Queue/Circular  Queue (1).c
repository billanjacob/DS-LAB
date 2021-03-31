#include <stdio.h>
#include<stdlib.h>
#define MAX 5
int front=-1;
int rear=-1;
int cqueue[MAX];
void insert();
int delete();
void display();
void search();
int main()
{
     int m,select;
     while(1)
     {
         printf("\nMenu\n");
          printf("\n1.insert\n2.delete\n3.display\n4.search");
           printf("\nselect\n");
           scanf("%d",&select);
           switch(select)
           {
               case 1:
                     insert();
                     break;
                case 2:
                      m=delete();
                      break;
                case 3:
                      display();
                      break;
                case 4: 
                      search();
                      break;
                default:
                       printf("\ninvalid option");
           }
     }
}
void insert()
{
    int m;
    if((front==0&&rear==MAX-1)||front==rear+1)
    {
         printf("\ncircular queue is full");
         return;
    }
         printf("\nEnter the number to be inserted:");
         scanf("%d",&m);
         if(front==-1)
         front=front+1;
         if(rear==MAX-1)
         rear=0;
         else rear=rear+1;
         cqueue[rear]=m;
         
    }
int delete()
{
    int d;
     if(front==-1)
     {
          printf("\ncircular queue is empty");
     }
     d=cqueue[front];
     if(front==MAX-1)
     front=0;
     else if(front==rear)
     {
          front=-1;
          rear=-1;
     }
     else front=front+1;
      printf("\n%d was deleted",d);
      return d;
    
     }
     void display()
     { 
         int i;
         if (front==-1)
         {
              printf("\ncircular queue is empty");
              return;
              
         }
     i=front;
     if(front<=rear)
     {
         while(i<=rear)
          printf("\n%d",cqueue[i++]);
          
         }
         else
         {
             while(i<=MAX-1)
             printf("\n%d",cqueue[i++]);
             i=0;
             while(i<=rear)
             printf("\n%d",cqueue[i++]);
             
         }
     }
     void search()
     {
          int ele,i,c=0;
          printf("enter the element to be searched");
          scanf("%d",&ele);
          for(i=front;i<=rear;i++)
          {
              if(ele==cqueue[i])
              {
                   printf("\nthe element is present at the location%d",i+1);
                   c++;
                   
              }
          }
          if(c==0)
          printf("element not found");
         
          }
     


