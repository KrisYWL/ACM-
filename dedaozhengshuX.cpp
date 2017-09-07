#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n,X;
    int ans=0;

    scanf("%d %d",&n,&X);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    for(int i=0;i<(1<<6);i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
                sum+=a[j];
        }
        if(sum==X)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
