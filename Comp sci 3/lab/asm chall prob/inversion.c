#include <stdio.h>

struct node
{
	int value;
	struct node* left;
	struct node* right;
};
typedef struct node Node;

void print_recursive(Node* n); // <- Provided 
void print_inverted(Node* n);  // <- You write

int main(int argc, char* argv[])
{
	Node n0  = {  0, NULL, NULL };
	Node n4  = {  4, NULL, NULL };
	Node n6  = {  6, NULL, NULL };
	Node n10 = { 10, NULL, NULL };
	Node n1  = {  1, &n0,  NULL };
	Node n3  = {  3, NULL, &n4  };
	Node n7  = {  7, &n6,  NULL };
	Node n9  = {  9, NULL, &n10 };
	Node n2  = {  2, &n1,  &n3  };
	Node n8  = {  8, &n7,  &n9  };
	Node n5  = {  5, &n2,  &n8  };

	print_inverted(&n5);
	return 0;
}

void print_recursive(Node* n)
{
	if (n->left != NULL)
		print_recursive(n->left);

	printf("%d\n", n->value);

	if (n->right != NULL)
		print_recursive(n->right);
}

void print_inverted(Node* root)
{
    Node* stack[1000]; 
    int top = -1;
    Node* current = root;

    while (current != NULL || top >= 0) 
	{
        // Traverse left subtree
        while (current != NULL) {
            stack[++top] = current;  // Push current node
            current = current->left; // Move to left child
        }

        
        current = stack[top--];       // Pop from stack
        printf("%d\n", current->value); // Print value

        // Traverse right subtree
        current = current->right;
    }
}
