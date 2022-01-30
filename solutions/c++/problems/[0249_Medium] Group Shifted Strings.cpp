class Solution {
public:
    string hash(string word) {
        int n = word.size();
        int diff = word[0] - 'a';
        string result = "";
        for (int i = 0; i < n; i++) {
            char c = 'a' + (word[i] - diff + 26) % 26;
            result += c;
        }
        return result;
    }

    vector <vector<string>> groupStrings(vector <string> &strings) {
        int n = strings.size();
        unordered_map <string, vector<string>> hashed;
        for (int i = 0; i < n; i++) {
            string curr = strings[i];
            hashed[hash(curr)].push_back(curr);
        }
        vector <vector<string>> groups;
        for (auto group: hashed) groups.push_back(group.second);
        return groups;
    }
};