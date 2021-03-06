// C++ program of AVL tree that 
// handles duplicates 
#include <stdio.h> 
#include <stdlib.h> 

// An AVL tree node 
struct node { 
	int key; 
	struct node* left; 
	struct node* right; 
	int height; 
	//int count; 
}; 

// A utility function to get maximum of two integers 
int max(int a, int b); 

// A utility function to get height of the tree 
int height(struct node* N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 

// A utility function to get maximum of two integers 
int max(int a, int b) 
{ 
	return (a > b) ? a : b; 
} 

/* Helper function that allocates a new node with the given key and 
	NULL left and right pointers. */
struct node* newNode(int key) 
{ 
	struct node* node = (struct node*) 
		malloc(sizeof(struct node)); 
	node->key = key; 
	node->left = NULL; 
	node->right = NULL; 
	node->height = 1; // new node is initially added at leaf 
	//node->count = 1; 
	return (node); 
} 

// A utility function to right rotate subtree rooted with y 
// See the diagram given above. 
struct node* rightRotate(struct node* y) 
{ 
	struct node* x = y->left; 
	struct node* T2 = x->right; 

	// Perform rotation 
	x->right = y; 
	y->left = T2; 

	// Update heights 
	y->height = max(height(y->left), height(y->right)) + 1; 
	x->height = max(height(x->left), height(x->right)) + 1; 

	// Return new root 
	return x; 
} 

// A utility function to left rotate subtree rooted with x 
// See the diagram given above. 
struct node* leftRotate(struct node* x) 
{ 
	struct node* y = x->right; 
	struct node* T2 = y->left; 

	// Perform rotation 
	y->left = x; 
	x->right = T2; 

	// Update heights 
	x->height = max(height(x->left), height(x->right)) + 1; 
	y->height = max(height(y->left), height(y->right)) + 1; 

	// Return new root 
	return y; 
} 

// Get Balance factor of node N 
int getBalance(struct node* N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
} 

struct node* insert(struct node* node, int key) 
{ 
	/* 1. Perform the normal BST rotation */
	if (node == NULL) 
		return (newNode(key)); 

	// If key already exists in BST, increment count and return 
	if (key == node->key) { 
		//(node->count)++; 
		return node; 
	} 

	/* Otherwise, recur down the tree */
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else
		node->right = insert(node->right, key); 

	/* 2. Update height of this ancestor node */
	node->height = max(height(node->left), height(node->right)) + 1; 

	/* 3. Get the balance factor of this ancestor node to check whether 
	this node became unbalanced */
	int balance = getBalance(node); 

	// If this node becomes unbalanced, then there are 4 cases 

	// Left Left Case 
	if (balance > 1 && key < node->left->key) 
		return rightRotate(node); 

	// Right Right Case 
	if (balance < -1 && key > node->right->key) 
		return leftRotate(node); 

	// Left Right Case 
	if (balance > 1 && key > node->left->key) { 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 

	// Right Left Case 
	if (balance < -1 && key < node->right->key) { 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 

	/* return the (unchanged) node pointer */
	return node; 
} 

/* Given a non-empty binary search tree, return the node with minimum 
key value found in that tree. Note that the entire tree does not 
need to be searched. */
struct node* minValueNode(struct node* node) 
{ 
	struct node* current = node; 

	/* loop down to find the leftmost leaf */
	while (current->left != NULL) 
		current = current->left; 

	return current; 
} 

// A utility function to print preorder traversal of the tree. 
// The function also prints height of every node 
void preOrder(struct node* root) 
{ 
	if (root != NULL) { 
		//printf("%d(%d) ", root->key, root->count); 
		preOrder(root->left); 
		preOrder(root->right); 
	} 
} 

void inOrder(struct node* root)
{
	if (root != NULL) {
		inOrder(root->left);
		printf("%d ", root->key);
		inOrder(root->right);
	}
}

/* Driver program to test above function*/
int main() 
{ 
	struct node* root = NULL; 
	int N, M, in;

	freopen("input_3.txt", "r", stdin);

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N + M; i++) {
		scanf("%d", &in);

		root = insert(root, in);
	}

	/* Constructing tree given in the above figure */
	/*
	root = insert(root, 9); 
	root = insert(root, 5); 
	root = insert(root, 10); 
	root = insert(root, 5); 
	root = insert(root, 9); 
	root = insert(root, 7); 
	root = insert(root, 17); 
	*/

	//printf("Pre order traversal of the constructed AVL tree is \n"); 
	//preOrder(root); 
	//root = deleteNode(root, 9); 
	//printf("\nPre order traversal after deletion of 9 \n"); 
	inOrder(root); 

	return 0; 
} 

