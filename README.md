<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**

- [About](#about)
  - [Prerequisites](#prerequisites)
  - [Repo structure](#repo-structure)
    - [Lessons (in the README file)](#lessons-in-the-readme-file)
      - [Problem categories](#problem-categories)
    - [Material](#material)
    - [Solutions](#solutions)
- [Lessons](#lessons)
  - [1. Number Theory: Factorization and Sieve of Eratosthenes](#1-number-theory-factorization-and-sieve-of-eratosthenes)
    - [Resources](#resources)
    - [Notes](#notes)
    - [Problems](#problems)
  - [2. Number Theory: GCD, LCM, Extended Euclidean Algorithm](#2-number-theory-gcd-lcm-extended-euclidean-algorithm)
    - [Resources](#resources-1)
    - [Problems](#problems-1)
      - [GCD, LCM Problems](#gcd-lcm-problems)
      - [Extended Euclid Problems](#extended-euclid-problems)
      - [Extra](#extra)
  - [3. Trees: Minimum Spanning Trees](#3-trees-minimum-spanning-trees)
    - [Refresh: DSU](#refresh-dsu)
    - [Resources](#resources-2)
    - [Problems](#problems-2)
  - [4. Trees: Tree Center and Diameter](#4-trees-tree-center-and-diameter)
    - [Refresh: DFS, BFS](#refresh-dfs-bfs)
    - [Resources](#resources-3)
    - [Problems](#problems-3)
  - [5. DP - Warm Up](#5-dp---warm-up)
    - [Resources](#resources-4)
    - [Problems](#problems-4)
  - [6. DP - Table Method and Patterns](#6-dp---table-method-and-patterns)
    - [Resources](#resources-5)
    - [Problems](#problems-5)
  - [7. DP - Tricks and Masks](#7-dp---tricks-and-masks)
    - [Resources](#resources-6)
    - [Problems](#problems-6)
    - [Subarrays](#subarrays)
    - [State Graphs](#state-graphs)
    - [Consider One Element](#consider-one-element)
    - [Masks](#masks)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# About
## Prerequisites
The basics covered in this training:  
https://github.com/MohamedAfifii/ProblemSolving--Arabic

## Repo structure
### Lessons (in the README file)
Lessons will usually contain:
- Resources covering the specified topic
- Extra notes (either videos or text) on points not covered by the resources
- Problems

#### Problem categories
Problems will usually be divided to:
- Basic problems: These are the problems that you should not skip. If you struggle with a basic problem, go read the solution to get the idea, then implement the solution on your own.
- Extra problems: These are usually harder problems. Feel free to skip these and get back to them later when you finish the training if you need more practice on a certain topic.
- Refresh problems: These problems are not related to the topic covered by the lesson, they will usually be
    - Problems on older topics
    - Ad-hock or greedy problems

Problems are **sorted** according to difficulty.

### Material
I will put the source code used in the videos that I record there.

### Solutions
This directory contains **documented solutions** for the training problems. If the solution isn't straightforward, you will find an explanation above the main function.

It is **highly recommended** that you read through the solutions even if you solve the problem, as you may find useful tricks there!

# Lessons
## 1. Number Theory: Factorization and Sieve of Eratosthenes

### Resources
Read these two short PDFs:
- [x] https://codility.com/media/train/8-PrimeNumbers.pdf
- [ ] https://codility.com/media/train/9-Sieve.pdf

Watch these two videos by Mustafa Saad:
- [ ] https://www.youtube.com/watch?v=VZBfW08ECgA
- [ ] https://www.youtube.com/watch?v=-5ApOQDhBtU

Watch this video that highlights important points that were not highlighted by the resources above:  
- [ ] https://youtu.be/xUk2SggGDRc

### Notes
The code in the last video can be easily modified to generate all the divisors (not only the prime divisors) for all numbers from 1 to N.
```CPP
int n = 10;
vector<vector<int>> divisors(n+1);

//i starts from 1
//All numbers (not only prime numbers) will visit their multiples
for(int i = 1; i <= n; i++)    
{
    for(int j = i; j <= n; j += i)
    {
        divisors[j].push_back(i);
    }
}
```
The complexity of this algorithm is `O(NlogN)` (assuming that `push_back` is `O(1)` for simplicity). The proof is similar to the proof mentioned in [Codility's PDF](https://codility.com/media/train/9-Sieve.pdf), except that the summation is now over all numbers from 1 to N. See this interesting [derivation](https://stackoverflow.com/questions/25905118/finding-big-o-of-the-harmonic-series) if you want to know why the upper bound for the summation is indeed `O(logN)` (**feel free to skip the proof**).


### Problems
As this is an extremely important topic that frequently appears on programming contests, please solve all the following problems:
- [ ] Codility - [CountFactors](https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/count_factors/)
- [ ] Codility - [MinPerimeterRectangle](https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/min_perimeter_rectangle/)
- [ ] SPOJ - [Prime Count](http://www.spoj.com/problems/PCOUNT/)
- [ ] SPOJ - [Almost Prime Numbers](http://www.spoj.com/problems/KPRIMES/)
- [ ] Codeforces - [Sherlock and his girlfriend](http://codeforces.com/problemset/problem/776/B)
- [ ] Codility - [CountSemiprimes](https://app.codility.com/programmers/lessons/11-sieve_of_eratosthenes/count_semiprimes/)
- [ ] Codility - [CountNonDivisible](https://app.codility.com/programmers/lessons/11-sieve_of_eratosthenes/count_non_divisible/)
- [ ] Codeforces - [Easy Number Challenge](http://codeforces.com/problemset/problem/236/B)
- [ ] Codeforces - [Bear and Prime Numbers](http://codeforces.com/problemset/problem/385/C)

**Extra**  
If the above problems were easy for you and you want to go fancier, read this [link](https://www.geeksforgeeks.org/segmented-sieve/) about Segment Sieve, then give the following problems a try:
- [ ] [SPOJ PRIME1](https://www.spoj.com/problems/PRIME1/)
- [ ] [UVA 294](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=230)

## 2. Number Theory: GCD, LCM, Extended Euclidean Algorithm
### Resources
- [ ] https://codility.com/media/train/10-Gcd.pdf  
Skip section 12.3
- [ ] https://www.youtube.com/watch?v=YklnFXpq0ZE  
Skip the parts of the video that are not related to GCD, LCM (they will be covered later).
- [ ] https://www.youtube.com/watch?v=2k0TPnZyobY

### Problems
#### GCD, LCM Problems
- [ ] Hackerrank - [Sherlock and GCD](https://www.hackerrank.com/challenges/sherlock-and-gcd/problem)
- [ ] Codeforces - [Modified GCD](https://codeforces.com/problemset/problem/75/C)
- [ ] Codility - [Chocolates by Numbers](https://app.codility.com/programmers/lessons/12-euclidean_algorithm/chocolates_by_numbers/)
- [ ] Codeforces - [LCM](https://codeforces.com/problemset/problem/1068/B)
- [ ] Codeforces - [Alarm Clocks Everywhere](https://codeforces.com/contest/1155/problem/C)
- [ ] Codeforces - [Alice and Bob](https://codeforces.com/problemset/problem/347/C)

#### Extended Euclid Problems
Note that problems that involve using the Extended Euclidean Algorithm are usually hard problems, so don't get disappointed if you struggle with them. I will try to provide easy to read solutions so that you can understand the solution if you get stuck!
- [ ] [UVA 10104 - Euclid Problem](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1045)
- [ ] [UVA 10673 - Play with Floor and Ceil](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1614)
- [ ] [UVA 10090 - Marbles](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1031)

#### Extra
- [ ] [Codeforces - Neko does Math](https://codeforces.com/problemset/problem/1152/C)
- [ ] [Codeforces - The Beatles](https://codeforces.com/contest/1143/problem/D)  
This problem is a harder version of Codility's [Chocolates by Numbers](https://app.codility.com/programmers/lessons/12-euclidean_algorithm/chocolates_by_numbers/).


## 3. Trees: Minimum Spanning Trees
### Refresh: DSU
- [ ] [DSU (Arabic)](https://www.youtube.com/watch?v=-jWBvgMw44U)
- [ ] [Codeforces - 884C](https://codeforces.com/contest/884/problem/C)

### Resources
Watch these two videos by Mustafa Saad:
- [ ] https://www.youtube.com/watch?v=tcQky6O1em8
- [ ] https://www.youtube.com/watch?v=HQ5ANfzSDn0

### Problems
- [ ] [SPOJ MST](https://www.spoj.com/problems/MST/)
- [ ] [UVA 10147 - Highways](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1088)
- [ ] [UVA 10369 - Arctic Network](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1310)
- [ ] [ECPC2017 - Dream Team (Hard)](https://codeforces.com/gym/101840)

## 4. Trees: Tree Center and Diameter
### Refresh: DFS, BFS
- [ ] [Graph Theory - DFS (Arabic)](https://www.youtube.com/watch?v=9DP0X2xlPCo)
- [ ] [Graph Theory - BFS (Arabic)](https://www.youtube.com/watch?v=COB1GHq0YwY)
- [ ] [SPOJ - BUGLIFE (Graph coloring, Testing bipartiteness)](https://www.spoj.com/problems/BUGLIFE/)      
- [ ] [UVA 852 - Deciding victory in Go (DFS on grid)](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=793)
- [ ] [Codeforces - 558C (BFS on implicit graph)](https://codeforces.com/contest/558/problem/C)
- [ ] [Codeforces - 767C (DFS, imporant!)](https://codeforces.com/contest/767/problem/C)

### Resources
- [ ] [Graph Theory - Tree Diameter and Isomorphism (Arabic)](https://www.youtube.com/watch?v=RASvnfG2SSE)

### Problems
- [ ] [SPOJ PT07Z](https://www.spoj.com/problems/PT07Z/)
- [ ] [SPOJ TREEISO](https://www.spoj.com/problems/TREEISO/)
- [ ] [Codeforces - 1068E (Not hard)](https://codeforces.com/contest/1068/problem/E)


## 5. DP - Warm Up
### Resources
- [ ] https://www.youtube.com/watch?v=TNgPT91sn90&t=121s (Introduction + how to print the optimal solution)  

Read this lesson from Codility
- [ ] https://codility.com/media/train/15-DynamicProgramming.pdf

Watch these 3 videos by Mustafa Saad
- [ ] https://www.youtube.com/watch?v=gFdP6X4CyKU
- [ ] https://www.youtube.com/watch?v=gFdP6X4CyKU
- [ ] https://www.youtube.com/watch?v=vAqaki1BhS0


### Problems
- [ ] [Codeforces - 35D](https://codeforces.com/problemset/problem/35/D)    (Knapsack-like)
- [ ] [Codeforces - 189A](https://codeforces.com/problemset/problem/189/A)   (Reduced version of the Coin Change problem)
- [ ] [ECPC2016 H](https://codeforces.com/gym/101147/problem/H)
- [ ] [Codeforces - 761C](https://codeforces.com/problemset/problem/761/C)
- [ ] [SPOJ ELIS](https://www.spoj.com/problems/ELIS/)  (LIS, no need to memoize)
- [ ] [SPOJ TLCS](https://www.spoj.com/problems/TLCS/)  (LCS  + printing output)
- [ ] [Codeforces - 2B](https://codeforces.com/problemset/problem/2/B) (Printing output, good one)

## 6. DP - Table Method and Patterns
### Resources
- [ ] Mustaf Saad's video for table method  
https://www.youtube.com/watch?v=PrXbn8-zw14
- [ ] Another video explaining table method (and some other stuff) in a better way  
https://www.youtube.com/watch?v=34Drti_iMsg
- DP patterns
    - [ ] [Consecutive ranges](https://www.youtube.com/watch?v=bDlAqeWsKsg)
    - [ ] [Nested ranges](https://www.youtube.com/watch?v=b4AC2jGNGEM)
    - [ ] [General ranges](https://www.youtube.com/watch?v=pJbeTrSKl3Y)

### Problems
- [ ] [ICPC archive - 2675](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=676)
- [ ] [UVA 10003](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=944)
- [ ] [UVA 348](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=284)
- [ ] [UVA 10739](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1680)
- [ ] [Codeforces 245H](https://codeforces.com/problemset/problem/245/H)
- [ ] [Codeforces 835D](https://codeforces.com/problemset/problem/835/D)
- [ ] [IEEExtreme11 - Gotta Catch 'Em All](https://csacademy.com/ieeextreme-practice/task/e610aba28810ebcf2d3998692269b5a0/)
- [ ] [Codeforces 1107E](https://codeforces.com/problemset/problem/1107/E)

## 7. DP - Tricks and Masks
### Resources
- [ ] [DP Tricks - Subarrays (Arabic)](https://youtu.be/XKAv9BrTQYk)
- [ ] [DP Tricks - State Graphs (Arabic)](https://youtu.be/baz0hOmrbe0)
- [ ] [DP Tricks - Consider One Element (Arabic)](https://youtu.be/8Uv3FvJ8rCQ)
- [ ] [Dynamic Programming - Masks - 1 (Arabic)](https://www.youtube.com/watch?v=8aATaY9sdeE)
- [ ] [Dynamic Programming - Masks - 2 (Arabic)](https://www.youtube.com/watch?v=AIjk-KVgjQo)

### Problems
### Subarrays
- [ ] [Codility MaxSliceSum](https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_slice_sum/)
- [ ] [Codility MaxDoubleSliceSum](https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_double_slice_sum/)
- [ ] [Codeforces 1155D](https://codeforces.com/contest/1155/problem/D)
- [ ] [Codeforces 841C](https://codeforces.com/problemset/problem/814/C)

### State Graphs
- [ ] [SPOJ DBALLZ](https://www.spoj.com/problems/DBALLZ/)
- [ ] [UVA 562](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=114&page=show_problem&problem=503)
- [ ] [Codeforces 837D](https://codeforces.com/problemset/problem/837/D)
- [ ] [Codility MinAbsSum](https://app.codility.com/programmers/lessons/17-dynamic_programming/min_abs_sum/) (Hard, see the [solution](https://codility.com/media/train/solution-min-abs-sum.pdf) if you get stuck)


### Consider One Element
- [ ] [Codeforces 1132F](https://codeforces.com/contest/1132/problem/F)

### Masks
- [ ] [UVA 10911](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1852)
- [ ] [IEEExtreme11 - Preparing for Xtreme 12.0](https://csacademy.com/ieeextreme-practice/task/72a7d67e7e18f4f7d033f7f5a5a09bef/)
