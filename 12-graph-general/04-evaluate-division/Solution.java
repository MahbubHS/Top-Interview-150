import java.util.*;

class Solution {
    private Map<String, Map<String, Double>> graph = new HashMap<>();

    public double[] calcEquation(List<List<String>> equations, double[] values,
                                 List<List<String>> queries) {
        graph.clear();
        for (int i = 0; i < equations.size(); i++) {
            String a = equations.get(i).get(0), b = equations.get(i).get(1);
            graph.computeIfAbsent(a, k -> new HashMap<>()).put(b, values[i]);
            graph.computeIfAbsent(b, k -> new HashMap<>()).put(a, 1.0 / values[i]);
        }
        double[] res = new double[queries.size()];
        for (int i = 0; i < queries.size(); i++) {
            res[i] = dfs(queries.get(i).get(0), queries.get(i).get(1), new HashSet<>());
        }
        return res;
    }

    private double dfs(String src, String dst, Set<String> visited) {
        if (!graph.containsKey(src) || !graph.containsKey(dst)) return -1.0;
        if (src.equals(dst)) return 1.0;
        visited.add(src);
        for (Map.Entry<String, Double> e : graph.get(src).entrySet()) {
            if (visited.contains(e.getKey())) continue;
            double r = dfs(e.getKey(), dst, visited);
            if (r != -1.0) return e.getValue() * r;
        }
        return -1.0;
    }
}
