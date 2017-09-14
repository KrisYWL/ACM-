 #include<iostream>
 #include<stdio.h>
 using namespace std;
 int MaxSubseqSum4(int A[],int N)
 {
    int ThisSum,MaxSum;
    int i;
    ThisSum = MaxSum = 0;
    for(i=0;i<N;i++)
    {
        ThisSum += A[i];
        if(ThisSum>MaxSum)
            MaxSum = ThisSum;
        else if(ThisSum<0)
            ThisSum = 0;
    }
    return MaxSum;
 }
 int main()
 {
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int MaxSum=MaxSubseqSum4(a,sizeof(a)/4);
    cout<<MaxSum<<endl;
    return 0;
 }
