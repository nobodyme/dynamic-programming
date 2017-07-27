
//author     : Naveen
//github-link: https://github.com/nobodyme
//This is a part of the article focusing on introduction to dp, hence please avoid the vage declaration of array-sizes and optimizations to it

/*Program to find the largest-sum-longest-contiguous-sub-array

Input: 	3,1,-5,-8,0,2,2
Output: Sum: 4
				Array: 0,2,2

Although [3,1] gives sum as 4 which is same as [0,2,2] the latter is the longest*/

#include<stdio.h>

int main()
{
int a[] = {-1,3,1,-5,-8,0,1,1,1,1};
int i,sum,start,end,n,max_value;

n = sizeof(a)/sizeof(a[0]);

//intializing max sum as first element initally
max_value = sum = a[0];
start = 0;
end = 0;

for(i=1;i<n;i++)
{
//check if choosing next element makes sum greater than adding it to the existing array
if(sum + a[i] < a[i])
{
//then this marks "start" of the longest-sub-array, notice this is first initialized 0 above
	start = i;
	sum = a[i];
}

//else simply add the element to the array
else
	sum = sum + a[i];

//if existing max-value is lesser than the current sum, assign the new value to sum and mark the end of the sub-array
if(max_value < sum)
{
	max_value = sum;
	end = i;
}

//if sum is equal to previous one, check if length is greater than previous one, if so mark this one as end
if(max_value == sum)
{
	if(start - i < start - end)
	{
		end = i;		
	}
}

}

printf("%d\n",max_value);

//print the sub-array
for(i=start;i<=end;i++)
printf("%d ",a[i]);

return 0;
}
