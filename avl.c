// Left Rotation and Right Rotation in AVL

#include<stdio.h>
#include<stdlib.h>

struct node
{
struct node* left;
int data;
struct node * right;
int height;
};


int height(struct node *n)
{
if(n==NULL)
return 0;
return n->height;
}


int max(int c,int d)
{
return(c>d)?c:d;
}


struct node* create(int key)
{

struct node* new_node=(struct node*)malloc(sizeof(struct node));
new_node->data=key;
new_node->left=NULL;
new_node->right=NULL;
new_node->height=1;
return(new_node);

}

struct node *right_rotation(struct node* y)
{

struct node* x=y->left;
struct node* t2=x->right;

x->right=y;
y->left=t2;

y->height=max(height(y->left),height(y->right))+1;
x->height=max(height(x->left),height(x->right))+1;

return x;

}


struct node* left_rotation(struct node* x)
{

struct node* y=x->right;
struct node* t2=y->left;

y->left=x;
x->right=t2;

x->height=max(height(x->left),height(x->right))+1;
y->height=max(height(y->left),height(y->right))+1;

return y;

}


int calculate_bf(struct node* n)
{

if(n==NULL)
return 0;
return height(n->left)-height(n->right);

}


struct node* insert(struct node* node,int key)
{

if(node==NULL)
return (create(key));

if(key<node->data)
node->left=insert(node->left,key);

else if(key>node->data)
node->right=insert(node->right,key);

else
return node;

node->height=1+max(height(node->left),height(node->right));

int balance=calculate_bf(node);

if(balance>1 && key<node->left->data)
return right_rotation(node);

if(balance>1 && key>node->left->data)
{
node->left=left_rotation(node->left);
return right_rotation(node);
}


if(balance<-1 && key>node->right->data)
return left_rotation(node);

if(balance<-1 && key<node->right->data)
{
node->right=right_rotation(node->right);
return left_rotation(node);
}

return node;

}


void preorder(struct node* root)
{

if(root!=NULL)
{

printf(" %d ",root->data);
preorder(root->left);
preorder(root->right);

}

}


void inorder(struct node* root)
{

if(root!=NULL)
{
inorder(root->left);
printf(" %d ",root->data);
inorder(root->right);
}
}


int main()
{

struct node* root=NULL;

root=insert(root,100);
root=insert(root,204);
root=insert(root,60);
root=insert(root,70);
root=insert(root,5);
root=insert(root,125);

printf("Preorder traversal of the AVL is \n");
preorder(root);
printf("\n");

printf("\nInorder traversal of AVL is \n");
inorder(root);
printf("\n");

return 0;

}




















