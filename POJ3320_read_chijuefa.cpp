#include<iostream>
#include<cstdio>
#include<set>
#include<map>
using namespace std;

int P;
int a[1000001];

void solve()
{
    int t=0,num=0,s=0;
    int res=P;
    int n;
    set<int> all;
    map<int,int> key;

    for(int i=0;i<P;i++)
        all.insert(a[i]);

    n=all.size();

    while(1)
    {
        while(t<P&&num<n)
        {
            if(key[a[t++]]++==0)
                num++;
        }

        if(num<n)
            break;

        res=min(res,t-s);
        if(--key[a[s++]]==0)
            num--;

    }
    cout<<res<<endl;
}

int main()
{
    cin>>P;
    for(int i=0;i<P;i++)
        scanf("%d",&a[i]);

    solve();

    return 0;
}
