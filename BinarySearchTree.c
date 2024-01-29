#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
    
} node;

node *root=NULL;

void insert(int d)
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=d;
    newnode->left=NULL;
    newnode->right=NULL;
    if (root==NULL)
    {
        root=newnode;
    }
    else
    {
        node *p=root;
        node *q;
        while(p!=NULL)
        {
            q=p;
            if (d<p->data)
            {
                p=p->left;
            }
            else
            {
                p=p->right;
            }
            
        }
        if (d<q->data)
        {
            q->left=newnode;
        }
        else
        {
            q->right=newnode;
        }   
    }
}
void inorder(node *p)
{
    if (p!=NULL)
    {
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
    
}
void search(int d)
{
    node *p=root;
    while(p!=NULL)
    {
        if (d==p->data)
        {
            printf("Element found\n");
            return;
        }
        else if (d<p->data)
        {
            p=p->left;
        }
        else
        {
            p=p->right;
        }
        
    }
    printf("Element not found\n");
}
void delete(int value)
{
    node *p=root;
    node *q=NULL;
    while(p!=NULL)
    {
        if (value==p->data)
        {
            break;
        }
        else if (value<p->data)
        {
            q=p;
            p=p->left;
        }
        else
        {
            q=p;
            p=p->right;
        }
        
    }
    if (p==NULL)
    {
        printf("Element not found\n");
    }
    else if (p->left==NULL && p->right==NULL)
    {
        if (p==root)
        {
            root=NULL;
        }
        else if (q->left==p)
        {
            q->left=NULL;
        }
        else
        {
            q->right=NULL;
        }
        free(p);
    }
    else if (p->left==NULL || p->right==NULL)
    {
        if (p==root)
        {
            if (p->left==NULL)
            {
                root=p->right;
            }
            else
            {
                root=p->left;
            }
            
        }
        else if (q->left==p)
        {
            if (p->left==NULL)
            {
                q->left=p->right;
            }
            else
            {
                q->left=p->left;
            }
            
        }
        else
        {
            if (p->left==NULL)
            {
                q->right=p->right;
            }
            else
            {
                q->right=p->left;
            }
            
        }
        free(p);
    }
    else
    {
        node *r=p->right;
        node *s=NULL;
        while(r->left!=NULL)
        {
            s=r;
            r=r->left;
        }
        if (s==NULL)
        {
            p->data=r->data;
            p->right=r->right;
        }
        else
        {
            p->data=r->data;
            s->left=r->right;
        }
        free(r);
    }
}
void main()
{
    int c;
    int d;
    int i=1;
    while(i==1)
    {
        printf("\nEnter the choice\n1. Insert\n2. Traverse\n3. Search\n4. Delete\n5. Exit\n");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            printf("Enter the data\n");
            scanf("%d",&d);
            insert(d);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            printf("Enter the data\n");
            scanf("%d",&d);
            search(d);
            break;
        case 4:
            printf("Enter the data\n");
            scanf("%d",&d);
            delete(d);
            break;
        case 5:
            i=0;
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
