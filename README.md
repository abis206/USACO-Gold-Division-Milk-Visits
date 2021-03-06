# USACO-Gold-Division-Milk-Visits
My solution to the USACO Gold Division problem: Milk Visits

Problem:
Farmer John is planning to build N (1≤N≤105) farms that will be connected by N−1 roads, forming a tree (i.e., all farms are reachable from each-other, and there are no cycles). Each farm contains a cow with an integer type Ti between 1 and N inclusive.
Farmer John's M friends (1≤M≤105) often come to visit him. During a visit with friend i, Farmer John will walk with his friend along the unique path of roads from farm Ai to farm Bi (it may be the case that Ai=Bi). Additionally, they can try some milk from any cow along the path they walk. Since most of Farmer John's friends are also farmers, they have very strong preferences regarding milk. Each of his friends will only drink milk from a certain type of cow. Any of Farmer John's friends will only be happy if they can drink their preferred type of milk during their visit.

Please determine whether each friend will be happy after visiting.

SCORING:
Test case 2 is the second example case below.
Test case 3 satisfies N≤103,M≤2⋅103.
Test cases 4-7 satisfy Ci≤10 (Ci defined below).
INPUT FORMAT (file milkvisits.in):
The first line contains two integer N and M.
The second line contains N space-separated integers T1,T2,…,TN. The type of the cow in the i-th farm is denoted by Ti.

The next N−1 lines each contain two distinct integers X and Y (1≤X,Y≤N), indicating that there is an edge between farms X and Y.

The next M lines contain integers Ai, Bi, and Ci. Ai and Bi represent the endpoints of the path walked during friend i's visit, while Ci (1≤Ci≤N) indicates the type of cow whose milk the friend enjoys drinking.

OUTPUT FORMAT (file milkvisits.out):
Print a binary string of length M. The ith character of the string should be '1' if the ith friend will be happy, or '0' otherwise.
SAMPLE INPUT:
5 5
1 1 2 1 2
1 2
2 3
2 4
1 5
1 4 1
1 4 2
1 3 2
1 3 1
5 5 1
SAMPLE OUTPUT:
10110
In this example, the path from 1 and 4 involves farms 1, 2, and 4. All of these contain cows of type 1, so the first friend will be satisfied while the second one will not.

SAMPLE INPUT:
6 4
1 2 3 3 3 3
1 2
2 3
3 4
2 5
5 6
4 6 1
4 6 2
4 6 3
4 6 4
SAMPLE OUTPUT:
0110
