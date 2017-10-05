#include<stdio.h>

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode
{
    //ElementType Element;
    Tree Left;
    Tree Right;
}T1[MaxTree];

void PreOrderPrintLeaves(Tree BT);
Tree BuildTree(struct TreeNode T[]);

int main()
{
    Tree R;
    R=BuildTree(T1);
    PreOrderPrintLeaves(R);
    return 0;
}

void PreOrderPrintLeaves(Tree BT)
{
    if(BT!=Null)
    {
        if(T1[BT].Left==Null&&T1[BT].Right==Null)
            printf("%d ",BT);
        PreOrderPrintLeaves(T1[BT].Left);
        PreOrderPrintLeaves(T1[BT].Right);
    }
}

Tree BuildTree(struct TreeNode T[])
{
    Tree Root;
    int N;
    //int check[N];
    //...
    scanf("%d\n",&N);

    if(N)
    {
        int i;
        int check[N-1];
        char cl,cr;
        for(i=0;i<N;i++)
            check[i]=0;

        for(i=0;i<N;i++)
        {

            scanf("%c %c\n",&cl,&cr);//?????????

            if(cl!='-')
            {
                T[i].Left=cl-'0';
                check[T[i].Left]=1;
            }
            else
                T[i].Left=Null;
            if(cr!='-')
            {
                T[i].Right=cr-'0';
                check[T[i].Right]=1;
            }
            else
                T[i].Right=Null;

        }
        for(i=0;i<N;i++)
            if(!check[i]) break;
        Root=i;
    }
    else
        Root=Null;

    return Root;
}
