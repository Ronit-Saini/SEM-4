#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodeptr;

struct node
{
    int data;
    nodeptr lchild;
    nodeptr rchild;
}node;

nodeptr root = NULL;

nodeptr insert(int element, nodeptr node)
{
    nodeptr temp;
    if(node == NULL)
    {
        temp = (nodeptr) malloc(sizeof(node));
        temp->data = element;
        temp->lchild = NULL;
        temp->rchild = NULL;
        if(root == NULL)
            root = temp;
        return temp;
    }
    else if(element < node->data)
    {
        node->lchild = insert(element, node->lchild);
        return node;
    }
    else if(element > node->data)
    {
        node->rchild = insert(element, node->rchild);
        return node;
    }
    else
    {
        printf("Duplicate Element found while inserting!\n");
        return node;
    }
}

void inorder(nodeptr node)
{
    if(node == NULL)
        return;
    inorder(node->lchild);
    printf("%d ",node->data);
    inorder(node->rchild);
}

void preorder(nodeptr node)
{
    if(node == NULL)
        return;
    printf("%d ",node->data);
    preorder(node->lchild);
    preorder(node->rchild);
}

void postorder(nodeptr node)
{
    if(node == NULL)
        return;
    postorder(node->lchild);
    postorder(node->rchild);
    printf("%d ",node->data);
}
void search(int key,nodeptr node)
{
    if(node==NULL)
    {
        printf("Key not found!!\n\n");
        node = insert(key,root);
        return;
    }
    else
    {
        if(key == node->data)
        {
            printf("Key , '%d' found!\n",key);
            return;
        }
        else if(key>node->data)
            search(key,node->rchild);
        else if(key<node->data)
            search(key,node->lchild);
    }
}

void print(nodeptr root)
{
    printf("..........PREORDER.......... : \n");
    preorder(root);
    printf("\n...........POSTORDER......... : \n");
    postorder(root);
    printf("\n............INORDER............ : \n");
    inorder(root);
    printf("\n");
}


void main()
{
    int element;
    int key;
    int ch = 1;
    while(ch == 1)
    {
        printf("Enter Element to Insert in Binary Search Tree : \n");
        scanf("%d", &element);
        insert(element, root);
        printf("Enter 1 to Insert in Binary Search Tree else Enter 0 to Stop : \n");
        scanf("%d", &ch);
    }
    print(root);
    printf("\nEnter Element to Search in Binary Search Tree : \n");
    scanf("%d", &key);
    search(key,root);
    print(root);
}
