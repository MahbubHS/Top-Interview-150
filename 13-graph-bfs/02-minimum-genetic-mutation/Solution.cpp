class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if (startGene == endGene) return 0;
        unordered_set<string> valid(bank.begin(), bank.end());
        if (!valid.count(endGene)) return -1;
        queue<pair<string,int>> q;
        unordered_set<string> seen = {startGene};
        q.push({startGene, 0});
        const string genes = "ACGT";
        while (!q.empty()) {
            auto [gene, steps] = q.front();
            q.pop();
            if (gene == endGene) return steps;
            for (int i = 0; i < (int)gene.size(); i++) {
                char orig = gene[i];
                for (char ch : genes) {
                    if (ch == orig) continue;
                    gene[i] = ch;
                    if (valid.count(gene) && !seen.count(gene)) {
                        seen.insert(gene);
                        q.push({gene, steps + 1});
                    }
                }
                gene[i] = orig;
            }
        }
        return -1;
    }
};
