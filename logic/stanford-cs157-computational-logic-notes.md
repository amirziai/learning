# Stanford CS157 Computational Logic Notes
aka automated logic and reasoning

## Chapter 1
Intro
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

## Chapter 2
Propositional Logic
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

## Chapter 3
Propositional Analysis
* Satisfaction relationship between specific sentences and specific truth assignments
* Logical properties
    * Validity always satisfied, p | ~p
    * Contingency p & q
    * Unsatisfiability never satisfied p & ~p
* Logical relationships between sentences
    * Entailment every truth assignment that satisfies Φ also satisfied Ψ, but not the other way around Φ |= Ψ
        * p |= p | q
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
        * 

## Chapter 4
Propositional Proofs
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
        * Δ |-R Φ
        * |- provability operator (single turnstile)
    * Not easy
* Soundness
    * Provable finite proof of the conclusion from the premises
    * Sound
        * Every provable conclusion is logically entailed, or Δ|-Φ then Δ|=Φ
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
    * 
    * 

## Chapter 5
Propositional Resolution
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
* Resolution proof of Φ from Δ is deriving {} from Δ∪{~Φ}, if this happens Δ|-Φ or Φ is provable from Δ
* Benefits of propositional proof
    * It’s focused. No need to choose instantiations carefully or search through INFINITELY many possible instantiations for rules of inference
    * Always terminates without losing completeness

Empty
* The empty set of *sentences* is satisfied by all truth assignments.  Thus, it logically entails only things that are valid, i.e. true in all truth assignments,
* The empty *clause*, i.e an empty set of disjuncts is unsatisfiable. It does, however, entail everything, since whenever the sentences in it are true (trivially none), then the entailed statement is also true.

