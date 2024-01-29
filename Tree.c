#include <stdio.h>
#include <math.h>


void readTree(int tree[],int mnodes)
{
    int c;
    int i=1;
    while(i<mnodes)
    {
        scanf("%d",&c);
        tree[i]=c;
        i++;
    }

}
void main()
{
    int h;
    printf("Enter the height of the tree:");
    scanf("%d",&h);
    int mnodes=pow(2,h+1)-1;
    int tree[mnodes];
    readTree(tree,mnodes);
    for(int i=1;i<mnodes;i++)
    {
        switch (tree[i])
        {
        case (-1):
            printf("_ ");
            break;
        
        default:
            printf("%d ",tree[i]);
            break;
        }
        
    }


}
