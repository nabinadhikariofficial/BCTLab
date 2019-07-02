#include<stdio.h>

struct node
{
    int data;
    struct node *leftChild;
    struct node *rightChild;
};
struct node *root= NULL;

void insert()
{
    struct node *tempNode = (struct node*) malloc(sizeof(struct node));
    struct node *current;
    struct node *parent;
    int data;
    printf("\n\nEnter the data :- ");
    scanf("%d",&data);
    tempNode->data = data;
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;
    if(root==NULL)
        root=tempNode;
    else
    {
        current =root;
        parent=NULL;
        while(1)
        {
            parent=current;
            if(data < parent->data)
            {
                current = current->leftChild;
                if(current==NULL )
                {
                    parent->leftChild = tempNode;
                    return;
                }
            }
            else
            {
                current = current->rightChild;
                if(current==NULL)
                {
                    parent->rightChild = tempNode;
                    return;
                }
            }
        }
    }
}

struct node* search(int data)
{
    struct node *current = root;
    printf("\nVisiting elements: \n\n\t");
    while(current->data != data)
    {
        if(current != NULL)
            printf("%d,\t",current->data);

        if(current->data > data)
            current = current->leftChild;
        else
            current = current->rightChild;

        if(current==NULL)
            return NULL;
    }
    return current;
}

void pre_order_traversal(struct node* root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        pre_order_traversal(root->leftChild);
        pre_order_traversal(root->rightChild);
    }
}

void inorder_traversal(struct node* root)
{
    if(root != NULL)
    {
        inorder_traversal(root->leftChild);
        printf("%d ",root->data);
        inorder_traversal(root->rightChild);
    }
}

void post_order_traversal(struct node* root)
{
    if(root != NULL)
    {
        post_order_traversal(root->leftChild);
        post_order_traversal(root->rightChild);
        printf("%d ", root->data);
    }
}

int main()
{
     struct node *temp;
     int ch,data;
     while(1)
     {
         printf("\n\nBinary Search Tree:\n\n\t1. INSERT\n\n\t2. SEARCH\n\n\t3.TRAVERSE\n\n\t4. EXIT\n\n\t");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1:
                 insert();
                 printf("\n\t\tDATA INSERTED.");
                 break;
             case 2:
                printf("\n\nEnter data to search :- ");
                scanf("%d",&data);
                temp = search(data);
                if(temp != NULL)
                    printf("[ %d ]\n\n\tElement found (%d).",temp->data,data);
                else
                    printf("[ x ]\n\n\tElement not found (%d).", data);
                break;
            case 3:
                printf("\n Preorder traversal:\n\t");
                pre_order_traversal(root);
                printf("\n Inorder traversal:\n\t");
                inorder_traversal(root);
                printf("\nPost order traversal:\n\t");
                post_order_traversal(root);
                break;
            case 4:
                exit(0);
            default:
                printf("\n\n\tEnter correct choice.....");
         }
     }
}
