#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
    
} node;

node *head=NULL;

void insertfirst(int d)
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=d;
    newnode->prev=NULL;
    newnode->next=NULL;
    if (head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    
}
void insertlast(int d)
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=d;
    newnode->prev=NULL;
    newnode->next=NULL;
    if (head==NULL)
    {
        head=newnode;
    }
    else
    {
        node *p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=newnode;
        newnode->prev=p;
    }
    
}
void insertat(int d,int pos)
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=d;
    newnode->prev=NULL;
    newnode->next=NULL;
    int i=1;
    if (head==NULL)
    {
        head=newnode;
    }
    else
    {
        node *p=head;
        while(i<pos-1)
        {
            p=p->next;
            i++;
        }
        newnode->next=p->next;
        p->next->prev=newnode;
        p->next=newnode;
        newnode->prev=p;
    }
    
}
void deletefirst()
{
    if (head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        node *p=head;
        head=head->next;
        head->prev=NULL;
        free(p);
    }
    
}
void deletelast()
{
    if (head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        node *p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->prev->next=NULL;
        free(p);
    }
    
}
void deleteat(int pos)
{
    if (head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        node *p=head;
        int i=1;
        while(i<pos-1)
        {
            p=p->next;
            i++;
        }
        p->next=p->next->next;
        p->next->prev=p;
    }
    
}
void display()
{
    if (head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        node *p=head;
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }
    }
    
}
void main()
{
    int ch,d,pos;
    int i=1;
    while(i==1)
    {
        printf("\n1.Insert at first\n2.Insert at last\n3.Insert at position\n4.Delete at first\n5.Delete at last\n6.Delete at position\n7.Display\n8.Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d",&d);
            insertfirst(d);
            break;
        case 2:
            printf("Enter the data: ");
            scanf("%d",&d);
            insertlast(d);
            break;
        case 3:
            printf("Enter the data: ");
            scanf("%d",&d);
            printf("Enter the position: ");
            scanf("%d",&pos);
            insertat(d,pos);
            break;
        case 4:
            deletefirst();
            break;
        case 5:
            deletelast();
            break;
        case 6:
            printf("Enter the position: ");
            scanf("%d",&pos);
            deleteat(pos);
            break;
        case 7:
            display();
            break;
        case 8:
            i=0;
            break;
        default:
            printf("Invalid choice");
            break;
        }
    }
}

