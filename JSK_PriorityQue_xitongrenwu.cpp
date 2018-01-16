/*
    蒜头君设计了一个任务系统。这个系统是为了定时提醒蒜头君去完成一些事情。

系统大致如下，初始的时候，蒜头君可能会注册很多任务，每一个任务的注册如下:

Register Q_num Period

表示从系统启动开始，每过 PeriodPeriod 秒提醒蒜头君完成编号为 Q_{num}Q
num
​	  的任务。

你能计算出蒜头君最先被提醒的 kk 个任务吗？

输入格式

第一行输入 n(0 < n \le 3000)n(0<n≤3000)，k(0 < k \le 10000)k(0<k≤10000)，其中 nn 表示蒜头君注册的任务数量。

接下来 nn 行，每行输入一条注册命令，其中 0 < q_{num} \le 30000<q
num
​	 ≤3000，0 \le Period \le 30000≤Period≤3000。

输出格式

顺序输出 kk 行，表示依次提醒的任务的编号。如果同一时间有多个任务，最先提醒编号小的任务。

样例输入

2 5
Register 2004 200
Register 2005 300
样例输出

2004
2005
2004
2004
2005
*/

#include<iostream>
#include<queue>
using namespace std;

int Their_time[3001];

struct node
{
    int Q,time;
    node(){};
    bool operator <(const node a)const
    {
        if(a.time!=time)
            return time>a.time;
        else
            return Q>a.Q;
    }
};

int main()
{
    string R;
    int qnum,Period;
    node x;
    priority_queue<node> s;
    priority_queue<node> s2;

    while(cin>>qnum>>Period)
    {
        for(int i=0;i<qnum;i++)
        {
            cin>>R>>x.Q>>x.time;
            s.push(x);
            Their_time[x.Q]=x.time;
        }


//        for(int i=0;i<qnum;i++)
//        {
//            for(int j=1;j<=Period;j++)
//            {
//                node a;
//                a.time=s.top().time*j;
//                a.Q=s.top().Q;
//                s2.push(a);
//            }
//            s.pop();
//        }



//        for(int i=0;i<Period;i++)
//        {
//            cout<<s2.top().Q<<endl;
//            s2.pop();

        for(int i=0;i<Period;i++)
        {
            cout<<s.top().Q<<endl;
            x.Q=s.top().Q;
            x.time=s.top().time+Their_time[x.Q];
            s.pop();

            s.push(x);
        }

        }


    return 0;
}
