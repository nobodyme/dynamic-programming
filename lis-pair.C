#include<stdio.h>
#include<stdlib.h>

int max(int a,int b)
{
 return a > b ? a : b;
}

int max_incre(int array[100][2],int n)
{
 int count[5],i,j,maxi = 1;

 for(i=0;i<n;i++)
 count[i] = 1;

/*
resulting array for the input
array : [(5,24)(39,60)(15,28)(27,40)(50,90)]
count : [   1     2      1      2       3  ]
*/

//
 for(i=1;i<n;i++)
  for(j=0;j<n;j++)
  {
   if(array[i][0]>array[j][1])
    count[i] = max(count[i],count[j]+1);
    
   if(count[i] > maxi)
    maxi = count[i];
  }
return maxi;
}

int main()
{
 int i,n,array[][2]={{5,24},{39,60},{15,28},{27,40},{50,90}};
 n = sizeof(array)/sizeof(array[0]); //returns no of elements in the array

 printf("Lis = %d\n",max_incre(array,n));
 return 0;
}
