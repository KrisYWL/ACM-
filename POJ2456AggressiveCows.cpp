#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int N,M;
int x[100001];

bool Pan(int mid)
{
    int last=0;

    for(int i=1;i<M;i++)
    {
        int crt=last+1;
        while(x[crt]-x[last]<mid && crt<N)
        {
            crt++;
        }
        if(crt>=N) return 0;
        last=crt;
    }
    return 1;
}

void solve()
{
    sort(x,x+N);

    int lb=0;
    int rb=1000000001;

    while(rb-lb>1)
    {
        int mid=(rb+lb)/2;
        if(Pan(mid)) lb=mid;
        else rb=mid;
    }
    cout<<lb<<endl;
}

int main()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
        scanf("%d",&x[i]);

    solve();

    return 0;
}
