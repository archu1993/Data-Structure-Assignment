//Implementation of queue using linklist


#include<stdio.h>
#include<stdlib.h>

struct node
{

int data;
struct node* next;
};

void enqueue(struct node** head_ref,int new_data)
{

struct node* new_node=(struct node*)malloc(sizeof(struct node));
new_node->data=new_data;
new_node->next=*head_ref;
*head_ref=new_node;

}

void dequeue(struct node** head_ref)
{

int y;
struct node* temp=*head_ref;
struct node* t;

while(temp->next!=NULL)
{
t=temp;
temp=temp->next;
}

t->next=NULL;
y=temp->data;
free(temp);
printf(" %d ",y);
//printf("\n");
}

void printlist(struct node* head)
{


printf("Data in the Queue \n");

while(head!=NULL)
{

printf(" %d ",head->data);
head=head->next;
}
}

int main()
{

struct node *head=NULL;
int i,j,n,m,arr;


printf("No of elements to insert = ");
scanf("%d",&n);

printf("Enter the Numbers to insert \n");

for(i=0;i<n;i++)
{
scanf("%d",&arr);
enqueue(&head,arr);
}

printlist(head);

printf("\nNo of elements to delete = ");
scanf("%d",&m);

printf("Deleted numbers are = ");
for(j=0;j<m;j++)
{
dequeue(&head);
}
printf("\n");
printlist(head);
printf("\n");

return 0;

}




