# Stanford CS157 Computational Logic Notes
aka automated logic and reasoning

## Chapter 1 Intro
* Logical sentences divide the set of all possible worlds into true and false subsets
* A set of premises logically entails a conclusion if conclusion in true in every world that ALL premises are true
* Abduction is reasoning from effects to possible causes
* e.g.
    * p => q
    * m | r => p | q
    * if a proposition on the LHS of a sentence is the same as RHS for another sentence then drop it
        * m | r => q | q
        * q | q is really q so m | r => q
* Logics
    * Proposition logic, conditions in the world
    * Relational logic individual objects and inter-relatinships, object constants, relation constants, variables, quantifiers
    * Herbrand logic infinitely many objects, nice computational properties lost

## Chapter 2 Propositional Logic
* Proposition possible condition of the world that is either true of false
    * Condition need not be true for it to be a proposition
* Sentences
    * Simple aka proposition constant, logical constants
    * Compound 5 types
        * Negation, ¬ in front of a target sentence, i.e. ¬p
        * Conjunction, AND
        * Implication, a (antecedent) => b (consequent)
* Operator precedence
    * ¬
    * ∧
    * ∨
    * => <=>
* Propositional vocabulary set of all proposition constants
* Propositional language is a set of all propositional sentences from the vocabulary
* Truth assignment for a propositional vocabulary is a function assigning a truth value to each of the proposition constants of the vocabulary
    * This doesn’t mean that we have to assign true to each constant, we’re just assigning either true or false to each variable
    * Truth assignment satisfies a sentence if and only if the sentence is true under that truth assignment
    * Truth assignment falsifies a sentence iff the sentence is false under the truth assignment
    * Truth assignment falsifies a set of sentences if at least one sentence is false under truth assignment
* Evaluation determine truth value of a compound sentence given truth assignments for proposition constants
* Satisfaction opposite of evaluation. Figure out which truth assignments satisfy 1 or more compound sentences
* Natural language
    * If cool or funny then popular, c | f => p
    * Popular only if cool or funny, same as if popular then cool or funny, p => c | f
    * Popular iff cool or funny, p <=> c | f
    * Not possible to be both cool and funny, ~(c & f)

## Chapter 3 Propositional Analysis
* Satisfaction relationship between specific sentences and specific truth assignments
* Logical properties
    * Validity always satisfied, p | ~p
    * Contingency p & q
    * Unsatisfiability never satisfied p & ~p
* Logical relationships between sentences
    * Entailment every truth assignment that satisfies Φ also satisfied Ψ, but not the other way around Φ ⊨ Ψ
        * p ⊨ p | q
        * p | q does not entail p
        * p does not entail p & q
        * Similar to arithmetic inequality
    * Equivalence every truth assignment that satisfies Φ also satisfies Ψ and the other way around. In other words they should be exactly the same value in all cases.
    * Consistency
        * Φ consistent with Ψ iff there’s a truth assignment that satisfies both Φ and Ψ
        * p | q not consistent with ~p & ~q
        * Consistent sentences not necessarily equivalent
        * Consistent sentences do not necessarily entail each other
        * If one sentence entails another this does not mean that these sentences are consistent, happens when one of the sentences is unsatisfiable
            * Any unsatisfiable sentence or set of sentences logically entails  everything
            * Avoid unsatisfiable set of sentences in logical reasoning
* Connections between properties and relationships
    * Equivalence theorem Φ and Ψ logically equivalent iff Φ <=> Ψ is valid
    * Deduction theorem
        * Φ entails Ψ iff Φ => Ψ
        * {Φ_1, ..., Φ_n} logically entails Φ iff (Φ_1 & ... & Φ_n) => Φ
    * Unsatisfiability theorem
        * If a set Δ of sentences logically entails a sentence Ψ, then Δ together with negation of Ψ must be unsatisfiable. Reverse is also true.
        * Set of Δ sentences logically entails a sentence Φ iff Δ ∪ {~Φ} is unsatisfiable
        * We can determine logical entailment by checking for unsatisfiability
    * Consistency theorem
        * Φ is consistent with Ψ iff Φ & Ψ is satisfiable
        * Sentence Φ is consistent with {Φ_1, ..., Φ_n} iff Φ_1 & ... & Φ_n & Φ is satisfiable

## Chapter 4 Propositional Proofs
* Schema expression satisfying grammatical rules of our language
    * except for occurrence of metavariables
    * schema with metavariables Φ and Ψ
        * Φ => Ψ
* Rule of inference consisting of schemas (premises) and one or more additional schemas called conclusions
    * Implication Creation (IC) if Ψ then x => Ψ for any x
    * Implication Distribution (ID)
        * Φ => Ψ => xi
        * (Φ => Ψ) => (Φ => xi)
* Linear proof
    * Proof of a sentence Φ from a set Δ of premises using the rules of inference in R, we say that Φ is provable from Δ using R.
        * Δ ⊢ R Φ
        * ⊢ provability operator (single turnstile)
    * Not easy
* Soundness
    * Provable finite proof of the conclusion from the premises
    * Sound
        * Every provable conclusion is logically entailed, or Δ⊢Φ then Δ⊨Φ
        * If you prove something then you’re confident it’s valid
    * Complete
        * Every logical conclusion is provable
        * You can prove them all, so complete
    * Fitch
        * Sound
        * Complete
        * For the full language
        * Logical entailment and provability the same thing
* If one premise entails a conclusion then adding more premises can only make the entailment easier to satisfy. In other words if you want to know if a conclusion is entailed by a set of premises, showing that it’s entailed with one is enough
    * e.g.
    * is (p⇒(p∧q))⇒((p⇒q)⇒r) and q | ~p consistent with p => q? yes because q | ~p is equivalent to p => q (~p | q and reversed)

## Chapter 5 Propositional Resolution
* Literal is an atomic or negation of an atomic (simple) sentence
* Clausal sentence is either a literal or a disjunction of literals
* Φ => Ψ, ~Φ | Ψ
* Φ <=> Ψ, (~Φ | Ψ) & (Φ | ~Ψ)
* ~(Φ | Ψ), (~Φ & ~Ψ)
* a | (b & c), (a | b) & (a | c)
* Propositional resolution aka Resolution principle
    * e.g. given {Φ1, ..., xi, ..., Φ_n} and {Ψ1, ..., ~xi, ..., Ψ_n} we can get {Φ1, Ψ1, ..., Φ_n, Ψ_n}
    * {p, q} and {~p, q} merge the two q’s into {q}
    * resolution of two singletons results in an empty clause, e.g. {p} and {~p} yields {}
    * apply one resolution at a time
        * {p, q} and {~p, ~q} yields {q, ~q} and {p, ~p}
    * e.g.
        * p => q and p, by IE yields q
        * {~p, q}, {p} yields {q}
    * if at any point {a} and {~a} appear then we have the empty clause {}
* INDO
    * Implication, Negation, Distribution, Operators
* Resolution derivation of a conclusion from a set of premises is a finite sequence of clauses terminating in the conclusion with each clause being either a premise or the result of applying the resolution principle
    * Similar to linear proof, but not called proof in this context
* Generative completeness resolution is NOT generatively complete, not possible to find resolution derivations for all clauses that are logically entailed by a set of premises
    * e.g. {p} and {q} doesn’t yield {p, q} which is logically entailed
    * Cannot derive any conclusions from an empty set of premises, e.g. p & ~p which is always true
* If a set of clauses is unsatisfiable then we are guaranteed to be able to derive an empty clause from Δ
* Unsatisfiability theorem Δ entails Φ iff Δ∪{~Φ} is inconsistent
* To determine logical entailment negate the goal, add as a premise, use resolution to determine if the set is unsatisfiable, and if it is then Δ entails Φ
* Resolution proof of Φ from Δ is deriving {} from Δ∪{~Φ}, if this happens Δ⊢Φ or Φ is provable from Δ
* Benefits of propositional proof
    * It’s focused. No need to choose instantiations carefully or search through INFINITELY many possible instantiations for rules of inference
    * Always terminates without losing completeness

Empty
* The empty set of *sentences* is satisfied by all truth assignments.  Thus, it logically entails only things that are valid, i.e. true in all truth assignments,
* The empty *clause*, i.e an empty set of disjuncts is unsatisfiable. It does, however, entail everything, since whenever the sentences in it are true (trivially none), then the entailed statement is also true.

## Chapter 6 Relational Logic
* Prop logic inadequate for more general statements, add quantifiers and variables and get relational logic
* In Relational Logic (RL) there are no propositional constants, instead we have object constants, relation constants (with an arity), and variables
* Vocabulary (aka signature) is a set of object constants and set of relation constants with assigned arity
* Term is variable or object constant, analogous to noun phrases in natural language
* 3 types of sentences in RL
    * 1- relational (aka atoms), analog of propositions in in Prop Logic (PL). e.g. q(a, y)
    * 2- logical, analog of logical in PL. e.g. ~p(a), p(a) <=> q(b, c)
    * 3- quantifier, no analog
* Quantifiers have higher precedence than other logical operators
* Expression is ground iff it has no variables, e.g. p(a) ground, AX:p(x) not ground
* Variable is free if it’s not within the scope of a quantifier, e.g. y is free in EX:q(x, y)
* A sentence is open iff it has free variables, closed otherwise
* Herbrand base is set of all ground relational sentences, e.g. for a vocabulary with object constants a and and p(_) and q(_, _) the Herbrand base is {p(a), p(b), q(a,a), q(a,b), q(b,a), q(b,b)}
* For b object constants for each n-arity relation constant we have b^n sentences in the Herbrand base
* Instance of an expression is an expression that all free variables have been consistently (i.e. replace with the same ground term) replaced by ground terms
* Truth assignment satisfies a sentence with FREE variables iff it satisfies every instance
* Truth assignment satisfies a set of sentences iff it satisfies every sentence
* Bess likes somebody who likes her EX:(likes(B, X) & likes(X, B))
* A block satisfies the clear relation if and only if there is nothing on it. ∀y.(clear(y) ⇔ ¬∃x.on(x,y))
* Sentences are either satisfiable (valid or contingent) or unsatisfiable
* ∃y.∀x.likes(x,y) <=> ∀x.∃y.likes(x,y)
* q(x,y) is satisfied if and only if ∀x.∀y.q(x,y) is satisfied
* Convert RL to PL
    * 1- Convert sentences to prenex form meaning it has to be closed and all quantifiers are outside of all logical operators (e.g. ∀y.p(x,y) ∨ ∃y.q(y) should become ∀x.∀y.∃z.(p(x,y) ∨ q(z))):
        * 1- rename variables to eliminate duplications
        * 2- apply quantifier distribution in reverse to move quantifiers outside of logical operators
        * 3- universally quantify free variables
    * 2- Ground the results
        * 1- If ground just add it to Γ
        * 2- If ∀ν.φ[ν] then add a copy for each object constant to Δ and remove the quantified sentence from Δ
        * 3- If ∃ν.φ[ν] then remove from Δ and add a disjunction of object constants {φ[τ1] ∨ ... ∨ φ[τn]}
    * 3- Rewrite in PL
        * Rewrite ground relational sentences by proposition constants
* Question of unsatisfiability for PL is decidable => RL unsatisfiability decidable.
* Logical entailment and unsatisfiability are correlated => logical entailment for RL is decidable
* Every unsatisfiable set of sentences contains a finite subset that is unsatisfiable (compactness?) => logical entailment can be demonstrated with finite proofs
* Example: n object constants and single binary relation constant: n ground terms, n^2 ground atomic sentences, 2^(n^2) truth assignments
* ∀x.¬likes(x,x) everybody does not like themselves is the same as ¬∃likes(x,x) there’s no one that likes herself
* If ∀x.∃y.loves(x,y) then everybody loves some person (not necessarily the same person) but for ∃y.∀x.loves(x,y) there’s a single person that everyone loves. So ∀x.∃y.p(x,y) ⇒ ∃y.∀x.p(x,y) is not true since it states that if everybody loves some person (not the same person) then everybody loves the same person which is not necessarily true. The reverse is true though. ∃y.∀x.p(x,y) ⇒ ∀x.∃y.p(x,y) if everybody loves the same person then saying that everybody loves someone is less restrictive and justified.

## Chapter 7 Relational Analysis
* n object constants, m relation constants of arity k,m*n^k or 2^(m*n^k) truth assignments
* Semantic trees, interleave unit propagation? and simplification? with tree generation -> pruning
* Boolean models (truth assignment). Sometimes there is just one model. Even if we have more than one we can reduce the combinations.
* Non-Boolean model, alternative representation that can shrink the space. For example for 4 object constants and 2 unary relation constants there are 8 elements in the Herbrand base and 2^8 truth assignments but if we have a constraint that each relation is only true of a single object then we can collapse this into 4^2 possibilities.
* φ and ∀x.φ are equivalent ∀x.φ ⊨ φ & φ ⊨ ∀x.φ. From Piazza: "a sentence with free variables is true in a truth assignment iff it’s true of all elements in the universe”.

## Chapter 8 Relational Proofs
* Set of RL premises logically entails an RL conclusion iff there is a finite proof of conclusion from premises.
* For UI the variable being quantified cannot be free or active in an assumption meaning a proof or a superproof
* For EE if there’s a free variable we introduce a Skolem function that captures all the free variables
* EI only applies in cases where the replaced term does not contain a universally quantified term. Deriving ∃y.∀x.hates(x,y) from ∀x.hates(x,[f(x)]) is incorrect since we go from everybody hates somebody to there is a single person that everybody hates
* For Domain Closure (DC) the presence of Skolem terms (constant or function) is not a deal breaker since they represent one of the object constants and if we have a schema satisfying all object constants then we can apply DC
* Given ∀x.∀y.(p(x,y) ⇒ q(x)), we know that ∀x.(∃y.p(x,y) ⇒ q(x)). This is possible provided the variable does not occur in the consequent of the implication. The reverse is also true. Given ∀x.(∃y.p(x,y) ⇒ q(x)), we know that ∀x.∀y.(p(x,y) ⇒ q(x))

## Chapter 9 Herbrand Logic
* RL works with finite objects
* Herbrand syntax: RL + function constants and functional expressions
* Functions produce other terms in the language
* Expressions and term synonymous
* f(_, _) is a binary function constant and f(a, y) is a functional expression
* Unlike relational sentences functional expressions can be nested
* Herbrand logic term is variable or an object constant or a functional expression.
* Herbrand base is infinitely large
* Evaluation not practical for 2 reasons: 1- infinite truth assignment 2- even for finite truth assignments evaluation of quantified sentences may not be feasible.
* We can still indirectly determine validity, contingency and unsatisfiability.
* [a, [b, c], d] := cons(a, cons(cons(b, cons(c, nil)), cons(d, nil))
* Herbrand Logic (HL)
    * Addition and multiplication can be defined in finite form which is not possible with RL and in other logics (e.g. FOL).
    * Unsatisfiability and logical entailment are not effectively computable
    * If our logic was semidecidable then question of unsatisfiability/logical entailment would also be, but HL is not know to be semidecidable so it must not be.
* Diophantine
    * 3*x^2=1 := ∃x.∃y.(times(x, x, y) ∧ times(s(s(s(0))), y, s(0)))
    * Express unsolvability of Diophantine by negating the sentence
    * Do the axioms of arithmetic logically entail this negation or equivalently does the union of axioms and unnegated sentence are unsatisfiable
    * Determining whether Diophantine equations are unsolvable is not semidecidable. If we could determine unsatisfiability then we could decide unsolvability which would contradict the non-semidecidability of that problem
* f(f(a)) by itself is not legal

## Chapter 10 Herbrand Proofs
* With some restrictions a set of premises logically entails a conclusion iff there’s a finite proof even when the base is infinite. It is possible to find these proofs in finite time.
* If a set of sentences does not logically entail a conclusion then the search may never stop
* If we remove the restrictions then we lose finite proof guarantee
* HL inherently incomplete and not compact
* Compactness: if an infinite set of sentences is unsatisfiable there is some finite subset that is unsatisfiable
* Compactness guarantees finite proofs
* Corollary to that is infinite proofs which states that in HL some entailed sentences only have infinite proofs. Can’t really do domain closure or the like
* Checking whether a candidate proof actually proves a conjecture is decidable

## Chapter 11 Induction
* Reason from specific to general
* Incomplete, complete (all instances), and mathematical (complete induction applied to numbers)
* Varies with the structure of the language
* Domain Closure (DC) does not work for an infinite Herbrand base
* Linear language has a single object constant (base element) and a single unary function constant (successor function)
* Base case, inductive case (inductive hypothesis => inductive conclusion), overall conclusion
* Tree induction, 1 object constant and finite # of unary function constants
* Structural induction is the most general form: multiple object constants, multiple n-ary function constants

## Chapter 12 Resolution
* Resolution Principle (RP) is a Rule of Inference (ROI) for RL
* Using RP we can build a sound and complete reasoning system
* RP search space < Herbrand proofs
* Literal is either relational sentence or negation of
* Clause is a set of literals
* Existentials Out (E) step ∃x.p(x) → p(a) ∃x not within the scope of a universal where a is a Skolem constant. Otherwise ∀x.(p(x) ∧ ∃z.q(x, y, z)) → ∀x.(p(x) ∧ q(x, y, f(x, y))) where f(x, y) is a Skolem function of x, y (free)
* Pure substitution iff terms in range free of variables in domain of substitution. Intersection of domain and range is empty?
* Pure substitutions are idempotent
* Composition: 1- apply τ to range of σ to get σ' with updated range 2- σ’ + elements of τ with domain not appearing in the domain of σ’ e.g. {x←a, y←f(u), z←v}{u←d, v←e, z←g} = {x←a, y←f(d), z←e, u←d, v←e}
* Composition does not preserve purity or lack thereof
* Composable iff domain of σ and range of τ are disjoint
* Composable substitutions preserve purity
* σδ=τ <=> σ is more general than τ
* mgu:
    * If one is a variable
        * If second contains that variable fail (occur check)
        * Otherwise compose old substitution and {var <- expr}
    * If neither is a variable and 1 is a constant fail e.g. p(a, x) and p(x, b)
* Any clause is a trivial factor of itself
* Resolution derivation of a conclusion is a sequence of clauses terminating in the conclusion
* Resolution is sound
* Resolution is NOT generatively complete e.g. cannot derive anything from an empty set of premises
* Unsatisfiability. Contradiction takes the form of the empty clause <=> disjunction of no literals
* Resolution and Fitch w/out DC are equally powerful
* Given a set of sentences resolution can derive the empty clause iff Fitch can find a proof of a contradiction
* Refutation theorem: we can establish Δ |- φ by showing that Δ∪{¬φ} is unsatisfiable
* Resolution refutation is when ¬φ is added to Δ which yields Δ’ and then Δ’ is turned into clausal form and if empty clause is formed from Δ’ then Δ |- φ
* Resolution used in proving complex math theorem and program correctness
* Answer literal e.g. p(x, jon) => goal(x)
* Sometimes the result of fill-in-the-blank resolution depends on the refutation by which it’s produced. Several different refutations can result from the same query that result in multiple answers
* Due to undecidability of logical entailment we can never know if we’ve found all the possible answers
* Remove
    * Clauses with pure literals i.e. have no compliments
    * Tautologies e.g. {p(a), ~p(x)} doesn’t count, {p(a), ~p(a), q(a)} is ok to remove
* Subsumption elimination
    * {p(x), q(y)} subsumes {p(a), q(v), r(w)}
    * {p(a), q(v), r(w)} is the subsumed clause
    * If {p(x), q(y)} then we can elimination {p(a), q(v), r(w)}
* Inference based on unit resolution is not complete
    * There’s a unit refutation of a set of Horn clauses (at most 1 positive literal) iff it is unsatisfiable
* Unit resolution and input resolution are equivalent in inferential power: unit refutation from a set of sentences whenever there is an input refutation and vice versa
    * Input resolution complete for Horn but incomplete in general
* No input resolution for {p, q}, {~p, q}, {p, ~q}, and {~p, ~q}
* Linear resolution
    * Refutation complete
    * If Δ is satisfiable and Δ∪{Φ} is unsatisfiable then there’s a linear refutation with Φ as the top clause (i.e. starting clause)
    * If we need a set of clauses is consistent then refutation with the elements of that set as top clauses is not successful
    * Merge inherents a literal from each parent and collapsed into a singleton by gmu
* Set of support
    * Γ is a set of support for Δ-Γ iff Δ-Γ is satisfiable
    * Set of support resolvent is one in which at least one parent is select from Γ or is a descendant of Γ
