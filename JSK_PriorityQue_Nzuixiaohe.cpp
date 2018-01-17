/*
5
8 9 1 2 6
6 6 2 7 3

用例正确输出：
3 4 4 5 7

你的输出：
7 7 3 8 8
*/
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct node
{
    int sum,hang,lie;
    node(){};
    bool operator <(const node a)const
    {
        return sum>a.sum;
    }
};

int A[50001];
int B[50001];

int main()
{
    int n;
    priority_queue<node> s;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    for(int j=0;j<n;j++)
    {
        cin>>B[j];
    }
    sort(A,A+n);
    sort(B,B+n);
    for(int i=0;i<n;i++)
    {
        node s_temp;
        s_temp.sum=A[i]+B[0];
        s_temp.hang=i;
        s_temp.lie=0;
        s.push(s_temp);
    }
    for(int i=0;i<n;i++)
    {
        if(i!=n-1)
            cout<<s.top().sum<<' ';
        else
            cout<<s.top().sum;
        node p;

        p.hang=s.top().hang;
        p.lie=s.top().lie+1;
        p.sum=A[p.hang]+B[p.lie];
        s.pop();
        s.push(p);
    }
    return 0;
}
