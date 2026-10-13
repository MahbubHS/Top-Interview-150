# IPO

**Difficulty:** Hard | **Category:** Heap
**LeetCode:** https://leetcode.com/problems/ipo/

## Problem Understanding
Starting with capital `w`, pick at most `k` projects (one at a time) to maximize final capital. A project is only affordable if its required capital is `<= current capital`; picking it adds its profit to capital.

## Approach
Greedy: at each of the `k` rounds, among all **currently affordable** projects, taking the one with the **highest profit** is always at least as good as any other choice (it maximizes capital for unlocking future projects too). Sort projects by required capital so affordable ones can be revealed incrementally; use a max-heap (by profit) to quickly grab the best affordable one each round.

## Algorithm
1. Sort projects by capital requirement.
2. For each of `k` rounds: push every project now affordable (capital <= w) into a max-heap by profit.
3. If the heap is empty, no more projects are affordable → stop early.
4. Otherwise pop the highest-profit project and add its profit to `w`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`k=2, w=0, profits=[1,2,3], capital=[0,1,1]`: round1 affordable={1} → take profit 1 → w=1. round2 affordable adds {2,3} → take profit 3 → w=4.

## Complexity
- Time: O(n log n) for the sort plus O(k log n) for the heap operations
- Space: O(n)

## Edge Cases
- No affordable projects at all → loop breaks immediately, returns `w` unchanged.
- `k` larger than the number of projects → simply exhausts all affordable ones and stops.
