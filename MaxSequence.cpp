#include<stdio.h>
int main()
{ 
	int MaxSubseqSum2(int A[],int N);
	int N,max;
	int A[10];
	scanf("%d",&N);
	scanf("%s",A);
	max=MaxSubseqSum2(int A[],int N);
	printf("%d",max);
	return 0;
}
int MaxSubseqSum2(int A[],int N)
{
	int ThisSum,MaxSum=0;
	int i,j;
	for(i=0;i<N;i++){
	ThisSum=0;
	for(j=0;j<N;j++){
		ThisSum+=A[j];
		if(ThisSum>MaxSum)
		MaxSum=ThisSum;
		}
	}
	return MaxSum;
}

