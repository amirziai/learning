### [Constraposition](https://en.wikipedia.org/wiki/Contraposition)
```
1.  p => q       		Premise
2.  | ¬q         		Assumption
3.  | | p        		Assumption
4.  | | ¬q       		Reiteration 3
5.  | p => ¬q    		Implication introduction 3, 4
6.  | p => q     		Reiteration 1
7.  | ¬p         		Negation introduction 
8.  ¬q => ¬p     		Implication introduction 2, 8
```

### [De Morgan's Law](https://en.wikipedia.org/wiki/De_Morgan%27s_laws)
```
1.  ¬q ∨ ¬r      		Premise
2.  | ¬q				Assumption
3.  | | q ∧ r 			Assumption
4.  | | q 				And elimination 3
5.  | q ∧ r => q		Implication introduction 3, 4
6.  | | q ∧ r 			Assumption
7.  | | ¬q				Reiterate 2
8.  | q ∧ r => ¬q		Implication introduction 6, 7
9.  | ¬(q ∧ r)			Negation introduction 5, 8
10. ¬q => ¬(q ∧ r)		Implication introduction 2, 9
11.  | ¬r				Assumption
12.  | | q ∧ r 			Assumption
13.  | | r 				And elimination 12
14.  | q ∧ r => r		Implication introduction 12, 13
15.  | | q ∧ r 			Assumption
16.  | | ¬r				Reiterate 11
17.  | q ∧ r => ¬r		Implication introduction 15, 16
18.  | ¬(q ∧ r)			Negation introduction 14, 7
19. ¬r => ¬(q ∧ r)		Implication introduction 11, 18
20. ¬(q ∧ r)			Or elimination 1, 10, 19
```
