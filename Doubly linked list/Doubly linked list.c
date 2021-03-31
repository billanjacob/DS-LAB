#include <stdio.h>
#include <stdlib.h>

struct node
{
struct node *prev;
int n;
struct node *next;
}*head,*temp,*temp1,*temp2,*temp4;
void beginsert();
void endinsert();
void speinsert();
void travbeg();
void search();
void delete();
int count = 0;
void main()
{
int select;
head = NULL;
temp = temp1 = NULL;
printf("\n 1 Insert at beginning\n 2 Insert at end\n3 Insert at  specific position\n 4 Delete at i\n 5 Display from beginning\n 6 Search for element\n 7 Exit");
while (1)
{
printf("\n Enter choice : ");
scanf("%d", &select);
switch (select)
{
case 1:
beginsert();
break;
case 2:
endinsert();
break;
case 3:
speinsert();
break;
case 4:
delete();
break;
case 5:
travbeg();
break;
case 6:
search();
break;
case 7:
exit(0);
default:
printf("\n Wrong choice menu");

}
}
}

void create()
{
int data;
temp =(struct node *)malloc(1*sizeof(struct node));
temp->prev = NULL;
temp->next = NULL;
printf("\n Enter value to node : ");
scanf("%d", &data);
temp->n = data;
count++;
}
void beginsert()
{
if (head == NULL)
{
create();
head = temp;
temp1 = head;
}
else
{
create();
temp->next = head;
head->prev = temp;
head = temp;

}
}
void endinsert()
{
if (head == NULL)
{
create();
head = temp;
temp1 = head;
}
else
{
create();
temp1->next = temp;
temp->prev = temp1;
temp1 = temp;
}
}
void speinsert()
{
int pos, i = 2;
printf("\n Enter position to be inserted : ");
scanf("%d", &pos);
temp2 = head;
if ((pos < 1) || (pos >= count + 1))
{
printf("\n Position out of range to insert");
return;
}

if ((head == NULL) && (pos != 1))
{
printf("\n Empty list cannot insert other than 1st position");
return;
}
if ((head == NULL) && (pos == 1))
{
create();
head = temp;
temp1 = head;
return;
}
else
{
while (i < pos)
{
temp2 = temp2->next;
i++;
}
create();
temp->prev = temp2;
temp->next = temp2->next;
temp2->next->prev = temp;
temp2->next = temp;
}
}
void delete()
{
int i = 1, pos;
printf("\n Enter position to be deleted : ");

scanf("%d", &pos);
temp2 = head;
if ((pos < 1) || (pos >= count + 1))
{
printf("\n Error : Position out of range to delete");
return;
}
if (head == NULL)
{
printf("\n Error : Empty list no elements to delete");
return;
}
else
{
while (i < pos)
{
temp2 = temp2->next;
i++;
}
if (i == 1)
{
if (temp2->next == NULL)
{
printf("Node deleted from list");
free(temp2);
temp2 = head = NULL;
return;
}
}
if (temp2->next == NULL)

{
temp2->prev->next = NULL;
free(temp2);
printf("Node deleted from list");
return;
}
temp2->next->prev = temp2->prev;
if (i != 1)
temp2->prev->next = temp2->next; 
if (i == 1)
head = temp2->next;
printf("\n Node deleted");
free(temp2);
}
count--;
}
void travbeg()
{
temp2 = head;
if (temp2 == NULL)
{
printf("List empty to display \n");
return;
}
printf("\n Linked list elements from begining : ");
while (temp2->next != NULL)
{
printf(" %d ", temp2->n);

temp2 = temp2->next;
}
printf(" %d ", temp2->n);
}
void search()
{
int data, count = 0;
temp2 = head;
if (temp2 == NULL)
{
printf("\n Error : List empty to search for data");
return;
}
printf("\n Enter value to search : ");
scanf("%d", &data);
while (temp2 != NULL)
{
if (temp2->n == data)
{
printf("\n Data found in %d position",count + 1);
return;
}
else
temp2 = temp2->next;
count++;
}
printf("\n Error : %d not found in list", data);
}
