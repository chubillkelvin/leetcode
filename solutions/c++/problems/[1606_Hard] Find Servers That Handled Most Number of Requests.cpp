class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = load.size();
        int maxCount = 0;
        vector<int> ans;
        vector<int> handled(k, 0);
        set<int> free;
        for(int i = 0; i < k; i++) free.insert(i);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;
        for(int i = 0; i < n; i++) {
            while(!busy.empty() && busy.top().first <= arrival[i]) {
                free.insert(busy.top().second);
                busy.pop();
            }
            auto target = free.lower_bound(i % k);
            if (target == free.end()) target = free.begin();
            if (target != free.end()) {
                int server = *target;
                handled[server]++;
                if (handled[server] == maxCount) {
                    ans.push_back(server);
                } else if (handled[server] > maxCount) {
                    maxCount = handled[server];
                    ans = {server};
                }
                busy.push(make_pair(arrival[i] + load[i], server));
                free.erase(target);
            }
        }
        return ans;
    }
};