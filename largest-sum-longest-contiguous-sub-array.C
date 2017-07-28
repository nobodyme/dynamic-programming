/*Program to find the largest-sum-longest-contiguous-sub-array

Input: 	3,1,-5,-8,0,2,2
Output: Sum: 4
        Sub-array: 0,2,2

Although [3,1] gives sum as 4 which is same as [0,2,2] the latter is the longest*/

#include<stdio.h>

int main()
{
int a[] = {3,1,-5,-8,0,2,2};
int i,sum,start,end,n,max_value,start_max,end_max;

n = sizeof(a)/sizeof(a[0]);

//max sums of all 
max_value = sum = a[0];
//start-point and end-point of max array
start_max = 0;
end_max = -1;
//start and end check
start = end = 0;

for(i=1;i<n;i++)
{

//check if adding a number to the existing array increases the sum if not make it the start of the new sub-array
if(sum + a[i] < a[i])
{
	sum = a[i];
	start = end = i;
}

//increment end as we add new elements to the sub-array
else
{
  sum = sum + a[i];
  end++;
}
  
//update max sum if its lesser than currently calculated one and hence set current start and end to the start_max and end_max
if(max_value < sum)
{
  max_value = sum;
 	start_max = start;
	end_max = end;
}

//if max_value is equal to current sum, check if current one is longest if so make this one the new sub-array
if(max_value == sum)
 if(end - start > end_max - start_max)
	{
		start_max = start;
		end_max = end;
	}

}

//print sum and sub-array
printf("Sum: %d\nSub-array: ",max_value);

for(i=start_max;i<=end_max;i++)
printf("%d ",a[i]);

return 0;
}
