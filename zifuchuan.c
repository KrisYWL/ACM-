#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int n;
    //string a;
    string b;
    //cin>>a;
    char a[5000];
    gets(a);
    cin>>b;
    int ans=0;
    
    for(int i=0;i<strlen(a)-b.size()+1;i++)
    {
        int flag=0;
        for(int j=i;j<i+b.size();j++)
        {
            if(a[j]!=b[j-i])
            {                
                flag=1;
                break;
            }
        }
        if (flag==0)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}