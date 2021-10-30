#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<char>> cart_product(const vector<vector<char>> &v) {
        vector<vector<char>> s = {{}};
        for (auto &u: v) {
            vector<vector<char>> r;
            for (auto &x: s) {
                for (auto y: u) {
                    r.push_back(x);
                    r.back().push_back(y);
                }
            }
            s.swap(r);
        }
        return s;
    }

    vector<char> getLetter(char num) {
        switch (num) {
            case '2':
                return {'a', 'b', 'c'};
            case '3':
                return {'d', 'e', 'f'};
            case '4':
                return {'g', 'h', 'i'};
            case '5':
                return {'j', 'k', 'l'};
            case '6':
                return {'m', 'n', 'o'};
            case '7':
                return {'p', 'q', 'r', 's'};
            case '8':
                return {'t', 'u', 'v'};
            case '9':
                return {'w', 'x', 'y', 'z'};
            default:
                return {};
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};

        vector<char> digitVector = vector<char>(digits.begin(), digits.end());
        vector<vector<char>> lettersVector = {};
        for (auto digit: digitVector) {
            lettersVector.push_back(getLetter(digit));
        }
        vector<vector<char>> product = cart_product(lettersVector);
        vector<string> ans = {};
        for (auto res: product) {
            ans.push_back(string(res.begin(), res.end()));
        }
        return ans;
    }
};