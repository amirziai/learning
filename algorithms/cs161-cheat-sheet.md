# Algorithms
[Stanford CS161](http://cs161.stanford.edu/) cheat sheet

### Questions
- [ ] ?
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
	- i=n => correct
```

### Solving recurrences
- 

## Sorting
x

## Randomized algorithms
x

## Tree algorithms
x

## Graph algorithms
x

### Single Source Shortest Path (SSSP)
- Dijkstra's works if no negative edges
- Bellman Ford works with negative edges but no negative cycles (ill-posed)
	- References `k` and `k-1`
