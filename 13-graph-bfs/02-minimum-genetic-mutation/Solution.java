import java.util.*;

class Solution {
    public int minMutation(String startGene, String endGene, String[] bank) {
        if (startGene.equals(endGene)) return 0;
        Set<String> valid = new HashSet<>(Arrays.asList(bank));
        if (!valid.contains(endGene)) return -1;
        Deque<String> q = new ArrayDeque<>();
        Map<String, Integer> dist = new HashMap<>();
        q.add(startGene);
        dist.put(startGene, 0);
        char[] genes = {'A', 'C', 'G', 'T'};
        while (!q.isEmpty()) {
            String gene = q.poll();
            int steps = dist.get(gene);
            if (gene.equals(endGene)) return steps;
            char[] arr = gene.toCharArray();
            for (int i = 0; i < arr.length; i++) {
                char orig = arr[i];
                for (char ch : genes) {
                    if (ch == orig) continue;
                    arr[i] = ch;
                    String cand = new String(arr);
                    if (valid.contains(cand) && !dist.containsKey(cand)) {
                        dist.put(cand, steps + 1);
                        q.add(cand);
                    }
                }
                arr[i] = orig;
            }
        }
        return -1;
    }
}
