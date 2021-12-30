class Solution {
public:
    int bagOfTokensScore(vector<int> &tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int score = 0;
        for (int i = 0; i < n; i++) {
            int curr = tokens[i];
            if (power >= curr) {
                power -= curr;
                score++;
            } else {
                if (score >= 1 && n - 1 > i && tokens[n - 1] >= curr) {
                    power += tokens[n - 1] - curr;
                    n--;
                } else {
                    break;
                }
            }
        }
        return score;
    }
};