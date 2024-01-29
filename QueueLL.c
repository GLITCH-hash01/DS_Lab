#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    
} node;

node *front=NULL;
node *rear=NULL;

void enqueue(int d)
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=d;
    newnode->next=NULL;
    if (front==NULL)
    {
        front=newnode;
        rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
    
}

void dequeue()
{
    if (front==NULL)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        node *p=front;
        printf("The dequeued element is: %d\n",p->data);
        front=front->next;
        free(p);
    }
    
}
void display()
{
    node *p=front;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void main()
{
    int c;
    int d;
    int i=1;
    while(i==1)
    {
        printf("\nEnter the choice\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1: printf("Enter the element to be enqueued: ");
                    scanf("%d",&d);
                    enqueue(d);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: i=0;
                    break;
            default: printf("Invalid Choice\n");
        }
    }
}