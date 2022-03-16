class Solution {
public:
    void handleTemp(string &temp, vector <string> &paths) {
        if (temp == "." || temp.empty()) {
            // do nothing
        } else if (temp == "..") {
            if (!paths.empty()) paths.pop_back();
        } else {
            paths.push_back(temp);
        }
        temp = "";
    }

    string simplifyPath(string path) {
        int n = path.size();
        vector <string> paths;
        string temp = "";
        for (int i = 0; i < n; i++) {
            char curr = path[i];
            if (curr == '/') {
                handleTemp(temp, paths);
            } else {
                temp += curr;
            }
        }
        handleTemp(temp, paths);
        string ans = "";
        for (auto p: paths) {
            ans += "/" + p;
        }
        if (ans.empty()) ans += '/';
        return ans;
    }
};