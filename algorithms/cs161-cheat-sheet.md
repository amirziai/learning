# Algorithms
[Stanford CS161](http://cs161.stanford.edu/) cheat sheet

### TODO
- [ ] add subs method notes
- [ ] subs method example
- [ ] subs method for linear time select T(n) <= T(n/5) + T(7n/10) + O(n) <= Cn/5 + 7/10Cn + dn <= Cn so choose C=10d and then C=max{7, 10d} for all n>1, T(n)<=Cn => T(n)=O(n)
- [ ] Expected Runtime of Randomized Quicksort
- [ ] 

### Questions
- [ ] worst-case lower bound
- [ ] worst-case for linear time selection is Omega(n)
- [ ] Recurrence T(n) = 3T(n/4) + nlogn
- [ ] Recurrence T(n) = 2T(n/2) + nlogn
- [ ] Recurrence T(n) = T(n-1) + O(n)
- [ ] Lecture 3 page 10 "but we can solve select(B, m/2) for len(B)=m < n assuming correctness of the algorithm on smaller inputs is a helpful technique for designing divide and conquer algorithms"
- [ ] T(n) <= T(n/5) + T(0.7n) + O(n) for linear time selection. T(n/5) comes from median of median, T(0.7n) comes from the upper bound on the numbe of elements that will be in either left or right lists, and O(n) comes from the partitioning?
- [ ] shallow tree for comparison sort. is this tree structure unique for a binary tree which produces exactly the n! permutations?
- [ ] d(x) = 1 + d(x.L) + d(x.R), what is the 1 doing there?
- [ ] Tight vs. loosed bound? If a bound is tight that means it is an upper and a lower bound (which seems to just be equivalent to Big Theta notation) and if it is loose, it simply means that it is not tight (e.g different upper and lower bounds). You can express a tight-bound using Big-O or Big-Ω. For example, any of the following statements would be tight-bounds on the worst-case runtime of insertion sort: O(n2), Ω(n2), Θ(n2).
- ...

## Useful stuff
- Sum_c^n 1/c = O(logn)
- Sum of infinite geometric series `Sum_{i=0}^{\infty}r^k` where `0 < k < 1` equals `1 / (1 - r)`
- `E[P(T)]=Sum E[P(T)|r(T)=i].P(r(T)=i) where P(r(T)=i)`
- quicksort recurrence `P(n)=n-1 + 1/n Sum_{i=0}&{n-1} (P(i) + P(n-i-1))`
- Markov's inequality c>0, `Pr[X>cE[X]] < 1/c`
- 
- ...

## Algorithmic Analysis
### Insertion sort
```
Input: list X with n elements
Output: sorted list

for each index in i=0 to len(X) - 1
	keep moving the element in i towards the front of the list while X[i] < X[j] where j < i in place

return X
```
- How many comparisons?
	- Best case: list is already sorted, n-1 (i.e. O(1) in the inner loop so the whole thing is O(n))
	- Worst case: list is sorted in reverse order, would take (n-1)n/2 operations and is therefore O(n^2)

### Loop invariant
- Condition that's true before and after each iteration of the loop

### Proof by induction
- **Inductive hypothesis** loop invariant holds after the i-th iteration
- **Base case / initialization** loop invariant holds before the first iteration, in other words a list of size 1 is sorted
- **Inductive step / maintenance** loop invariant holds after i-th iteration => holds after the (i+1)-th iteration
- **Conclusion / termination** loop invariant holds after the last iteration => algorithm is correct

### Bigs
- Big-O is an upper bound, ignore constants and non-dominant growth terms
	- 0 <= T(n) <= c.g(n)
	- T(n)=n^2 and g(n)=n, Prove: T(n)!=O(g(n)). Assume T(n)=O(g(n)) => n>=n_0 and n^2 <= c.n. Take n=max(c, n_0) + 1 => n>c => n^2>c.n which is a contradiction with our assumption so T(n)!=O(g(n)).
- Big-Omega
	- 0 <= c.g(n) <= T(n)
- Runtime of an algorithm is usually asking for the upper-bound for the worst-case runtime

## Divide and conquer
- Induct on __length of the input list__ as opposed to loop iteration
	- **Inductive hypothesis:** works on input lists of length 1 to i
	- **Base case:** works on input list of size 1
	- **Inductive step:** works on size i => works on size i + 1
	- **Conclusion:** works on size n => works on entire list

### Proving correctness
```
Algorithm type:
Iterative
	- find loop invariant
	- define inductive hypothesis (internal state at iteration i)
	- base case i=0
	- i => i+1
	- i=n => correct

Recursive
	- define inductive hypothesis (correct for input sizes 1 to i)
	- base case (i < small constant)
	- inductive step (i=>i+1 OR {1,2,...,i} => i+1)
	- i=n => correct, it's called on the entire list so because inductive step holds at i=n we have the correct answer
```

### Solving recurrences
- Simplifications: rewrite Omega terms, choose n to be a power of 2, set c=max(c_1, c_2). Methods: recursion tree, iteration, master, substitution.
- Master method, for T(n)=a.T(n/b)+O(n^d)
	- a=b^d   => O(n^d * logn)
	- a < b^d => O(n^d)
	- a > b^d => O(n^log_b(a))
- Top-heavy: lots of work towards the top, not very deep

### Linear-time selection
- Comparison-based
- Median of sub-medians =~ median of the whole list
	- At least 3 * (ceil(g / 2) -1 -1) + 2 elements guaranteed to be smaller than median of medians
	- g is the number of groups, assuming 5 elements in each group
	- first -1 is to exclude the list with median of median (would be the same if we did floor(g / 2)?)
	- second -1 is for the list with leftovers which in the worst case would have all items larger than median of median
	- Number of things larger than median of median: (n-1) - (3 * ceil((n / 5) / 2) -2 + 2) <= 0.7n + 3
	- n-1 is everything except for the median


## Sorting
- Any deterministic comparison-based sorting algo requires Omega(nlogn) time
	- Longest path in a decision tree that represents all the comparisons
	- There are n! leafs
	- Depth of the shallowest tree with this many leaves => log(n!).
- Bucket sort O(max{nlogn, n+k})
- Radix sort O(d(n+k))
	- Needs extra memory to bucketize
	- Needs info about ordering and buckets

## Randomized algorithms
- Las Vegas algos guarantee correctnss not runtime. Monte Carlo the other way around.
- Bogosort
	- 1/n! probability of landing on a sorted list
	- Expected value of geometric distribution is 1/p=n!
	- Each iteration of bogosort requires O(n) work so the expected runtime is O(n.n!)

### Randomized selection
- Expected runtime
	- if we select a pivot in the middle 50% we will shrink the list to at least 3/4
	- in phase k we will have at most n(3/4)^k elements
	- the last phase is ceil(log_{4/3} n)

### Hashing
- Expected # of items in u_x’s bucket is O(1) is good
- All buckets have expected size O(1) is bad
- Exhaustive set of hash functions n^|U|
- p(h(u_x) = h(u_y)) = 1/n for the exhaustive set H
- How many bits to write down the name of one of the x=n^|U| functions? logx=|U|logn, enough to do direct addressing!
- Universal hash function, for all u_x, u_y pairs probability of collision over the set of hash functions must be less than or equal to 1 / # of buckets (n)
	- Hash integer, h=ax + b % p % n for some prime p >= |U| and a and b in {1,2,3...,p-1} 
		- |H| = p(p-1) = O(p^2)=O(|U|^2)
		- space needed to store is log(|U|^2)=O(log|U|) << O(|U|logn)
	- u-bit string x
		- h(x)=Ax, u=log|U|, b=logn, A=b x u random matrix of 0's and 1's
		- 2^{ub} binary matrices = O(|U|^{logn}) << n^{|U|} but much smaller than 

## Tree algorithms
- Predecessor of 5 in 5 -> 3 -> 4 is 4 and not 3
### Red-black tree
- NIL child is black. for all vertices all paths from v to NIL descendants has the same # of blacks
- bLack vertices balanced, red are spread out
- can be maintained by rotations
- non-NIL descendants of x >= 2^{b(x)}-1 where b(x) = largest # of black nodes in any path from x to NIL excluding x but including NIL descendants
- d(x) = # of non-NIL descendants of x, d(x) = 1 + d(x.left) + d(x.right)
- Red-black tree has height <= 2 log_2(n+1)=O(logn)
	- n >= b^{b(r) - 1} >= 2^{h/2}-1 => h <= 2log_2{n+1}
	- number of black vertices is at least the number of red vertices
	- b(x) >= half of the height

## Graph algorithms
- Adjacency matrix edge membership O(1), neighbors of u, O(|V|), space O(|V|^2)
- Adjacency list (better for sparse graphs) edge membership O(deg(u) or deg(v)), neighbor O(deg(v)), space O(|V|+|E|)
- dfs, O(|V|+|E|), searches the connected component, directed/undirected
	- topological sort, if (u, v) in E then end_time u > end_time of v
	- dfs in-order traversal => BST in order, print when marked done
	- exact traversal
- bfs, shortest path between u and v
	- bipartite: starting from any vertex and alternate colors on levels (# of steps away from source), if any vertex is attempted to be colored 2 different colors => not bipartite
		- bfs colors two neighbors the same color iff it's found a cycle of odd length. impossible to color an odd cycle with 2 colors s.t. no 2 neighbors have the same color.
- strongly connected components (scc). kosaraju's. 1- dfs-loop 2- reverse edges (helps to have incoming neighobrs) 3- repeat dfs-loop starting with the largest end time, SCCs are isolated sub-graphs
	- SCC metagraph is a DAG (if not 2 SCCs collapse into one)
	- Largest end_time has no incoming edges, reversing the edges means it'll have no outgoing edges so it'll be an SCC, same follows for other SCCs
	- for (u, v) in SCC metagraph where u in C_1 and v in C_2 end time of C_1 > end time of C_2


### Single Source Shortest Path (SSSP)
- Dijkstra's works if no negative edges
- Bellman Ford works with negative edges but no negative cycles (ill-posed)
	- References `k` and `k-1`
