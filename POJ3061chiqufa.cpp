#include<iostream>
#include<algorithm>
using namespace std;

int a[100001];
int n,S;

void solve()
{   //resΪ��̳���ֵ��tΪ��β��sΪ��ͷ
    int res=n+1,t=0,s=0;
    int sum=0;
    while(1)
    {
        while(t<n&&sum<S)
        {
            sum+=a[t++];
        }

        if(sum<S)
            break;
        res=min(res,t-s);
        sum-=a[s++];
    }
    if(res>n)
        res=0;
    cout<<res<<endl;
}

int main()
{
    int times;
    cin>>times;

    for(int i=0;i<times;i++)
    {
        cin>>n>>S;
        for(int j=0;j<n;j++)
        {
            cin>>a[j];
        }
        solve();
    }

    return 0;
}
