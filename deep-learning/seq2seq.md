# Sequence 2 Sequence Models

Notes from [Andrew Ng's deeplearning.ai Deep Learning Specialization](https://www.coursera.org/learn/nlp-sequence-models)
[Lecture videos on Coursera](https://www.coursera.org/learn/nlp-sequence-models/lecture/v2pRn/picking-the-most-likely-sentence)

### Basic models

![Sequence to Sequence model](resources/465106B4-C91B-4A94-AB3F-9D6B891BDCB5.png)

use AlexNet as encoder, cut the softmax and then use an encoder for captioning
![Image captioning](resources/A20FBB9E-4417-4D74-AD95-DBF41F859D44.png)

language model: calculates probability of a sentence
can think of Language Model (LM) as a decoder network
with this in mind we can then say that Machine Translation (MT) is a decoder + LM
conditional language model e.g. P(English translation | French sentence)

![MT as conditional LM](resources/6E36FDCD-B718-40F7-866B-7C1026EC7145.png)

![Most likely translation](resources/79024588-EA4F-4630-9592-6B303ECD9D0C.png)

If we've started with
> Jane is ...

Then the next most likley greedy selection might be *going* and a better global sentence will be tossed in greedy search.
![Why not greedy search](resources/AC5AD23F-8615-492E-B010-6903A1B3C389.png)

### Beam Search
Beam width = `B`
Beam width is the number of candidates considered
Let's say `B=3`
![Beam search](resources/BB7C0960-E71F-466F-AEBD-F90869006789.png)

Instantiating 3 copies of the network in each step (i.e. one for each candidate).

![Beam search 3rd step](resources/13819EAC-4C94-49DF-80E6-F39150D7F1F3.png)

If `B=1` then beam search degenerates to greedy search

Multiplications can result in numerical underflow, maximizing the sum of log probabilities is the same.

![Numerical underflow](resources/CAB51805-F9B7-47BD-AB4A-6097E4F835A6.png)

This objective function tends to prefer shorter sentences as there's less multiplications of less than 1 values.
![Length normalization](resources/70559C79-4960-41E3-8B6B-D2E96A9B34B7.png)

Normalized log-likelihood

How to choose beam width B? computational complexity vs. result quality. Beam width of 10 likely for production systems, 100-1,000 more common for research projects. There's diminishing returns to increasing B. Beam search is an approximate/heuristic algorithm unlike BFS or DFS so it's faster but not guaranteed to find the optimal answer.

#### Error analysis in beam search

![Error analysis in beam search](resources/4A8963F3-18F5-4E96-BB04-7D3F0BC27E11.png)

If most of error is attributed to beam search then it may be warranted to incerase `B`
![Error analysis in beam search 2](resources/71C1D04C-79B7-4E8E-BED4-9249C01FA5DF.png)

### Bleu score
Bleu score on unigrams
![Bleu precision](resources/705E0418-A132-4CEA-B05C-BF393E73C9DF.png)

Bleu score on bigrams
![Bleu bigram](resources/3F2AD276-D22B-4EAB-96FF-A206623B5410.png)

Bleu score on n-grams
![Bleu n-gram](resources/BE37B458-F0DA-4BAF-B714-2E5BA7025565.png)

![Bleu](resources/A056B10E-FF5D-492A-9140-DFF937CEB3E3.png)

Image captioning and MT use bleu score

### Attention
![Long sequences](resources/092862A8-37D5-4DE2-A118-2F6D48409803.png)

Compute attention weights
![Attention](resources/74CAA003-ED3E-44EE-B831-75323C20ED01.png)

LSTMs used more commonly

![Context](resources/F0172EDB-C7CC-41B9-9C94-6111A52349D4.png)

![Context for step 2](resources/4D2DCB61-8E31-45F0-8D12-3809275C5ADC.png)

Calculating attention
Use softmax
$$S^{<t-1>}$$ is the hidden state from `t-1`
![](resources/)
