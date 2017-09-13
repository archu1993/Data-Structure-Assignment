//Double Link List using XOR

#include<iostream>
#include<stdlib.h>
#include<malloc.h>
#include<stdint.h>
using namespace std;
struct llist
{
	int data;
	struct llist* link;
};
int main()
{
	struct llist* a,*b,*c,*ptr;
	a=(struct llist *)malloc(sizeof(llist));
	b=(struct llist *)malloc(sizeof(llist));
	c=(struct llist *)malloc(sizeof(llist));
	a->data=199;
	b->data=50;
	c->data=67;
	a->link=(struct llist*)((uintptr_t)b^(uintptr_t)0);
	b->link=(struct llist*)((uintptr_t)a^(uintptr_t)c);
	c->link=(struct llist*)((uintptr_t)0^(uintptr_t)b);
	cout<<"Forward Traversal..."<<endl;
	ptr=a;
	cout<<ptr->data;
	cout<<"->";
	ptr=ptr->link;
	cout<<ptr->data;
	cout<<"->";
	ptr=(struct llist*)((uintptr_t)ptr->link^(uintptr_t)a);
	cout<<ptr->data;
	cout<<endl<<"Backward Traversal..."<<endl;
	ptr=c;
	cout<<ptr->data<<"->";
	ptr=ptr->link;
	cout<<ptr->data<<"->";
	ptr=(struct llist*)((uintptr_t)c^(uintptr_t)ptr->link);
	cout<<ptr->data;
	
}
