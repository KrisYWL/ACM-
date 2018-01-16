#include<iostream>
#include<queue>

using namespace std;

#define MAX_N 20000
typedef long long ll;
int N,L[MAX_N];

void solve()
{
    ll ans=0;

    priority_queue<int,vector<int>,greater<int>> que;
    for(int i=0;i<N;i++)
        que.push(L[i]);

    while(que.size()>1)
    {
        int a,b;
        a=que.top();
        que.pop();
        b=que.top();
        que.pop();

        ans=ans+a+b;
        que.push(a+b);
    }
    cout<<ans<<endl;

    return ;
}


int main()
{
    while(cin>>N)
    {
        for(int i=0;i<N;i++)
            cin>>L[i];

        solve();
    }


    return 0;
}
