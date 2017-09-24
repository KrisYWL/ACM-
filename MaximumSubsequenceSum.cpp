 #include<iostream>
 using namespace std;

 int s=0;
 int j=0;
 int flag=0;
 int b[1000];
 int sb1=0;
 int sb2=0;
 int times=0;
 int MaxSubseqSum4(int A[],int N)
 {
    int ThisSum,MaxSum;
    int i;
    ThisSum = MaxSum = 0;
    int s=0;
    int j=1;
    flag=0;
    for(i=0;i<N;i++)
    {

        ThisSum += A[i];
        if(ThisSum>MaxSum)
        {
            MaxSum=ThisSum;
            sb1=2*flag;
            b[sb1]=s;
            sb2=2*flag+1;
            b[sb2]=s+j-1;
            flag++;
        }
        else if(ThisSum<=0)
        {
            ThisSum = 0;
            s=i+1;
            j=0;
            times++;
        }
        j++;
    }
    if(times==N)
        return 0;
    else
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
    if(times==n)
        cout<<MaxSum<<' '<<a[0]<<' '<<a[n-1]<<endl;
    else
        cout<<MaxSum<<' '<<a[b[sb1]]<<' '<<a[b[sb2]]<<endl;

    return 0;
 }
