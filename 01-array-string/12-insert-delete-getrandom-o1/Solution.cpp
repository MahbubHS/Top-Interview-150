class RandomizedSet {
    vector<int> vals;
    unordered_map<int,int> idx;
public:
    RandomizedSet() {}
    bool insert(int val) {
        if (idx.count(val)) return false;
        idx[val] = vals.size();
        vals.push_back(val);
        return true;
    }
    bool remove(int val) {
        if (!idx.count(val)) return false;
        int i = idx[val];
        int last = vals.back();
        vals[i] = last;
        idx[last] = i;
        vals.pop_back();
        idx.erase(val);
        return true;
    }
    int getRandom() {
        return vals[rand() % vals.size()];
    }
};
