/*
Program to find all possible paths to reach to bottom-right cell starting from the top-left
Can move only right,down or diagonally lower

Enter the no of rows: 2
Enter the no of columns: 2
Total paths: 3
   
   j
   ___
i |1 1
  |1 3
  
  sum of all three sides, gives total path.
*/


#include<stdio.h>

int main()
{
int a[100][100],i,j,r,c;

printf("Enter the no of rows: ");
scanf("%d",&r);
printf("Enter the no of columns: ");
scanf("%d",&c);

a[0][0] = 1;

for(i=0;i<r;i++)
	for(j=0;j<c;j++)
	{
	if(i==0 || j==0)
		a[i][j] = 1;
	else
		a[i][j] = a[i-1][j] + a[i-1][j-1] + a[i][j-1];
	}

	printf("Total paths: %d ",a[r-1][c-1]);
		
return 0;
}
