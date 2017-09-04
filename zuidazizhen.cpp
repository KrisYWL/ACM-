#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int n,m;
    int sum=0;
    int Max=-1000;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    }
    //cout<<a[1][1]<<endl;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            for(int p=0;p<n-i;p++)
            {
                for(int q=0;q<m-j;q++)
                {
                    sum=0;
                    for(int y=i;y<=i+p;y++)
                    {
                        for(int x=j;x<=j+q;x++)
                        {
                            sum+=a[y][x];                               
                        }
                    }
                    if(sum>Max)
                        Max=sum;
                }
            }
        }
    }
    cout<<Max<<endl;   
    return 0;
}