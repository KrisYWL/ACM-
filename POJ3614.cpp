//#include<iostream>
//#include<map>
//#include<string>
//using namespace std;
//
//int cows[5001];
//int lotion[5001];
//int C,L;
//
//
//void solve()
//{
//
//    int cows_number=65533;
//    int lotion_number=65533;
//    int ans=0;
//    int times=0;
//
//    while(1)
//    {
//        int max_lotion=0,max_SPF=0;
//
//        for(int i=0;i<2*L;i=i+2)//取SPF数值最大的
//        {
//            if(lotion[i]>max_lotion&&lotion[i+1]!=0)
//            {
//                max_lotion=lotion[i];
//                lotion_number=i;
//            }
//        }
//
//        for(int i=0;i<2*C;i=i+2)
//        {
//            if(cows[i+1]>max_SPF)
//                {
//                    cows_number=i;
//                    max_SPF=cows[i+1];
//          //          cout<<max_SPF<<endl;
//                }
//        }
//        //cout<<max_lotion<<' '<<max_SPF<<endl;
//        //cout<<cows_number<<endl;
//
//        if(max_lotion>cows[cows_number+1]||max_lotion<cows[cows_number])
//            lotion[lotion_number+1]--;
//
//        if(max_lotion<cows[cows_number+1]&&max_lotion>cows[cows_number]
//        &&lotion[lotion_number+1]>=0)
//            {
//                cows[cows_number]=0;
//                cows[cows_number+1]=0;
//                ans++;
//                lotion[lotion_number+1]--;
//                times=0;
//                //cout<<'x'<<endl;
//            }
//        times+=2;
//        if(times>2*C)   //出口
//            break;
//    }
//    cout<<ans<<endl;
//    return ;
//}
//
//int main()
//{
//
//    while(cin>>C>>L)
//    {
//        for(int i=0;i<2*C;i=i+2)
//        {
//            cin>>cows[i]>>cows[i+1];
//        }
//        for(int i=0;i<2*L;i=i+2)
//        {
//            cin>>lotion[i]>>lotion[i+1];
//        }
//
//        solve();
//    }
//
//    return 0;
//}


#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
const int CMax=2510,NMax=2*CMax;
int nn,C,L,PL,Min[CMax],Max[CMax],P[CMax],NUM[CMax];
struct edge {
    int num,len;
    edge *next,*rev;
}*A[NMax],pool[2*CMax*CMax];
void Build(int x,int y,int z) {
    edge *p=&pool[PL++],*q=&pool[PL++];
    p->num=y;p->len=z;p->next=A[x];A[x]=p;p->rev=q;
    q->num=x;q->len=0;q->next=A[y];A[y]=q;q->rev=p;
}
int level[NMax],q[NMax];
bool makelevel() {
    memset(level,-1,sizeof(level));
    q[0]=0;level[0]=0;
    for(int i=0,bot=1;i<bot;i++) {
        int x=q[i];
        for(edge *p=A[x];p;p=p->next) if(p->len&&level[p->num]==-1){
            level[q[bot++]=p->num]=level[x]+1;
        }
    }
    return level[nn]!=-1;
}
int Find(int a,int alpha) {
    if(a==nn) return alpha;
    int tot=0,tmp;
    for(edge *p=A[a];p&&tot<alpha;p=p->next) {
        if(p->len&&level[p->num]==level[a]+1)
            if(tmp=Find(p->num,min(p->len,alpha-tot))) {
                tot+=tmp;
                p->len-=tmp;
                p->rev->len+=tmp;
            }
    }
    if(!tot) level[a]=-1;
    return tot;
}
int main()
{
    scanf("%d%d",&C,&L);
    nn=C+L+1;
    for(int i=1;i<=C;i++) {
        scanf("%d%d",Min+i,Max+i);
        if(Min[i]>Max[i]) swap(Min[i],Max[i]);
    }
    for(int i=1;i<=L;i++) scanf("%d%d",P+i,NUM+i);
    for(int i=1;i<=L;i++) {
        Build(0,i,NUM[i]);
        for(int j=1;j<=C;j++)
            if(Min[j]<=P[i]&&P[i]<=Max[j]) Build(i,L+j,1);
    }
    for(int i=1;i<=C;i++) Build(L+i,nn,1);
    int tmp,ret=0;
    while(makelevel())
        while(tmp=Find(0,100000000)) ret+=tmp;
    printf("%d\n",ret);
    getchar();getchar();
}
