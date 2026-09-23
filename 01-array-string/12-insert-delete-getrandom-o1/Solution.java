import java.util.*;

class RandomizedSet {
    private List<Integer> vals;
    private Map<Integer, Integer> idx;
    private Random rand;

    public RandomizedSet() {
        vals = new ArrayList<>();
        idx = new HashMap<>();
        rand = new Random();
    }

    public boolean insert(int val) {
        if (idx.containsKey(val)) return false;
        idx.put(val, vals.size());
        vals.add(val);
        return true;
    }

    public boolean remove(int val) {
        if (!idx.containsKey(val)) return false;
        int i = idx.get(val);
        int last = vals.get(vals.size() - 1);
        vals.set(i, last);
        idx.put(last, i);
        vals.remove(vals.size() - 1);
        idx.remove(val);
        return true;
    }

    public int getRandom() {
        return vals.get(rand.nextInt(vals.size()));
    }
}
