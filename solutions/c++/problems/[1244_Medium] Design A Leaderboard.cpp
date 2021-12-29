class Leaderboard {
    unordered_map<int, int> mp;
public:
    Leaderboard() {

    }

    void addScore(int playerId, int score) {
        if (mp.find(playerId) == mp.end()) {
            mp[playerId] = score;
        } else {
            mp[playerId] += score;
        }
    }

    int top(int K) {
        priority_queue<int> q;
        for (auto p: mp) q.push(p.second);
        int sum = 0;
        while (K > 0 && !q.empty()) {
            sum += q.top();
            q.pop();
            K--;
        }
        return sum;
    }

    void reset(int playerId) {
        mp.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */