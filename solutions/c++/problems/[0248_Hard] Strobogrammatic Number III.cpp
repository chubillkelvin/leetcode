class Solution {
    unordered_map<int, vector<string>> memo;
public:
    bool isValid(string s) {
        return to_string(stoll(s)) == s;
    }

    vector <string> findStrobogrammatic(int n) {
        if (n == 1) return {"0", "1", "8"};
        if (n == 2) return {"11", "69", "88", "96"};
        if (memo.find(n) != memo.end()) return memo[n];
        auto bases = n % 2 == 0 ? vector < string > {"00", "11", "69", "88", "96"} : vector < string > {"0", "1", "8"};
        int curr = n % 2 == 0 ? 2 : 1;
        vector <string> ans;
        while (curr < n) {
            vector <string> temp;
            for (auto base: bases) {
                string s1 = '0' + base + '0';
                temp.push_back(s1);
                string s2 = '1' + base + '1';
                temp.push_back(s2);
                string s3 = '6' + base + '9';
                temp.push_back(s3);
                string s4 = '8' + base + '8';
                temp.push_back(s4);
                string s5 = '9' + base + '6';
                temp.push_back(s5);
            }
            bases = temp;
            curr += 2;
        }
        for (auto base: bases) if (isValid(base)) ans.push_back(base);
        sort(ans.begin(), ans.end());
        return memo[n] = ans;
    }

    int strobogrammaticInRange(string low, string high) {
        int n1 = low.size();
        int n2 = high.size();
        int count = 0;
        for (int i = n1; i <= n2; i++) {
            auto temp = findStrobogrammatic(i);
            if (i != n1 && i != n2) {
                count += temp.size();
            } else {
                int start = 0;
                int end = temp.size() - 1;
                if (i == n1) {
                    int j = start;
                    while (j <= end && temp[j] < low) j++;
                    start = j;
                }
                if (i == n2) {
                    int j = end;
                    while (j >= 0 && temp[j] > high) j--;
                    end = j;
                }
                count += max(end - start + 1, 0);
            }
        }
        return count;
    }
};