# Stanford CS228 Probabilistic Graphical Models Notes
https://cs.stanford.edu/~ermon/cs228/index.html

### Review
- [ ] Law of total probability
- [ ] ...

### Week 1
- Inference requires marginalization that's `2 ^ (N - 1)` if N is the number of binary variables
- We'll solve this with the right representation (i.e. data structure)
- `Val(X)` is the values or states of random variable `X` `Val(X) = {Head, Tail}`
- Number of parameters to parameterize a joint distribution with N binary variables is `2 ^ N - 1` since we lose a single DoF because `Sum(p_i) = 1`
- Space concern, i.e. how many parameters needed? tabular approach not scalable
- Simplifying assumptions i.e. factorization
	- Indpendence. Joint probability distribution `p(x1, ..., xn)` factorizes into `p(x1)p(x2)...p(xn)` i.e. the product of marginal probabilities
		- States are still `2 ^ N`
		- Parameters needed to specify the joint probability are `N` assuming each is a `Ber(p)` where `p` is the parameter (same as if `|Val(Xi)| = 2`)
	- Use conditional independence, if events `A` and `B` are conditionally independent given `C` then `p(A, B) = p(A | C)p(B | C)`
		- Be careful: RVs `X` and `Y` are conditionally independent given `Z` if for all values/states of `X`, `Y`, and `Z` this relationship holds: `p(X=x, Y=y, Z=z)=p(X=x | Z=z)p(Y=y | Z=z)`
		- If `p(X, Y | Z) = p(X | Z)p(Y|Z)` then `p(X | Y, Z) = p(X | Z)`
```
p(X, Y, Z)	= p(X | Y, Z)p(Y, Z)
			= p(X, Y | Z)p(Z)
			= p(X | Z)p(Y | Z)p(Z)
			= (p(X, Z) / p(Z))(p(Y, Z) / p(Z))p(Z)
			= p(X, Z)p(Y, Z) / p(Z)

p(X | Y, Z)	= p(X, Y, Z) / p(Y, Z)
			= (p(X, Z)p(Y, Z) / p(Z)) / p(Y, Z)
			= p(X, Z) / p(Z) = p(X | Z)

p(X | Y, Z) = p(X | Z)
```

- Conditional independence: `X ⟂ Y | Z` `X` and `Y` conditionally independent given `Z`
- Same goes for a set of RV's **`X ⟂ Y | Z`**
- Properties of conditional independence
	- Symmetry: `X ⟂ Y | Z => Y ⟂ X | Z`
	- Decomposition: `X ⟂ (Y, Z) | Z => X ⟂ Y | Z`
	- Contraction: `(X ⟂ Y | Z) Λ (X ⟂ W | Y, Z) => X ⟂ Y, W | Z`
	- Weak union: `X ⟂ Y, W | Z => X ⟂ Y | Z, W`
	- Intersection: if `p(.) > 0`: `(X ⟂ Y | Z) Λ (X ⟂ W | Y, Z) => X ⟂ Y, W | Z`
- Chain rule is a general way to factorize
```
p(S1, S2, ..., Sn) = p(S1)p(S2|S1)p(S3|S2, S1)...p(Sn|S1, ..., Sn-1)
```

For `n=2` we recover the definition of conditional probability
```
p(S1, S2) = p(S1)p(S1 | S2)
```



- ...

### Week 2
...
