// Implement Stack using Linklist


#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node* next;
};

void push(struct node **head_ref,int new_data)
{

struct node* new_node=(struct node*)malloc(sizeof(struct node));
new_node->data=new_data;
new_node->next=*head_ref;
*head_ref=new_node;

}

void pop(struct node** head_ref)
{

struct node* temp=*head_ref;

*head_ref=temp->next;
int y=temp->data;
free(temp);


printf(" Deleted data is \n %d ",y);
printf("\n");

}

void printlist(struct node *head)
{
while(head!=NULL)
{
printf(" %d ",head->data);
head=head->next;
}

}

int main()
{
int n,arr,m;
struct node* head=NULL;


printf(" No of elements you want to push = ");
scanf(" %d",&n);

printf("Enter the data you want to push \n");
for(int i=0;i<n;i++)
{
scanf("%d",&arr);
push(&head,arr);
}


printf(" Data in the linklist are \n");
printlist(head);
printf("\n");

printf(" No of elements you want to pop =");
scanf("%d",&m);

for(int j=0;j<m;j++)
{

pop(&head);
}

printf(" LinkList after Deletion is \n");
printlist(head);
printf("\n");

return 0;
}


