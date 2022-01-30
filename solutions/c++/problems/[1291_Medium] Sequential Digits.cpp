class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int minN = log10(low) + 1;
        int maxN = log10(high) + 1;
        string test = "123456789";
        vector<int> ans;
        for (int i = minN; i <= maxN; i++) {
            for (int j = 0; j <= 9 - i; j++) {
                int num = stoi(test.substr(j, i));
                if (num >= low) {
                    if (num <= high) {
                        ans.push_back(num);
                    } else {
                        break;
                    }
                }
            }
        }
        return ans;
    }
};