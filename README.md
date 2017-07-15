# Dynamic Programming

There were huge number of sources on the internet on this topic but still we (me and my friend) couldn't understand any of it for a very long time until we fiddled with code and tracked the output for every change in the input. So this repository is exactly created for people like us to make the transition from [greedy](https://en.wikipedia.org/wiki/Greedy_algorithm) to dynamic programming easier. This will just be an introduction to dynamic programming, so that one can pick it up from there. I have added additional sources for practice and other online tutorials that I found a little helpful at the end and will continue to do so as I find something new. It is for programmers who are comfortable with brute-force and might not the serve the purpose for absolute beginners.

### Definition 

So what's dynamic programming? Let's first look at a more formal definition.

Dynamic programming (also known as dynamic optimization) is a method for solving a complex problem by breaking it down into a collection of simpler subproblems, solving each of those subproblems just once, and storing their solutions. The next time the same subproblem occurs, instead of recomputing its solution, one simply looks up the previously computed solution, thereby saving computation time at the expense of a (hopefully) modest expenditure in storage space. (Each of the subproblem solutions is indexed in some way, typically based on the values of its input parameters, so as to facilitate its lookup).[(Source-Wiki)](https://en.wikipedia.org/wiki/Dynamic_programming).

Or more simply, it is technique to save intermediate results in a calculation in any comfortable format so that the result can be used for further computation instead of calculating it all over again at the arrival of an additional input. Sounds simple enough? Yes, indeed it is, let's have a look at an example to put it right through our skull.

Before that, we need to identify whether a problem has the following properties, inorder to be solved by Dynamic Programming(DP)
  
  - [Overlapping Sub-problem](http://www.geeksforgeeks.org/dynamic-programming-set-1/)
  - [Optimal Substructure](http://www.geeksforgeeks.org/dynamic-programming-set-2-optimal-substructure-property/)
  
### Problems:

  - [Longest increasing subsequence](#problem-1)
  - [Minimum cost problem](#problem-2)

### Longest increasing subsequence <a name="problem-1"></a>
The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order. 
For example, the length of LIS for {10, 12, 32, 2, 22, 23, 25, 30} is 6 and LIS is {10, 12, 22, 23, 25, 30}

**Solution:**

This will be elaborate step by step explanation about attaining the solution, since this is the first sum.

So how would you go on solving that?
Oh, the properties I read talked about saving the sub-problems to make the computations easier!
What are the sub-problems here?

Oh, it's too tough.

No, it's not we will work together.

So, how would go on solving that using **brute force** just like how you would perform a [selection sort](https://en.wikipedia.org/wiki/Selection_sort)!


| 10  | 12  | 32  |  2  | 22  | 23  | 25 | 30 |
|---  |---  |---  | --- | --- |---  |--- |--- |
| k,i |  j  |     |     |     |     |    |    |


You would compare every element with every other element, if it's greater than the current one, you would increase count variable and print the highest one, right? Let us look at the result after such an implementation in the above array.

***pseudo code*** (Skip this code if you don't follow) </br> 

    for(i=0;i<n-1;i++)
    {   
		 count = 1;
		 for(j=i+1,k=i;j<n,k<n-1;j++)
		 {
			 if(a[j] > a[k])
			 {
				 k=j;
				 count++;
			 }
			 if(count>maxi)
				maxi = count;
		 }
    }
    printf("\nMax-length = %d\n",maxi);
  

So such an implementation returns, `max-length = 5`, which is {2, 22, 23, 24, 25}. We know it's 6 and LIS is {10, 12, 22, 23, 25, 30}. Why does it fail to catch the above lis? because while traversing {10, 12, 32, 22, 23, 25, 30}, the code will run as follows,it will check,</br>
if(10>12) yes--> count is 2, then</br>
if(32>12) yes--> count is 3, then</br>
At this point **count = 3**, from there on count won't get incremented because the following elements are lesser than 32 and hence condition like (22>32) will consecutively fail. If only it knew that by **avoiding 32** and traversing through the rest of the array we would actually obtain the result which is `max-length = 6`. This is exactly the information we store for our computation using DP. In brute force terms, we store the count variable for all possible alternatives of traversal in the array and then simply find the maximum of it.(Not that brute force cannot solve the problem, a different approach might but definitely in exponential time)

 And we set `count=1` and not 0 initially, because when we have a case where all numbers are same in the array i.e {2, 2, 2, 2}, we must return count as **1** since one element is the still a subarray of the larger one which is simply { 2 } therefore returning 0 would be wrong.
 
**Dp solution:**

So how would you code the same in dp, well actually it's easier.</br>
We first start off by creating another array for storing the count for each member of the array and as we discussed earlier we initialize it to `1`

| array | 10  | 12  | 32  |  2  | 22  | 23  | 25 | 30 |
|---    |---  |---  |---  | --- | --- |---  |--- |--- |
|count  |  1  |  1  |  1  |  1  |  1  | 1   | 1  | 1  |
|       |  j  |  i  |     |     |     |     |    |    |

Now we check in a similar way,

For, now lets us consider only the elements **10** and **12** exist in the array.

| array | 10  | 12  |
|---    |---  |---  |
|count  |  1  |  1  |
|       |  j  |  i  |

</br>**if(12>10)** --> increment corresponding count of 12 ie `count[i] = count[j] + 1;`

Why is it, `count[j]+1`?
Because the count[j] stores the max count of sequence when 10 is traversed, now since we find another element 12 greater than 10 and we chose to traverse through 10 we add it's length to 12's count + 1 (i.e 12 itself).The result is the Longest increasing subsequence (i.e. 2) when 10, 12 alone are the elements in the array.

Now let us consider 32, increment `i to 32 and j to 10` ie j to the starting element of the array and traverse from the beginning to see **adding 32** provides a longer subsequence.
</br>The array becomes,


| array | 10  | 12  | 32  |
|---    |---  |---  |---  |
|count  |  1  |  2  |  1  |
|       |  j  |     |  i  |

</br>Now since **if(32>10)** yes --> therefore repeat the step of incrementing 32's count --> count[i] = count[j]+1; Check to see if other elements in the array prove useful too, therefore increment j till all elements before the 32 are traversed,

![animated](https://user-images.githubusercontent.com/22789194/27852855-3ce86814-6150-11e7-9a31-bcb108e1308d.gif)

</br>**if(32>12)** --> 32's count = 12's count + 1 = (2+1) = 3

| array | 10  | 12  | 32  |
|---    |---  |---  |---  |
|count  |  1  |  2  |  3  |
|       |     |  j  |  i  |

</br>Similarly, **considering element 2** the array becomes,

| array | 10  | 12  | 32  | 2 |
|---    |---  |---  |---  |---|
|count  |  1  |  2  |  3  | 1 |
|       |  j  |     |     | i |

</br>The array stays the same since each case checking **if(2>10)** , **if(2>12)** or **if(2>32)** fails, and it's count variable remains unchanged.

</br> Now let's add the next number, **22** and check for 10, 12, 32, similar to the previous one, for 10 and 12, count of 22 is incremented to 3 and with 32 it fails and remains as 3, and j is incremented to point 2.

| array | 10  | 12  | 32  | 2 | 22 |
|---    |---  |---  |---  |---| -- |
|count  |  1  |  2  |  3  | 1 | 3  |
|       |     |     |     | j | i  |

</br>Now **if(22 > 2)** --> count of 22 becomes `count[j]+1` i.e. 2? 
</br>No, we know that count reflects the longest subsequence, by traversing other elements in the array we obtained 3 as longest subsequence for 22. So why lower it to 2? Hence while adding `count[i] = count[j]+1` make sure it benefits the cause. Therefore place `count[i] = max(count[j]+1,count[i])` ie with the maximum of two numbers to avoid such cases.



And similarly the rest of the array is traversed and the array becomes,

| array | 10  | 12  | 32  |  2  | 22  | 23  | 25 | 30 |
|---    |---  |---  |---  | --- | --- |---  |--- |--- |
|count  |  1  |  2  |  3  |  1  |  3  | 4   | 5  | 6  |
|       |     |     |     |     |     |     | j  | i  |

Since the highest is 6, that gives the longest increasing subsequence, the video of the above traversal is [linked here(different example)](https://youtu.be/Ns4LCeeOFS4). Let's have a look at the code snippet of the same below.
As we have learnt, 
   - We intialize count array to 1
   - Then calculate count for every element

    for(i=0;i<n;i++)
    count[i] = 1;

    for(i=1;i<n;i++)
    {
     for(j=0;j<i;j++)
     {
     if(array[i] > array[j])
      count[i] = max(count[i],count[j]+1);
     }
    }

After that we find the maximum of the count array and print it, [full code snippet is here](https://github.com/nobodyme/Dynamic-Programming/blob/master/longest-increasing-sub-sequence.C).

Hence by considering the elements one by one we have built up our solution or in DP terms we have acquired our solution in bottom up fashion(tabulation method) from the sub-problems. There's another approach to it called memoizatation. The difference between both is explained in the [article over here](http://www.geeksforgeeks.org/tabulation-vs-memoizatation/).

### Minimum cost problem <a name="problem-2"></a>

Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function that returns cost of minimum cost path to reach (m, n) from (0, 0). Each cell of the matrix represents a cost to traverse through that cell. Total cost of a path to reach (m, n) is sum of all the costs on that path (including both source and destination). You can only traverse down, right and diagonally lower cells from a given cell, i.e., from a given cell (i, j), cells (i+1, j), (i, j+1) and (i+1, j+1) can be traversed. You may assume that all costs are positive integers.

| 1 | 2 | 3 |
|---|---|---|
| 4 | 8 | 2 |
| 1 | 5 | 3 |

(forgive the highlighting of the first row it is of no special significance)

**Solution:**

So again, what would you think is the approriate value to store to make the problem easier with dp?. Nothing comes to mind? It's alright.</br>
How would you normally solve it, forgetting about code for a minute.</br>
You probably eye all the cells of the numbers adding the cost along the path till you reach the destination. But you don't know if it's minimum so you start adding by traversing in a different direction. Then maybe after considering all paths you come up with a cost that's give you the least and maybe you needed a pen and paper along the way.</br>

That's pretty much it.</br>

My friend interrupts,</br>
**Friend:** But the above method only solves the problem for one particular destination, what if we want to calculate the total cost for reaching a different destination.</br>
**Me:** Good point!</br>
**Friend:** That's why we store the minimum cost for reaching each cell in the array from the first cell. That way when we fill up all cells we will be left with solutions of every cell.</br>
**Friend:** I lost you there.</br>
**Me:** Haha, let me finish.

So what do we know so far?</br>
There's an array and we can move right, down and digonally lower.</br>
We need to print the minimum cost of traversing to the given destination.</br>
And we start at the first cell.</br>

**Breaking down the problem:**

**Me:** What is simply the cost of moving from [0,0] to [0,1]?</br>
**Friend:** It's `2 + 1 = 3`</br>
**Me:** What is the minimum cost of moving from [0,0] to [0,1]?</br>
**Friend:** Still 3, because there's no other way we could reach [0,1] since we can only move right or down or diagonally lower. We can **only** reach [0,1] from [0,0].</br>
**Me:** Excellent! So what is the minimum cost of moving from [0,1] to [0,2]?</br>
**Friend:** Oh wait, the cost of moving from **[0,0] to [0,1]** is **3**, hence **[0,1] to [0,2]** would be  `3 + cost of getting to (0,1)` which is `3 + 3 = 6`. </br>
**Me:** Now shall we store this obtained cost corresponding to each cell, so that we can return them, when the cell is the destination?</br>
**Friend:** Fair enough.


<table>
<tr><th>Table A </th> <th>Min cost</th></tr>
<tr><td>

| 1 | 2 | 3 |
|---|---|---|
| 4 | 8 | 2 |
| 1 | 5 | 3 |

</td><td>

| 1 | 3 | 6 |
|---|---|---|
| - | - | - |
| - | - | - |

</td></tr> </table>

Why not code it up too?

    minarr[0][0] = a[0][0];

    for(i=1;i<n;i++)
    minarr[0][i] = minarr[0][i-1] + a[0][i];

where n is the number of rows
    
We transfer the first element as it is to the min cost table and calculate the cost of others in the row.</br>
**Friend:** Why not the columns? The cells in the first column have only one way of reaching them too, which is down from the first cell.</br>
**Me:** Yeah absolutely, that's our next step.

Similarly, we calculate the cost of reaching each column by adding the cell with the previous ones in the column.

<table>
<tr><th>Table A </th> <th>Min cost</th></tr>
<tr><td>

| 1 | 2 | 3 |
|---|---|---|
| 4 | 8 | 2 |
| 1 | 5 | 3 |

</td><td>

| 1 | 3 | 6 |
|---|---|---|
| 5 | - | - |
| 6 | - | - |

</td></tr> </table>

We'll code that up too!

    for(i=1;i<m;i++)
    minarr[i][0] = minarr[i-1][0] + a[i][0];

where m is the number of columns


**Friend:** Now, how do we calculate the minimum cost to reach cell [1,1]?</br>
**Me:** We know we can only traverse left, down or diagonally lower cell. Hence we can reach cell [1,1] only from cell [0,0] or [0,1] or [1,0]. So now that our table already has the minimum values to reach [0,0], [0,1] and [1,0], simply the minimum of those three values plus the cost of reaching cell [1,1] gives us our result.</br>

So the `cost to reach cell [1,1] = a[1,1] + min(minarr[0,0], minarr[0,1], minarr[1,0])`</br>
`minarr[1,1] = 8 + min(1,3,5)`</br>
So, `minarr[1,1] = 9`</br>

Similarly we do for all cells, starting from 1,1.

Let's code it up again,

    for(i=1;i<n;i++)
     for(j=1;j<m;j++)
      minarr[i][j] = (a[i][j] + min(minarr[i-1][j-1],minarr[i][j-1],minarr[i-1][j])); 
      
      
 <table>
<tr><th>Table A </th> <th>Min cost</th></tr>
<tr><td>

| 1 | 2 | 3 |
|---|---|---|
| 4 | 8 | 2 |
| 1 | 5 | 3 |

</td><td>

| 1 | 3 | 6 |
|---|---|---|
| 5 | 9 | 5 |
| 6 |10 | 8 |

</td></tr> </table>

Now that our table is filled, we simply return the cell of the given destination in the minimum cost array. The full code is [given here](https://github.com/nobodyme/Dynamic-Programming/blob/master/minimum-cost-path.C). Here is a [similar problem](http://practice.geeksforgeeks.org/problems/largest-zigzag-sequence/0). Try it on your own.

### More to come

  - Minimum coin change
  
### Points to remember
  
  - Dynamic programming is just like any like any other kind you get some, you don't get some practice makes it all better. I have lot to do too.
  - From my experience, it is similar to brute force but instead of exploring the whole input space, you find a way to store intermediate results that arise from the input and exhaustively explore that for the required result.
  - Yes, it is indeed a method of trading time for space. A recursive approach may utilize a little less space but dynamic programming approach is quicker.

### Other resources
  - [Hackerearth article explaining more on "Why dynamic programming"](https://www.hackerearth.com/practice/notes/dynamic-programming-i-1/)
  - [Geeks for geeks for practice problems](http://practice.geeksforgeeks.org/topics/Dynamic-Programming/)
  - [Geeks for geeks tutorials](http://www.geeksforgeeks.org/fundamentals-of-algorithms/#DynamicProgramming)
  - [Hackerearth article for problems involving grids](https://www.hackerearth.com/practice/notes/dynamic-programming-problems-involving-grids/)
