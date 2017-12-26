//coin problem

#include<stdio.h>

int Value[100] = {1,5,10,50,100,500};

int num[100];
int min(int x,int y);
int resolve(int A,int n);

int main()
{
    int Coin_num,A,n;
    int i=0;
    scanf("%d",&n);
    while(scanf("%d",&A)!=EOF)
    {
        num[i]=A;
        i++;
        if(i==n) break;

    }

    scanf("%d",&A);

    Coin_num = resolve(A,n);
    printf("%d",Coin_num);

    return 0;
}

int min(int x,int y)
{
    if(x>=y)
        return y;
    else
        return x;
}

int resolve(int A,int n)
{
    int t,number=0;
        for(int i=n-1;i>=0;i--)
        {
            t=min(A/Value[i],num[i]);
            A=A-t*Value[i];
            number+=t;
        }

    return number;
}
