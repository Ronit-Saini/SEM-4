#include <stdio.h>
#include <stdlib.h> 
int opcount=0;

typedef struct node {
    int val;
    struct node * left;
    struct node * right;
} Node;

Node * createNode(int x) {
    Node * new = (Node *) malloc(sizeof(Node));
    new->val = x;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void postOrder(Node *tree, int * count) {
	opcount++;
    if (tree != NULL) {
        *count = *count + 1;
        postOrder(tree->left,count);
        postOrder(tree->right,count);
    }
}

void main() {
    Node * root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->left->right->right = createNode(8);
    root->right->right->right = createNode(9);
    root->right->right->right->left = createNode(10);
    root->right->right->right->left->right = createNode(13);
    int count = 0;
    postOrder(root,&count);
    printf("Number of nodes in graph are %d\n",count);
	printf("opcount is %d",opcount);
}