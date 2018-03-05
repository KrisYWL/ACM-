#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int n;
int A[4001],B[4001],C[4001],D[4001];
int CD[4001*4001];

void solve()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            CD[i*n+j]=C[i]+D[j];
        }
    sort(CD,CD+n*n);

    long long res=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            int cd=-A[i]-B[j];
            res+=upper_bound(CD,CD+n*n,cd)-lower_bound(CD,CD+n*n,cd);
        }
    printf("%lld\n",res);
}

int main()
{
    cin>>n;

    for(int j=0;j<n;j++)
        cin>>A[j]>>B[j]>>C[j]>>D[j];

    solve();



    return 0;
}
