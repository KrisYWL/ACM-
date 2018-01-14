#include<iostream>
#include<stdio.h>
using namespace std;

char c[2001];
int n;

void solve()
{
    int a=0,b=n-1,ans=0;
    bool left=false;

    while(a<=b)
    {
        for(int i=0;a+i<=b;i++)
        {
            if(c[a+i]<c[b-i])
                {
                    left=true;
                    break;
                }
            else if(c[a+i]>c[b-i])
                {
                    left=false;
                    break;
                }
        }

        if(left==true)
            cout<<c[a++];
        else
            cout<<c[b--];
        ans++;
        if(ans%80==0)
            cout<<endl;

    }

    return ;
}


int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }

    solve();

    return 0;
}
