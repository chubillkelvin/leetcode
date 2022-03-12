class Solution {
public:
    bool isValid(string s) {
        return to_string(stoll(s)) == s;
    }

    vector <string> findStrobogrammatic(int n) {
        if (n == 1) return {"0", "1", "8"};
        if (n == 2) return {"11", "69", "88", "96"};
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
        return ans;
    }
};