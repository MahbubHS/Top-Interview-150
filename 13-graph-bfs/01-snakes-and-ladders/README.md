# Snakes and Ladders

**Difficulty:** Medium | **Category:** Graph BFS
**LeetCode:** https://leetcode.com/problems/snakes-and-ladders/

## Problem Understanding
An `n x n` board is numbered 1..n² in a zigzag ("boustrophedon") order starting at the bottom-left. From square `s` you roll a die and move to any of `s+1..s+6`; landing on a snake/ladder square sends you to its destination. Find the fewest moves to reach square n², or -1.

## Approach
Each square is a graph node with up to 6 outgoing edges, and every move costs 1, so the fewest moves is a **BFS shortest path**. The only tricky part is converting a square number to board coordinates: rows count from the bottom, and every odd row runs right-to-left.

## Algorithm
1. Map square `s` to `(r, c)`: `r, c = divmod(s-1, n)`; flip `c` when `r` is odd; read `board[n-1-r][c]`.
2. BFS from square 1; for each of the next 6 squares, jump to the snake/ladder destination if it is not `-1`.
3. Record the distance the first time a square is reached; stop when reaching n².

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
2×2 board `[[-1,-1],[-1,3]]`: from 1 roll to 2, 3 (ladder to 3) or 4 → square 4 is reachable in 1 move → `1`.

## Complexity
- Time: O(n²)
- Space: O(n²)

## Edge Cases
- A snake/ladder is taken only once per move (no chaining of destinations).
- Target unreachable → `-1`.
