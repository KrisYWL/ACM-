#include<iostream>
using namespace std;

int mat[1000][1000];

void DFS(int x,int y,int n)
{
    mat[x][y]=mat[y][x]=100;
    for(int i=1;i<=n;i++)
    {
        if(mat[y][i]==1)
            DFS(y,i,n);

    }
    for(int i=1;i<=n;i++)
    {
        if(mat[x][i]==1)
            DFS(x,i,n);
    }

    return;
}



int main()
{
    int n,m;

    while(cin>>n>>m)
    {
        int ans=0;

        int x,y;
        for(int i=0;i<m;i++)
        {
            cin>>x>>y;
            mat[x][y]=mat[y][x]=1;      //注意编号从1开始，没有0.
        }

//        for(int i=0;i<=n;i++)
//        {
//            for(int j=0;j<=n;j++)
//            {
//                if(j!=n)
//                    cout<<mat[i][j]<<' ';
//                else
//                    cout<<mat[i][j]<<endl;
//            }
//        }
//        cout<<endl;

               //开始DFS
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(mat[i][j]==1)
                {
                    DFS(i,j,n);
                    ans++;


//                    for(int i=0;i<=n;i++)
//        {
//            for(int j=0;j<=n;j++)
//            {
//                if(j!=n)
//                    cout<<mat[i][j]<<' ';
//                else
//                    cout<<mat[i][j]<<endl;
//            }
//        }
//
//                cout<<endl;

                }
            }
        }
        cout<<ans-1<<endl;

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                mat[i][j]=0;
            }
        }



    }



    return 0;
}

/*
835 77
487 144
68 832
441 649
388 58
735 819
126 793
1 687
220 383
39 702
758 835
726 373
569 698
103 138
395 444
340 770
494 767
227 484
497 753
16 646
711 760
305 357
234 269
479 189
576 532
27 424
544 102
77 296
233 473
292 181
400 36
555 154
233 350
11 738
519 483
403 727
257 786
599 737
318 31
530 757
294 594
713 237
622 221
437 55
438 751
304 511
820 725
186 656
780 819
212 156
312 3
478 664
195 21
321 78
246 590
174 658
521 4
811 345
813 13
421 432
118 127
811 439
200 156
129 96
413 239
279 15
41 691
114 137
709 196
530 246
670 475
31 831
359 681
697 805
70 215
373 468
354 271
625 688
241 1
676 352
*/
