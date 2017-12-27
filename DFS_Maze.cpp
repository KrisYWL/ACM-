
#include<iostream>
#include<queue>
using namespace std;

const int INF = 100000000;

typedef pair<int,int> P;

char maze[100][100];
int N,M;
int sx,sy;  //start point
int gx,gy;  //end point
int d[100][100];//distance between current point to start point
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};

int bfs();
int solve();

int bfs()
{
    int sum;
    queue<P> que;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            d[i][j] = INF;
        }
    que.push(P(sx,sy));
    d[sx][sy] = 0;
    while(que.size())
    {
        P q = que.front(); que.pop();
        if(q.first==gx && q.second==gy)
        {
            sum = d[gx][gy];
            break;
        }

        for(int i=0;i<4;i++)
        {
            int nx = q.first + dx[i];
            int ny = q.second + dy[i];
            if(nx>=0 && nx<=N && ny>=0 && ny<=M && maze[nx][ny]!='#' && d[nx][ny] == INF)
            {
                que.push(P(nx,ny));
                d[nx][ny] = d[q.first][q.second] + 1;
            }
        }
    }

    return sum;
}

int solve()
{
    int sum = bfs();

    cout<<sum<<endl;
    return 0;
}

int main()
{

    cout<<"N=";
    cin>>N;
    cout<<"M=";
    cin>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            cin>>maze[i][j];

            if(maze[i][j]=='S')
            {
                sx = i; sy = j;
            }
            if(maze[i][j]=='G')
            {
                gx = i; gy = j;
            }
        }

    solve();

    return 0;
}












