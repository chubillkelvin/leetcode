class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) return 0;
        if (n == 2) return 1;
        string starting = "";
        string ending = "";
        vector<pair<int, string>> next;
        for(int i = 0; i < n; i++) {
            starting += "0";
            ending += "1";
        }
        for(int i = 0; i < n; i++) next.push_back(make_pair(i, starting));
        vector<unordered_map<string, bool>> memo(n);
        queue<vector<pair<int, string>>> bfs;
        bfs.push(next);
        int count = 0;
        while(!bfs.empty()) {
            auto curr = bfs.front();
            vector<pair<int, string>> next;
            for(auto [i, v]: curr){
                v[i] = '1';
                if (v == ending) return count;
                for(auto j: graph[i]) {
                    if (!memo[j][v]) {
                        next.push_back(make_pair(j, v));
                        memo[j][v] = true;
                    }
                }
            }
            count++;
            bfs.pop();
            if(!next.empty()) bfs.push(next);
        }
        return count;
    }
};