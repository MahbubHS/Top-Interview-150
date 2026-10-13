import java.util.*;

class Solution {
    private List<List<Integer>> res = new ArrayList<>();
    private List<Integer> path = new ArrayList<>();

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        res = new ArrayList<>();
        path = new ArrayList<>();
        bt(candidates, 0, target);
        return res;
    }

    private void bt(int[] candidates, int start, int remaining) {
        if (remaining == 0) {
            res.add(new ArrayList<>(path));
            return;
        }
        for (int i = start; i < candidates.length; i++) {
            if (candidates[i] > remaining) continue;
            path.add(candidates[i]);
            bt(candidates, i, remaining - candidates[i]);
            path.remove(path.size() - 1);
        }
    }
}
