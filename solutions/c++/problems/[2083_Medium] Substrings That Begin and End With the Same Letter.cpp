class Solution {
public:
    long long numberOfSubstrings(string s) {
        long long sum = 0;
        vector<long long> count(26, 0);
        for (char c: s) sum += ++count[c - 'a'];
        return sum;
    }
};