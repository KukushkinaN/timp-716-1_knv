#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
	int value;
    	int key;
	struct tree *left;
    	struct tree *right;
    	struct tree *parent;
} node;

int lvl=0;
node* create(int key, int value){
    node *tmp = malloc(sizeof(node));

    tmp -> value = value;
    tmp -> key = key;

    tmp -> parent = NULL;
    tmp -> left = NULL;
    tmp -> right = NULL;
         
    return tmp;
}

void add(node* root, int key, int value)
{

	while(1)
	{
		if (root->key==key)
		{
			root->value=value;
			break;
		}
		
		if (key>root->key)
		{
			if (root->right==NULL)
			{
				node *tmp = malloc(sizeof(node));
				root->right = tmp;
				tmp->key=key;
				tmp->value=value;
				tmp->parent=root;
				break;
			}
			else
			{
				root=root->right;
				continue;
			}
		}
		
		if (key<root->key)
		{
			if (root->left==NULL)
			{
				node *tmp = malloc(sizeof(node));
				root->left = tmp;
				tmp->key=key;
				tmp->value=value;
				tmp->parent=root;
				break;
			}
			else
			{
				root=root->left;
				continue;
			}
		}
    }
}
int search(node* root, int key){
	lvl++;
	if (root==NULL)
		return -1;	
		
	if (root -> key == key)
		return root->value;

	if (key < root -> key)
        	return search(root -> left, key);
    	else return search(root -> right, key);
}

void preorder(node *root)
{
    if (root == NULL)
        return;
    if (root -> key)
        printf("%d ", root -> key);
    preorder(root -> left);
    preorder(root -> right);
}

int main()
{
  int n, key, value;
  scanf ("%d", &n);
  scanf("%d", &key);
  scanf("%d", &value);
  node *root = create(key, value);
  for (int i=1; i<n; i++)
 {
           scanf("%d", &key);
           scanf("%d", &value);
           add (root, key, value);
        }
        for (int i=0; i<3; i++)
        {
        int temp=0;
        	lvl=-1;
                scanf("%d", &key);
                temp=search(root,key);
                if (temp!=-1)
                	printf("%d ", lvl);
                printf("%d", temp);
                
                printf ("\n");
        }
}
