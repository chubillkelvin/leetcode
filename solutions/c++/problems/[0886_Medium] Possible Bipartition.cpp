class Solution {
    unordered_map<int, vector<int>> mp;
public:
    bool bipartite(int n, unordered_set<int> &ungrouped) {
        vector<int> group(n, -1);
        queue <vector<int>> bfs;
        int firstItem = *ungrouped.begin();
        ungrouped.erase(firstItem);
        bfs.push({firstItem});
        group[firstItem] = 1;
        while (!bfs.empty()) {
            auto curr = bfs.front();
            vector<int> next;
            for (int person: curr) {
                auto dislikedPeople = mp[person];
                for (int dis: dislikedPeople) {
                    if (group[dis] == group[person]) return false;
                    if (group[dis] == -1) {
                        group[dis] = group[person] == 1 ? 2 : 1;
                        next.push_back(dis);
                        ungrouped.erase(dis);
                    }
                }
            }
            bfs.pop();
            if (!next.empty()) bfs.push(next);
        }
        return true;
    }

    bool possibleBipartition(int n, vector <vector<int>> &dislikes) {
        for (int i = 0; i < dislikes.size(); i++) {
            auto curr = dislikes[i];
            mp[curr[0] - 1].push_back(curr[1] - 1);
        }
        unordered_set<int> ungrouped;
        for (int i = 0; i < n; i++) ungrouped.insert(i);
        while (!ungrouped.empty()) {
            bool canBipartite = bipartite(n, ungrouped);
            if (!canBipartite) return false;
        }
        return true;
    }
};