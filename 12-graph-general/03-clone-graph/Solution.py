class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None
        clones = {node: Node(node.val)}
        stack = [node]
        while stack:
            cur = stack.pop()
            for nb in cur.neighbors:
                if nb not in clones:
                    clones[nb] = Node(nb.val)
                    stack.append(nb)
                clones[cur].neighbors.append(clones[nb])
        return clones[node]
