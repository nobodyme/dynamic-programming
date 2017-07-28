#include<stdio.h>
#include<stdlib.h>

//naive 3 variable comparison
int min(int a,int b, int c)
{
 if(a<b && a<c)
  return a;
 else if(b<a && b<c)
  return b;
 else if(c<a && c<b)
  return c;
}

//function to return min-cost to reach a point

int minpath(int a[100][100], int n, int m)
{
 int minarr[100][100] = {0},i,j,n1,m1;
 
 printf("\nenter the destination :");
 scanf("%d%d",&n1,&m1);

 if((n1 > 0) && (n1 < n) && (m1 > 0) && (m1 < m))
{
//setting up the base cases in the minarray
 minarr[0][0] = a[0][0];

 for(i=1;i<n;i++)
  minarr[0][i] = minarr[0][i-1] + a[0][i];

 for(i=1;i<m;i++)
  minarr[i][0] = minarr[i-1][0] + a[i][0];

//table filling from the base cases

for(i=1;i<n;i++)
 for(j=1;j<m;j++)
  minarr[i][j] = (a[i][j] + min(minarr[i-1][j-1],minarr[i][j-1],minarr[i-1][j]));	


 return minarr[n1][m1];
}
else
{
 printf("Not a valid destination\n");
 exit(1);
}
}


int main()
{
//change input array as per your liking
 int costarray[100][100] = { {1 ,2 ,3}, {4 ,8, 2}, {1 ,5 ,3} };
//change rows and columns in the 2nd and 3rd parameter respectively
 printf("Minimum cost :%d\n",minpath(costarray,3,3));
 return 0;
}
