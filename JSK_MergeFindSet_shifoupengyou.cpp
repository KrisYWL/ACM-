#include<iostream>
using namespace std;

int Fri[5001];

void init(int n)
{
    for(int i=1;i<=n;i++)
        Fri[i]=i;
}

int Find(int x)
{
    if(Fri[x]==x)
        return x;
    else
        return Fri[x]=Find(Fri[x]);
}

void merge(int x,int y)
{
    x=Find(x);
    y=Find(y);

    if(x==y)
        return;
    else
    {
        Fri[y]=x;
        return;
    }

}

bool Is_or_Not(int a,int b)
{
    a=Find(a);
    b=Find(b);
    if(a==b)
        return true;
    else
        return false;
}


int main()
{
    int n,m,p;
    while(cin>>n>>m>>p)
    {
        int Ai,Bi;

        init(n);

        for(int i=0;i<m;i++)
        {
            cin>>Ai>>Bi;
            merge(Ai,Bi);
        }
        int test1,test2;

        for(int i=0;i<p;i++)
        {
            cin>>test1>>test2;
            if(Is_or_Not(test1,test2))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    //cout<<endl;


    return 0;
}
