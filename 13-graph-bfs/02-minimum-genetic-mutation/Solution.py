from collections import deque

class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: list[str]) -> int:
        if startGene == endGene:
            return 0
        valid = set(bank)
        if endGene not in valid:
            return -1
        q = deque([(startGene, 0)])
        seen = {startGene}
        while q:
            gene, steps = q.popleft()
            if gene == endGene:
                return steps
            for i in range(len(gene)):
                for ch in 'ACGT':
                    if ch == gene[i]:
                        continue
                    nxt = gene[:i] + ch + gene[i + 1:]
                    if nxt in valid and nxt not in seen:
                        seen.add(nxt)
                        q.append((nxt, steps + 1))
        return -1
