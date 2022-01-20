class Solution {
    bool trimmed = false;
    unordered_map <string, unordered_map<string, int>> memo;
public:
    bool isMatch(string s, string p) {
        if (memo.find(s) != memo.end() && memo[s].find(p) != memo[s].end()) return memo[s][p] == 1;
        if (!trimmed) {
            trimmed = true;
            string trimmedP = "";
            for (char c: p) if (c != '*' || trimmedP.empty() || trimmedP.back() != '*') trimmedP += c;
            p = trimmedP;

            int n = p.size();
            if (n > 1) {
                if (p[0] == '*' && p[1] != '?') {
                    int skipped = 0;
                    for (char c: s) {
                        if (c == p[1]) break;
                        skipped++;
                    }
                    if (skipped > 0) s = s.substr(skipped, s.size() - skipped);
                }
                if (p[n - 1] == '*' && p[n - 2] != '?') {
                    while (!s.empty() && s.back() != p[n - 2]) {
                        s.pop_back();
                    }
                }
                if (p[p.size() - 1] != '*') {
                    while (!s.empty() && !p.empty()) {
                        if (s.back() == p.back() || p.back() == '?') {
                            s.pop_back();
                            p.pop_back();
                        } else {
                            break;
                        }
                    }
                }
                if (p[0] != '*') {
                    int minSize = min(s.size(), p.size());
                    for (int i = 0; i < minSize; i++) {
                        if (p[i] == '*' || (p[i] != '?' && s[i] != p[i])) {
                            if (i > 0) {
                                s = s.substr(i, s.size() - i);
                                p = p.substr(i, p.size() - i);
                            }
                            break;
                        }
                    }
                }
            }
        }
        if (s == p) {
            memo[s][p] = 1;
        } else if (p == "*") {
            memo[s][p] = 1;
        } else if (s.empty() || p.empty()) {
            memo[s][p] = 0;
        } else if (s[0] != p[0] && p[0] != '*' && p[0] != '?') {
            memo[s][p] = 0;
        } else {
            char endS = s.back();
            char endP = p.back();
            string originalS = s;
            string originalP = p;
            s.pop_back();
            p.pop_back();
            if (endS == endP) {
                while (!s.empty() && !p.empty() && s.back() == p.back()) {
                    s.pop_back();
                    p.pop_back();
                }
                memo[originalS][originalP] = isMatch(s, p) ? 1 : 0;
            } else if (endP == '*') {
                memo[originalS][originalP] = isMatch(s, originalP) || isMatch(s, p) || isMatch(originalS, p) ? 1 : 0;
            } else if (endP == '?') {
                memo[originalS][originalP] = isMatch(s, p) ? 1 : 0;
            } else {
                memo[originalS][originalP] = 0;
            }
            return memo[originalS][originalP] == 1;
        }
        return memo[s][p] == 1;
    }
};