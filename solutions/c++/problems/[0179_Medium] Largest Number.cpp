class Solution {
public:
    string largestNumber(vector<int> &nums) {
        vector <string> numbers;
        for (int num: nums) numbers.push_back(to_string(num));
        sort(numbers.begin(), numbers.end(), [](string s1, string s2) {
            return s1 + s2 > s2 + s1;
        });
        string ans = "";
        for (auto s: numbers) ans += s;
        int leadingZeros = 0;
        for (auto c: ans) {
            if (c == '0') {
                leadingZeros++;
            } else {
                break;
            }
        }
        ans.erase(0, leadingZeros);
        return ans.size() > 0 ? ans : "0";
    }
};