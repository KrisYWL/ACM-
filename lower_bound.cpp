#include<iostream>
using namespace std;

#define MAX_N 100
int n,k;
int a[MAX_N];

void solve()
{
    int lb=-1,ub=n;

    while(ub-lb>1)
    {

        int mid=(lb+ub)/2;
        if(a[mid]>=k)
        {
            ub=mid;
        }
        else
        {
            lb=mid;
        }
    }
    cout<<ub<<" The number is:"<<a[ub]<<endl;
}

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    solve();

    return 0;
}
