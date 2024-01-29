#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    
} node;

node *top=NULL;

void push(int d)
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=d;
    newnode->next=NULL;
    if (top==NULL)
    {
        top=newnode;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }
    
}
void pop()
{
    if (top==NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        node *p=top;
        printf("The popped element is: %d\n",p->data);
        top=top->next;
        free(p);
    }
    
}
int peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        return top->data;
    }
}

void main()
{
    int c;
    int d;
    int i=1;
    while(i==1)
    {
        printf("\nEnter the choice\n1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d",&d);
            push(d);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("%d",peek());
            break;
        case 4:
            i=0;
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
}
