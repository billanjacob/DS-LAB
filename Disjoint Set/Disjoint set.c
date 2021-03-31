#include <stdio.h>
struct DisjointSet{
    int parent[10];
    int rank[10];
    int n;
}dis;
void makeset()
{
    for(int i=0;i<dis.n;i++)
    {
        dis.parent[i]=i;
        dis.rank[i]=0;
    }
}
void displayset()
{
    printf("\nparent array\n");
    for(int i=0;i<dis.n;i++)
    {
    printf("%d",dis.parent[i]);
    }
    printf("\nrank of array\n");
    for(int i=0;i<dis.n;i++)
    {
        printf("%d",dis.rank[i]);
    }
    printf("\n");
}

int find(int x)
{
    if(dis.parent[x]!=x)
    {
         dis.parent[x]=find(dis.parent[x]);
    }
    return dis.parent[x];
}

void Union(int x,int y)
{
    int xset=find(x);
    int yset=find(y);
    if(xset==yset)
    
       return;
       if (dis.rank[xset]<dis.rank[yset])
       {
           dis.parent[xset]=yset;
           dis.rank[xset]=-1;
       }
     else if (dis.rank[xset]>dis.rank[yset])
       {
           dis.parent[yset]=xset;
           dis.rank[yset]=-1;
       }  
        
    else
    {
        dis.parent[yset]=xset;
        dis.rank[xset]=dis.rank[xset]+1;
        dis.rank[yset]=-1;
    }
    
}
int main()
{
    int n,x,y;
    printf("enter the number of elements:");
    scanf("%d",&dis.n);
    makeset();
    int ch,wish;
    do
    {
        printf("\n1.union\n2.find\n3.display\n");
        printf("enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter the element to perform union:");
            scanf("%d%d",&x,&y);
            Union(x,y);
            break;
        case 2:
               printf("enter the element to check :");
               scanf("%d%d",&x,&y);
               if(find(x)==find(y))
                 printf("connected components:");
                else
                printf("no connected components:");
            break;
        case 3:
        displayset();
        break;
        }
        printf("\n do you  continue(0/1)");
        scanf("%d",&wish);
        
               }while(wish==1);
               return 0;
        }
    