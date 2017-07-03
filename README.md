# Dynamic Programming

There were huge number of sources on the internet on this topic but still we (me and my friend) couldn't understand any of it until a very long time until we fiddled with code and tracked the output for every change in the input. So this repository is exactly created for people like us to make the transition from [greedy](https://en.wikipedia.org/wiki/Greedy_algorithm) to dynamic programming easier. This will just be an introduction to dynamic programming, so that one can pick it up from there. I have added additional sources for practice and other useful online sources that I found useful at the end and will contiue to do so as I find something new. It is for programmers who are comfortable with brute-force and might not the serve the purpose for absolute beginners.

### Definition 

So what's dynamic programming? Let's first look at a more formal definition.

Dynamic programming (also known as dynamic optimization) is a method for solving a complex problem by breaking it down into a collection of simpler subproblems, solving each of those subproblems just once, and storing their solutions. The next time the same subproblem occurs, instead of recomputing its solution, one simply looks up the previously computed solution, thereby saving computation time at the expense of a (hopefully) modest expenditure in storage space. (Each of the subproblem solutions is indexed in some way, typically based on the values of its input parameters, so as to facilitate its lookup). The technique of storing solutions to subproblems instead of recomputing them is called "memoization"[(Source-Wiki)](https://en.wikipedia.org/wiki/Dynamic_programming).

Or more simply, it is technique to save intermediate results in a calculation in any comfortable format so that the result can be used for further computation instead of calculating it all over again at the arrival of an additional input. Sounds simple enough? Yes, indeed it is, let's have a look at an example to put it right through our skull.


### Longest increasing subsequence
The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order. 
For example, the length of LIS for { 10, 12, 32, 2, 22, 23, 25, 30 } is 6 and LIS is { 10, 12, 22, 23, 25, 30 }

This will be elaborate step by step explanation about attaining the solution, since this is the first sum.

So how would go on solving that?
Oh, the previous example told me to save the sub-problems to make the computation easier!
What are the sub-problems here?

Oh, it's too tough.

No, it's not we will work together.

So, how would go on solving that using brute force just like how you would perform a [selection sort](https://en.wikipedia.org/wiki/Selection_sort)!

<div align="center">

| 10  | 12  | 32  | 2 | 22  | 23  | 25 | 30 |
|--:|---|---|---|---|---|---|---|

</div>

You would compare every element with every other element, if it's greater than the current one, you would increase count variable and print the highest one, right? Let us look at the result after such an implementation in the above array.

***pseudo code*** </br>
if (j > k) </br>
count = 1;
if (12 > 10)  yes --> count++, j++, k++ </br>
if (32 > 12)  yes --> count++, j++, k++ </br>
if (2 > 32)  no  --> j++ </br>
if (22 > 32)  no </br>
.. </br>
.. </br>
end 

So such an implementation returns the `max-length = 3`, which is { 10, 12, 32 }. We know it's incorrect. If only we knew that by avoiding 32 and traversing through the rest of the array we would actually obtain the result which is `max-length = 6`. This is exactly the information we store for our computation using DP. In brute force terms, we store the count variable for all possible alternatives of traversal in the array and then simply find the maximum of it.

We set `count=1` and not 0 initially, because if all numbers are same in the array i.e { 2, 2, 2, 2}, we must return count as 1 since one element is the still the subarray of the larger one which is simply 2 therefore returning 0 would be wrong.

We create another array for storing the count, as we discussed earlier we initialize it to `1`

<div align="center">

| array | 10  | 12  | 32  |  2  | 22  | 23  | 25 | 30 |
|---    |---  |---  |---  | --- | --- |---  |--- |--- |
|count  |  1  |  1  |  1  |  1  |  1  | 1   | 1  | 1  |
|       | j   |  i  |     |     |     |     |    |    |

</div>

Now we check in a similar way,

For, now lets us consider only the elements 10 and 12 exist in the array.

<div align="center">

| array | 10  | 12  |
|---    |---  |---  |
|count  |  1  |  1  |
|       | j   |  i  |

</div>

</br>if(12>10) --> increment corresponding count of 12 ie `count[i] = count[j] + 1;`

Why is it, `count[j]+1`?
Because the count[j] stores the max count of sequence when 10 is traversed, now since we chose to traverse through 10 we add it's length to 12's count.The result is the Longest subsequence when 10, 12 alone are the elements in the array.

Now let us consider 32, increment `i to 32 and j to 10` ie j to the starting element of the array and traverse from the beginning to see adding 32 provides a longer subsequence.
</br>The array becomes,

<div align="center">

| array | 10  | 12  | 32  |
|---    |---  |---  |---  |
|count  |  1  |  2  |  1  |
|       | j   |     |  i  |

 
</br>Now since if(32>10) yes --> therefore repeat the step of incrementing 32's count --> count[i] = count[j]+1; and increment j.

| array | 10  | 12  | 32  |
|---    |---  |---  |---  |
|count  |  1  |  2  |  2  |
|       |     |  j  |  i  |

</br>if(32>12) --> 32's count = 12's count + 1 = (2+1) = 3


| array | 10  | 12  | 32  |
|---    |---  |---  |---  |
|count  |  1  |  2  |  3  |
|       |     |  j  |  i  |

</br>Similarly, considering 2 the array becomes,


| array | 10  | 12  | 32  | 2 |
|---    |---  |---  |---  |---|
|count  |  1  |  2  |  3  | 1 |
|       |  j  |     |     | i |

</br>The array stays the same since each case checking if(2>10) or if(2>12) fails, and it's count variable remains unchanged.

</div>

</br> Now let's add the next number, 22 and check for 10, 12, 32, similar to the previous for 10 and 12 count of 22 is incremented to 3 and with 32 it fails and remains as 3, and j is incremented to point 2.

<div align="center">

| array | 10  | 12  | 32  | 2 | 22 |
|---    |---  |---  |---  |---| -- |
|count  |  1  |  2  |  3  | 1 | 3  |
|       |     |     |     | j  | i |
</div>

</br>Now 22 > 2 --> count of 22 becomes `count[j]+1` i.e. 2? 
</br>No, we know that count reflects the longest subsequence, by traversing other elements in the array we obtained 3 as longest subsequence for 22. So why lower it to 2? Hence while adding `count[i] = count[j]+1` make sure it benefits the cause. Therefore place `count[i] = max(count[j]+1,count[i])` ie with the maximum of two numbers to avoid such cases.



And similarly the rest of the array is traversed and the array becomes,

<div align="center">

| array | 10  | 12  | 32  |  2  | 22  | 23  | 25 | 30 |
|---    |---  |---  |---  | --- | --- |---  |--- |--- |
|count  |  1  |  2  |  3  |  1  |  3  | 4   | 5  | 6  |
|       |     |     |     |     |     |     | j  |  i |


</div>

Since the highest is 6, that gives the longest increasing subsequence. Have a look at the [code snippet here](https://github.com/nobodyme/Dynamic-Programming/blob/master/longest-increasing-sub-sequence.C).

[The video of the above traversal is here](https://youtu.be/Ns4LCeeOFS4)

### More to come

  - Minimum cost path problem
  - Minimum coin change

### Other resources
  - [Hackerearth article explaining more on "Why dynamic programming"](https://www.hackerearth.com/practice/notes/dynamic-programming-i-1/)
  - [Geeks for geeks for practice](http://practice.geeksforgeeks.org/topics/Dynamic-Programming/)
  - [Geeks for geeks tutorials](http://www.geeksforgeeks.org/fundamentals-of-algorithms/#DynamicProgramming)