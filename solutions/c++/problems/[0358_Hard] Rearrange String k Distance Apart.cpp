class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k == 0) return s;
        vector<int> count(26, 0);
        for (char c: s) count[c - 'a']++;
        priority_queue <pair<int, char>> addChar;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                addChar.push(make_pair(count[i], 'a' + i));
            }
        }
        vector<int> lastPos(26, -1);
        string ans = "";
        while (!addChar.empty()) {
            vector <pair<int, char>> next;
            int doneCount = 0;
            while (!addChar.empty() && doneCount < k) {
                char c = addChar.top().second;
                int idx = c - 'a';
                addChar.pop();
                count[idx]--;
                if (lastPos[idx] == -1 || ans.size() - lastPos[idx] >= k) {
                    lastPos[idx] = ans.size();
                    ans += c;
                } else {
                    return "";
                }
                doneCount++;
                if (count[idx] > 0) next.push_back(make_pair(count[idx], c));
            }
            for (auto p: next) addChar.push(p);
        }
        return ans;
    }
};