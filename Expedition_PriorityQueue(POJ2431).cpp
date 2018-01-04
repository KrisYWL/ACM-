#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

const int ms=10010;
struct node
{
	int a,b;
}A[ms];


//int solve(int L,int N,int P);
bool cmp(const node &a1,const node &a2)
{
	return a1.a<a2.a;
}
int solve(int L,int N,int P)
{
    int pos = 0,tank = P;
    int d,ans=0;
    priority_queue<int> que;

    A[N].a=L;
    A[N].b=0;
    N++;
    sort(A,A+N,cmp);
//    for(int i=0;i<N;i++)
//        cout<<A[i].b<<' ';
    for(int i=0;i<=N;i++)
    {
        int d = A[i].a-pos;

        while(tank < d)
        {
            if(que.empty())
            {
                cout<<"-1"<<endl;
                return 0;
            }
            //cout<<que.top()<<endl;
            tank+=que.top();
            que.pop();//pop
            ans++;
            //cout<<"j"<<d<<' '<<tank-d<<endl;
        }
        que.push(A[i].b);
        pos = A[i].a;
        tank-=d;


        //cout<<"j"<<endl;
        //push
    }
    cout<<ans<<endl;
    //cout<<B[N]<<endl;


    return 0;
}


int main()
{
    int N,L,P;
    cin>>N;
    //for(int i=0;i<N)
    for(int i=0;i<N;i++)
        cin>>A[i].a>>A[i].b;
    cin>>L>>P;

//    for(int i=0;i<N;i++)
//        cout<<A[i];

//    for(int i=0;i<N;i++)
//        cin>>A[i];
//    for(int i=0;i<N;i++)
//        cin>>B[i];

    for(int i=0;i<N;i++)
        A[i].a=L-A[i].a;

    solve(L,N,P);

    return 0;
}
