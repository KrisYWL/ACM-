#include<iostream>
#include<cstring>
#include<time.h>
using namespace std;

clock_t start,stop;
double duration;

void printN(int N)
{
    for(int i=0;i<N;i++)
        cout<<i<<endl;
}
int main()
{
    int N;
    cin>>N;
    start = clock();
    printN(N);
    stop = clock();
    duration = ((double)(stop-start))/CLK_TCK;
    cout<<duration<<endl;

    return 0;
}


