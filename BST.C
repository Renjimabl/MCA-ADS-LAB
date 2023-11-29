#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
	int data;
	struct node*left;
	struct node*right;
};
typedef struct node node;
struct node*root = NULL;
struct node*create_node(int);
void insert(int);
struct node*delete(struct node*,int);
int search(int);
void printtree(struct node*,int);
void inorder(struct node*);
void postorder();
void preorder();
struct node*smallest_node(struct node*);
struct node*largest_node(struct node*);
int get_data();
int main()
{
int userchoice;
int userActive = 'Y';
int data;
struct node*result = NULL;
clrscr();
while(userActive =='Y'||userActive == 'y')
{
printf("\n\n.....Operation of Binary Search Tree...\n");
printf("\n 1.Insertion");
printf("\n 2.Deletion");
printf("\n 3.Searching");
printf("\n 4.Get largest data");
printf("\n 5.Get smallest data");
printf("\n 6.Printing the tree");
printf("\n\n...Traversals...");
printf("\n 7.Preorder");
printf("\n 8.Inorder");
printf("\n 9.Postorder");
printf("\n 10.Exit");
printf("\n Enter your choice:");
scanf("%d",&userchoice);
printf("\n");
switch(userchoice)
{
	case 1:
		data = get_data();
		insert(data);
		break;
	case 2:
		data = get_data();
		root = delete(root,data);
		printf("\n%d deleted",data);
		break;
	case 3:
		data = get_data();
		if(search(data)==1)
		{
			printf("\n Data was found!\n");
		}
		else
		{
			printf("\n Data not found!\n");
		}
		break;
	case 4:
		result = largest_node(root);
		if(result!=NULL)
		{
			printf("\n largest data: %d\n",result->data);
		}
		break;
	case 5:
		result = smallest_node(root);
		if(result!=NULL)
		{
		printf("\n smallest Data:%d\n",result->data);
		}
		break;
	case 6:
		printf("\n Binary search tree\n");
		printtree(root,1);
		break;
	case 7:
		printf("\n Preorder Traversal\n");
		preorder(root);
		break;
	case 8:
		printf("\n Inorder Traversal\n");
		inorder(root);
		break;
	case 9:
		printf("\n Postorder Traversal\n");
		postorder(root);
		break;
	case 10:
		exit(0);
		break;
	default:printf("\n\tInvalid choice\n");
		break;
}
printf("\n______\nDo you want to continue?(y/n)");
fflush(stdin);
scanf("%c",&userActive);
}
return 0;
}
struct node*create_node(int data)
{
	struct node*new_node = (struct node*)malloc(sizeof(struct node));
	if(new_node==NULL)
	{
		printf("\n memory for new node can't be allocated");
		return NULL;
	}
	new_node -> data = data;
	new_node -> left = NULL;
	new_node -> right = NULL;
	return new_node;
}
void insert(int data)
{
	struct node*temp,*prev;
	struct node*new_node = create_node(data);
	if(new_node!=NULL)
		{
			if(root==NULL)
			{
				root = new_node;
				printf("\n Data %d was inserted in Node \n",data);
				return;
			}
		temp = root;
		prev = NULL;
			while(temp!=NULL)
			{
				prev = temp;
				if(data>temp->data)
				{
					temp = temp->right;
				}
				else
				{
					temp =temp->left;
				}
			}
			if(data>prev->data)
			{
				prev->right = new_node;
			}
			else
			{
				prev->left = new_node;
			}
			printf("\nData %d was inserted in node\n",data);
		}
}
	struct node*delete(struct node*root,int key)
	{
		struct node*temp;
		if(root == NULL)
		{
			return root;
		}
		if(key<root->data)
			{
				root->left = delete(root->left,key);
			}
		else if(key>root->data)
			{
				root->right = delete(root->right,key);
			}
		else
			{
				if(root->left==NULL)
				{
					struct node*temp=root->right;
					free(root);
					return temp;
				}
				else if(root->right==NULL)
				{
					struct node*temp = root->left;
					free(root);
					return temp;
				}
				temp = smallest_node(root->right);
				root->data = temp->data;
				root->right =delete(root->right,temp->data);
			}
			return root;
	}
int search(int key)
{
	struct node*temp = root;
	while(temp!=NULL)
	{
		if(key==temp->data)
		{
			return 1;
		}
		else if(key>temp->data)
		{
			temp = temp->right;
		}
		else
		{
			temp = temp->left;
		}
	}
return 0;
}
struct node*smallest_node(struct node*root)
{
	struct node*curr = root;
	while(curr!=NULL&&curr->left!=NULL)
	{
		curr = curr->left;
	}
	return curr;
}
struct node*largest_node(struct node*root)
{
	struct node*curr = root;
	while(curr!=NULL&&curr->right!=NULL)
	{
		curr = curr->right;
	}
	return curr;
}
void printtree(struct node*t,int level)
{
	int i;
	if(t!=NULL)
	{
		printtree(t->left,level+1);
		for(i=0;i<level;i++)
		{
			printf(" ");
		}
		printf("%d\n",t->data);
		printtree(t->right,level+1);
	}
}
void inorder(struct node*root)
{
	if(root ==NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%d",root->data);
	inorder(root->right);
}
void preorder(struct node*root)
{
	if(root ==NULL)
	{
		return;
	}
	printf("%d",root->data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(struct node*root)
{
	if(root == NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d",root->data);
}
int get_data()
{
	int data;
	printf("\n Enter Data:");
	scanf("%d",&data);
	return data;
}
