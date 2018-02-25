#include<iostream>
#include<cstring>
using namespace std;

int f[5001];
int dir[5001];
int K,M;
int N;
int comp(int k);
void solve();

int main()
{
    cin>>N;
    char temp;
    for(int i=0;i<N;i++)
    {
        cin>>temp;
        if(temp=='B')
            dir[i]=1;
        else if(temp=='F')
            dir[i]=0;
    }

    solve();

    return 0;
}

int comp(int K)
{
    memset(f,0,sizeof(f));
    int res=0;
    int sum=0;
    for(int i=0;i+K<=N;i++)
    {
        if((dir[i]+sum)%2!=0)
        {
            res++;
            f[i]=1;
        }
        sum+=f[i];
        if(i-K+1>=0)
        {
            sum-=f[i-K+1];
        }
    }
    for(int i=N-K+1;i<N;i++)
    {
        if((dir[i]+sum)%2!=0)
        {
            return -1;
        }
        if(i-K+1>=0)
        {
            sum-=f[i-K+1];
        }
    }


    return res;
}

void solve()
{
    K=1,M=N;
    for(int k=1;k<=N;k++)
    {
        int m=comp(k);
        if(m>=0&&m<M)
        {
            M=m;
            K=k;
        }
    }
    cout<<K<<' '<<M<<endl;
}
