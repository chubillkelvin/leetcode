class Solution {
public:
    vector<int> getVersion(string ver) {
        vector<int> v;
        string temp = "";
        for (char c: ver) {
            if (temp.empty() && c == '0') continue;
            if (c == '.') {
                if (temp.empty()) temp = "0";
                v.push_back(stoi(temp));
                temp = "";
            } else {
                temp += c;
            }
        }
        v.push_back(temp.empty() ? 0 : stoi(temp));
        return v;
    }

    int compareVersion(string version1, string version2) {
        auto v1 = getVersion(version1);
        auto v2 = getVersion(version2);
        while (v1.size() != v2.size()) {
            if (v1.size() < v2.size()) {
                v1.push_back(0);
            } else {
                v2.push_back(0);
            }
        }
        int n = v1.size();
        for (int i = 0; i < n; i++) {
            if (v1[i] < v2[i]) return -1;
            if (v1[i] > v2[i]) return 1;
        }
        return 0;
    }
};