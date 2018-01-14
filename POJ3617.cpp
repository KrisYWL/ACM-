#include<iostream>

using namespace std;

int a[2001];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<a[3]<<endl;
    return 0;
}
