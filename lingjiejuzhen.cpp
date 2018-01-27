#include<iostream>
#include<cstring>
using namespace std;
int s[100][100];
int main()
{
    int n,m;
    memset(s,0,sizeof(s));
    while(cin>>n>>m)
    {
        int a,x,y;
        for(int i=0;i<m;i++)
        {
            cin>>a>>x>>y;
            if(a==0)    //ÓÐÏò±ß
            {
                s[x][y]=1;
            }
            else
            {
                s[x][y]=1;s[y][x]=1;
            }
        }

        for(int i=0;i<n;i++)
        {
               for(int j=0;j<n;j++)
               {
                    if(j!=n-1)
                        cout<<s[i][j]<<' ';
                    else
                        cout<<s[i][j]<<endl;
               }
        }
    }

    return 0;
}
