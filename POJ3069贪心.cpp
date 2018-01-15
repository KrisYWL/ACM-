//理解错误，1000是个数不是大小。


//#include<iostream>
//
//using namespace std;
//
//int a[1001];
//
//int main()
//{
//    int R,n,loc;
//
//    while(cin>>R>>n)
//    {
//        if(R==-1&&n==-1)
//            break;
//
//
//        int num=0,flag=0;
//        int loc_max=0;
//        for(int i=0;i<n;i++)
//        {
//            cin>>loc;
//            if(loc_max<loc)
//                loc_max=loc;
//            a[loc]=1;
//        }
//
//        for(int i=0;i<=loc_max;i++)
//        {
//            if(a[i]==1)
//            {
//                for(int j=i-R;j<=i+R;j++)
//                {
//                    if(j-R>=0&&j-R<=loc_max&&a[j]==2)
//                    {
//                        flag=1;
//                        //cout<<"jj"<<endl;
//                        break;
//                    }
//                }
//                if(flag==0) //加标志点
//                    for(int j=i+R;j>=i;j--)
//                    {
//                        if(a[j]==1)
//                        {
//                            a[j]=2;
//                            num++;
//                            break;
//                        }
//                    }
//            flag=0;
//            }
//        }
//
//        cout<<num<<endl;
//        for(int i=0;i<=loc_max;i++)
//        {
//            if(a[i]==1||a[i]==2)
//            {
//                a[i]=0;
//            }
//        }
//    }
//    return 0;
//}
#include"iostream"
#include"cstdio"
#include"cstring"
#include"algorithm"
using namespace std;
const int ms=1001;
int a[ms];
int r,n;
void solve()
{
	int i=0,ans=0,l;
	sort(a,a+n);
	l=a[0];
	while(i<n)
	{
		while(i<n&&l+r>=a[i])
			i++;
		l=a[i-1];
		while(i<n&&l+r>=a[i])
			i++;
		l=a[i];
		ans++;
	}
	printf("%d\n",ans);
	return ;
}
int main()
{
	while(scanf("%d%d",&r,&n)==2)
	{
		if(r==-1&&n==-1)
			break;
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		solve();
	}
	return 0;
}
