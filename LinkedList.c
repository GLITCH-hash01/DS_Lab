#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head=NULL;

void insertlast(int d)
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=d;
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
    }
}
void insertfirst(int d)
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=d;
    newnode->next=NULL;
    if (head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}
void display()
{
    node *p=head;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void insertat(int d,int pos)
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=d;
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
        p->next=newnode;
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
        while(p->next->next!=NULL)
        {
            p=p->next;
        }
        node *q=p->next;
        p->next=NULL;
        free(q);
    }
}
void deletepos(int pos)
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
        node *q=p->next;
        p->next=q->next;
        free(q);
    }
}
void main()
{
    int ch,d,pos;
    int i=1;
    while(i==1)
    {
        printf("\n1.Insert at last\n2.Insert at first\n3.Insert at position\n4.Delete first\n5.Delete last\n6.Delete at position\n7.Display\n8.Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the data: ");
                scanf("%d",&d);
                insertlast(d);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d",&d);
                insertfirst(d);
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
                deletepos(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                i=0;
                break;
            default:
                printf("Invalid choice");
        }
    }
}
