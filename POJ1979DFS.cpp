#include<iostream>

using namespace std;

char a[25][25];
int x_for[4]={1,0,-1,0};
int y_for[4]={0,-1,0,1};
int W,H;
int num=1;

void solve(int x,int y)
{
    for(int i=0;i<=3;i++)
        if(x+x_for[i]>=0&&x+x_for[i]<H&&y+y_for[i]>=0
           &&y+y_for[i]<W&&a[x+x_for[i]][y+y_for[i]]=='.')
            {
                a[x+x_for[i]][y+y_for[i]]='x';
                num++;
                solve(x+x_for[i],y+y_for[i]);

            }
    return ;
}


int main()
{

    while(cin>>W>>H)
    {
        if(W==0&&H==0)
            break;

        for(int i=0;i<H;i++)
            for(int j=0;j<W;j++)
                cin>>a[i][j];



        for(int i=0;i<H;i++)
            for(int j=0;j<W;j++)
            {
                if(a[i][j]=='@')
                {
                    solve(i,j);
                    break;
                }
            }
        cout<<num<<endl;
        num=1;

//        for(int i=0;i<H;i++)
//            for(int j=0;j<W;j++)
//            {
//                cout<<a[i][j];
//                if(j==W-1)
//                    cout<<endl;
//            }
    }

    return 0;
}
