#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int Need[n][];
    for(int i=0;i<n;i++)
    {
        int EveryNeed=0;
        cin>>EveryNeed;

        for(int j=0;j<EveryNeed;j++)
        {
            scanf("%d",Need[i][j]);
        }
    }
    cout<<Need[00]<<endl;
    return 0;
}
