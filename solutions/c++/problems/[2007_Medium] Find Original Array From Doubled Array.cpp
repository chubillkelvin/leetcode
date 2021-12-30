class Solution {
    unordered_map<int, int> mp;
    unordered_map<int, bool> handled;
public:
    int singleCount(int key) {
        if (mp[key] == 0) return mp[key];
        if (key == 0) return mp[key] / 2;
        if (key % 2 == 0) {
            return mp[key] - singleCount(key / 2);
        }
        return mp[key];
    }

    vector<int> findOriginalArray(vector<int>& changed) {
        for(auto num: changed) mp[num]++;
        int s = 0;
        int d = 0;
        vector<int> ans;
        for(auto num: changed) {
            if (handled[num]) continue;
            if (num == 0 && mp[0] % 2 != 0) return {};
            int count = singleCount(num);
            if (count < 0) return {};
            for (int i = 0; i < count; i++) ans.push_back(num);
            s += count;
            d += mp[num] - count;
            handled[num] = true;
        }
        return s == d ? ans : vector<int>{};
    }
};