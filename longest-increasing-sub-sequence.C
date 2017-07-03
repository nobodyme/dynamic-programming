#include<stdio.h>
#include<stdlib.h>

int max(int a,int b);
void max_inc(int array[100],int n);

// return maximum of two numbers
int max(int a,int b)
{
	return a>b ? a : b;
}

void max_inc(int array[100],int n)
{
	int count[100],maxi;
	int i,j;

//set all elements of count to 1
	for(i=0;i<n;i++)
		count[i] = 1;

// increment count of each element if condition satisfies

	for(i=1;i<n;i++)
		for(j=0;j<i;j++)
		{
			if(array[i] > array[j])
				count[i] = max(count[i],count[j]+1);
		}

//finding the maximum no in the count array

	for (i = 0; i < n; i++ )
 		if (maxi < count[i])
		{
  		maxi = count[i];
		}

//print max count

	printf("\nMax-length = %d\n",maxi);

}

int main()
{
	int n,array[] = {10, 12, 32, 22, 23, 25, 30};
	n = sizeof(array)/sizeof(array[0]); // get no of elements in the array
	max_inc(array,n);
	return 0;
}
