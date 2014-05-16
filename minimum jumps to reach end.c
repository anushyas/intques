
Given an array of integers where each element represents the max number of steps that can be made forward from that 
element. Write a function to return the minimum number of jumps to reach the end of the array (starting from the first 
element). If an element is 0, then cannot move through that element.

Example:

Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3 (1-> 3 -> 8 ->9)
#include<stdio.h>
#include<limits.h>
void jumps(int *arr,int *result,int n)
{
	int i,j;
	if(n==0||arr[0]==0)
		return;
	result[0]=0;
	for(i=1;i<n;i++)
	{
		result[i]=INT_MAX;
		for(j=0;j<i;j++)
		{
			if(arr[j]>=i-j){
				if(result[j]+1<result[i])
					result[i]=result[j]+1;
			}		
		}
	}
}
int main(){
int result[10],i,n;
int arr[10];
scanf("%d",&n);
for(i=0;i<n;i++)
{	
	scanf("%d",&arr[i]);
	result[i]=0;
}
jumps(arr,result,n);

	printf("the result array is ");
for(i=0;i<n;i++)
{
	printf("%d ",result[i]);
}
printf("\n jumps=%d",result[n-1]);

return 0;
}
