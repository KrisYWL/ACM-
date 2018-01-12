#include<iostream>

using namespace std;

int main()
{
    int a;
    double x,y;
    cin>>a;
    //int num=1;
    for(int i=0;i<a;i++)
    {
        cin>>x>>y;

        //int i=1;
        double area=0;
        int num=1;
        while(1)
        {
            //cout<<"df"<<endl;
            area+=50;
            if(1.570795*(x*x+y*y)<area)
            {

                cout<<"Property "<<i+1<<": This property will begin eroding in year "
                <<num<<'.'<<endl;

                break;
            }
            num++;
        }

    }
    cout<<"END OF OUTPUT."<<endl;

    return 0;
}
