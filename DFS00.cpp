#include<stdio.h>

int a[4]={1,2,4,7};
int n=4,k;

bool DFS(int i,int sum)
{
    if(i==n)
        return (sum==k);  //Ending condition
    if(DFS(i+1,sum))
        return true;
    if(DFS(i+1,sum+a[i]))
        return true;
    return false;
}

int main()
{
    scanf("%d",&k);
    if(DFS(0,0))
        printf("True");
    else
        printf("False");
    return 0;
}





