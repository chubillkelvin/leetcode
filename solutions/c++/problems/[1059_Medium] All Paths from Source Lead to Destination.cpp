class Solution {
    vector<vector<int>> adj;
    int destination;
public:
    bool dfs(int node, unordered_set<int> &path) {
        if (node == destination) return adj[node].empty();
        if (adj[node].empty()) return false;
        bool canReach = true;
        for(auto next: adj[node]) {
            if(path.count(next) == 0) {
                path.insert(next);
                canReach = canReach && dfs(next, path);
                path.erase(next);
            } else {
                return false;
            }
        }
        return canReach;
    }

    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        adj = vector<vector<int>>(n, vector<int>{});
        this->destination = destination;
        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        if (adj[source].empty()) return source == destination;
        for(auto node: adj[source]) {
            unordered_set<int> path;
            path.insert(node);
            if(!dfs(node, path)) return false;
        }
        return true;
    }
};