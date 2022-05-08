#include <stdio.h>
#include <stdlib.h>

// Binary Search Tree

typedef struct tree {
	int number;
	
	struct tree *left, *right;
} Tree;

void append_bst(Tree **root, int new_number)
{
	if (*root == NULL) {
		Tree *new_node = (Tree *) malloc (sizeof(Tree));
		new_node->left = new_node->right = NULL;
		new_node->number = new_number;

		*root = new_node;
		return ;
	}

	Tree *cur_node = *root;
	if (new_number < cur_node->number)
		append_bst(&(cur_node->left), new_number);
	else 
		append_bst(&(cur_node->right), new_number);
}

void print_post_bst(Tree *cur_node)
{
	if (cur_node->left != NULL) 
		print_post_bst(cur_node->left); 

	if (cur_node->right != NULL) 
		print_post_bst(cur_node->right);

	printf("%d\n", cur_node->number);
}

int main(void)
{
	int input;
	char c;
	Tree *head = NULL;

	freopen("input_1.txt", "r", stdin);

	while (scanf("%d", &input) != EOF) {
		append_bst(&head, input);
	}

	print_post_bst(head);

	return 0;
}