#include<iostream>

using namespace std;

int a1[201];

int solve(int a,int b)
{
    int max=0;

    if(a%2==0)
        a=a/2;
    else
        a=(a+1)/2;

    if(b%2==0)
        b=b/2;
    else
        b=(b+1)/2;

    for(int i=0;i<201;i++)
    {
        if(i>=a&&i<=b)
            a1[i]++;
    }

    for(int i=0;i<201;i++)
    {
        if(a1[i]>max)
            max=a1[i];
    }

    return max;
}



int main()
{
    

    int Twai=0,Tnei=0;

    cin>>Twai;
    for(int p=0;p<Twai;p++)
    {
        int times=0,times_max=0;
        cin>>Tnei;
        int a,b;
        for(int p1=0;p1<Tnei;p1++)
        {
            cin>>a>>b;
            if(a>b)
            {
                int temp=a;
                a=b;
                b=temp;
            }

            times=solve(a,b);

            if(times>times_max)
                times_max=times;
        }
        cout<<times_max*10<<endl;
        for(int i=0;i<201;i++)
        {
            a1[i]=0;
        }
    }

    return 0;
}
